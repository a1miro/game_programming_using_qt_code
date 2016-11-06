TEMPLATE = app
TARGET = dashboard
INCLUDEPATH += .

# Input
#FORMS += form.ui
SOURCES += main.cpp \
    carinfo.cpp

QT += quick widgets

FORMS += form.ui

DISTFILES += \
    main.qml Needle.qml \
    Label.qml

HEADERS += \
    carinfo.h

RESOURCES += \
    resources.qrc
