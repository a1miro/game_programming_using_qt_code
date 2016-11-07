QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = tictactoe
TEMPLATE = app
SOURCES += main.cpp tictactoewidget.cpp \
    configurationdialog.cpp
HEADERS  += tictactoewidget.h \
    configurationdialog.h

FORMS += \
    configurationdialog.ui
