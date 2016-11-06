#include <QQuickView>
#include <QGuiApplication>
#include <QtQml>
#include <outlinetextitem.h>


int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);
    QQuickView view;
    qmlRegisterUncreatableType<OutlineTextItemBorder>("OutlineTextItem", 1, 0, "OutlineTextItemBorder", "");
    qmlRegisterType<OutlineTextItem>("OutlineTextItem", 1, 0, "OutlineTextItem");

    view.setSource(QUrl("qrc:/main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();
    return app.exec();
}
