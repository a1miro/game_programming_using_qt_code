#ifndef QTPYTHON_H
#define QTPYTHON_H

#include <QObject>
#include <QString>

class QtPython : public QObject {
  Q_OBJECT
public:
  QtPython(const char *progName, QObject *parent = 0);
  ~QtPython();
  void run(const QString &program);
};
#endif // QTPYTHON_H
