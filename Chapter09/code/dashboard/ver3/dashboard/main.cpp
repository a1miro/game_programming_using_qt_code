#include <QtWidgets>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QtQml>
#include "ui_form.h"
#include "carinfo.h"


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QQuickView view;
    QString msg = QStringLiteral("Objects of type CarInfoEngine cannot be created");
    qmlRegisterUncreatableType<CarInfoEngine>("CarInfo", 1, 0, "CarInfoEngine", msg);
    qmlRegisterType<CarInfoProxy>("CarInfo", 1, 0, "CarInfo");
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    return app.exec();
}
