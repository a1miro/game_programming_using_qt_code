#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QtQml>
#include <QGuiApplication>
#include "regularpolygon.h"

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);
    QQuickView view;
    QSurfaceFormat format = view.format();
    format.setSamples(16);
    view.setFormat(format);
    qmlRegisterType<RegularPolygon>("RegularPolygon", 1, 0, "RegularPolygon");
    view.setSource(QUrl("qrc:/main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();
    return app.exec();
}
