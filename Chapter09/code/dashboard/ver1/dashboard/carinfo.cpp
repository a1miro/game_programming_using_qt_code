#include "carinfo.h"
#include "ui_form.h"

CarInfo::CarInfo() : QWidget(0), ui(new Ui::Form) {
    ui->setupUi(this);
    connect(ui->gearBox, SIGNAL(valueChanged(int)), this, SIGNAL(gearChanged(int)));
    connect(ui->speedBox, SIGNAL(valueChanged(int)), this, SIGNAL(speedChanged(int)));
    connect(ui->rpmBox, SIGNAL(valueChanged(int)), this, SIGNAL(rpmChanged(int)));
    connect(ui->distanceBox, SIGNAL(valueChanged(double)), this, SIGNAL(distanceChanged(double)));

    connect(ui->distanceSlider, &QSlider::valueChanged, ui->distanceBox, &QDoubleSpinBox::setValue);
    connect(this, &CarInfo::distanceChanged, ui->distanceSlider, &QSlider::setValue);
}

int CarInfo::speed() const { return ui->speedBox->value(); }
void CarInfo::setSpeed(int s) { ui->speedBox->setValue(s); }
int CarInfo::gear() const { return ui->gearBox->value(); }
void CarInfo::setGear(int g) { ui->gearBox->setValue(g); }
int CarInfo::rpm() const { return ui->rpmBox->value(); }
void CarInfo::setRpm(int rpm) { ui->rpmBox->setValue(rpm); }
double CarInfo::distance() const { return ui->distanceBox->value(); }
void CarInfo::setDistance(double d) { ui->distanceBox->setValue(d); }
