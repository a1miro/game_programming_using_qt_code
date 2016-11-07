#ifndef SIMPLEGLWINDOW_H
#define SIMPLEGLWINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

class SimpleGLWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
public:
    SimpleGLWindow(QWindow *parent = 0);
protected:
    void initializeGL();
    void paintGL();
};

#endif // SIMPLEGLWINDOW_H
