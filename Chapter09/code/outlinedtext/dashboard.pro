TEMPLATE = app
TARGET = outlinedtext
INCLUDEPATH += .

SOURCES += main.cpp outlinetextitem.cpp

QT += quick

HEADERS += outlinetextitem.h

DISTFILES += main.qml

RESOURCES += \
    resources.qrc
