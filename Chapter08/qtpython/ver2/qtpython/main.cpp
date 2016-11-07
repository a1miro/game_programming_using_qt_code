#include "qtpython.h"
#include "qtpythonvalue.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    QtPython python(argv[0]);
    QtPythonValue integer = 7, string = QStringLiteral("foobar"), none;
    qDebug() << integer.toInt() << string.toString() << none.isNone();
    return 0;
}
