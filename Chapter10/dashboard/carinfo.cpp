#include "carinfo.h"
#include "ui_form.h"

CarInfo::CarInfo() : QWidget(0), ui(new Ui::Form) {
    ui->setupUi(this);
    m_engine = new CarInfoEngine(this);
    m_engine->setGear(ui->gearBox->value());
    m_engine->setRpm(ui->rpmBox->value());
    connect(ui->speedBox, SIGNAL(valueChanged(int)), this, SIGNAL(speedChanged(int)));
    connect(ui->distanceBox, SIGNAL(valueChanged(double)), this, SIGNAL(distanceChanged(double)));

    connect(ui->distanceSlider, &QSlider::valueChanged, ui->distanceBox, &QDoubleSpinBox::setValue);
    connect(this, &CarInfo::distanceChanged, ui->distanceSlider, &QSlider::setValue);

    connect(ui->gearBox, SIGNAL(valueChanged(int)), m_engine, SLOT(setGear(int)));
    connect(ui->rpmBox, SIGNAL(valueChanged(int)), m_engine, SLOT(setRpm(int)));
    connect(m_engine, SIGNAL(gearChanged(int)), ui->gearBox, SLOT(setValue(int)));
    connect(m_engine, SIGNAL(rpmChanged(int)), ui->rpmBox, SLOT(setValue(int)));
}

int CarInfo::speed() const { return ui->speedBox->value(); }
void CarInfo::setSpeed(int s) { ui->speedBox->setValue(s); }
double CarInfo::distance() const { return ui->distanceBox->value(); }
void CarInfo::setDistance(double d) { ui->distanceBox->setValue(d); }

CarInfoProxy::CarInfoProxy(QObject *parent) : QObject(parent) {
    connect(&m_car, SIGNAL(engineChanged()), this, SIGNAL(engineChanged()));
    connect(&m_car, SIGNAL(speedChanged(int)), this, SIGNAL(speedChanged(int)));
    connect(&m_car, SIGNAL(distanceChanged(double)), this, SIGNAL(distanceChanged(double)));
}

CarInfoEngine *CarInfoProxy::engine() const { return m_car.engine(); }

bool CarInfoProxy::visible() const { return m_car.isVisible(); }

void CarInfoProxy::setVisible(bool v) {
    if(v == visible()) return;
    m_car.setVisible(v);
    emit visibleChanged(v);
}

int CarInfoProxy::speed() const { return m_car.speed(); }

void CarInfoProxy::setSpeed(int v) { m_car.setSpeed(v); }

double CarInfoProxy::distance() const { return m_car.distance(); }

void CarInfoProxy::setDistance(double d) { m_car.setDistance(d); }
