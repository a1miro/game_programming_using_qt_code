#include "qtpython.h"

int main(int argc, char *argv[])
{
    QtPython python(argv[0]);
    python.run("print('Hello from Python')");
    return 0;
}
