QT       = core gui script
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = codeeditor
TEMPLATE = app

SOURCES += main.cpp mainwindow.cpp
HEADERS  += mainwindow.h
FORMS    += mainwindow.ui
