#ifndef CARINFO_H
#define CARINFO_H

#include <QWidget>
#include <QDate>

namespace Ui {
class Form;
}

class CarInfo : public QWidget {
    Q_OBJECT
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int gear READ gear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(int rpm READ rpm WRITE setRpm NOTIFY rpmChanged)
    Q_PROPERTY(double distance READ distance NOTIFY distanceChanged)
public:
    CarInfo();
    int speed() const;
    void setSpeed(int s);
    int gear() const;
    void setGear(int g);
    int rpm() const;
    void setRpm(int rpm);
    double distance() const;
    void setDistance(double d);

signals:
    void speedChanged(int);
    void gearChanged(int);
    void rpmChanged(int);
    void distanceChanged(double);
private:
    Ui::Form *ui;
};


#endif // CARINFO_H
