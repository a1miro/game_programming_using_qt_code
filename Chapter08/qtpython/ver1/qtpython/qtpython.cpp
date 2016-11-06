#include <Python.h>
#include "qtpython.h"

QtPython::QtPython(const char *progName, QObject *parent) : QObject(parent) {
    if(progName != 0) {
        wchar_t buf[strlen(progName+1)];
        mbstowcs(buf, progName, strlen(progName));
        Py_SetProgramName(buf);
    }
    Py_InitializeEx(0);
}

QtPython::~QtPython() { Py_Finalize(); }

void QtPython::run(const QString &program) {
    PyRun_SimpleString(qPrintable(program));
}
