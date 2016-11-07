TEMPLATE = app
TARGET = xmlreader
DEPENDPATH += .
INCLUDEPATH += .
QT = core

# Input
HEADERS += \
    playerinforeader.h \
    playerinfo.h

DISTFILES += \
    playerinfo.xml

SOURCES += \
    playerinforeader.cpp \
    main.cpp
