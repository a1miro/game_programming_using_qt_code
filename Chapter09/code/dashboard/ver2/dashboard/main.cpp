#include <QtWidgets>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QtQml>
#include "ui_form.h"
#include "carinfo.h"


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    CarInfo cinfo;
    QQuickView view;
    view.engine()->rootContext()->setContextProperty("carData", &cinfo);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    cinfo.show();
    return app.exec();
}
