TEMPLATE = app
TARGET = jsonparser
DEPENDPATH += .
INCLUDEPATH += .

HEADERS += playerinfo.h \
    playerinfojson.h

SOURCES += \
    playerinfojson.cpp \
    main.cpp

CONFIG += c++11
