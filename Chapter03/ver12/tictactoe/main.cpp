#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPalette pall;
    QPixmap pix(":/redstar.png");
    QCursor cur(pix);
    pall.setColor(w.backgroundRole(), Qt::blue);
    w.setPalette(pall);
    w.setAutoFillBackground(true);

    w.setCursor(Qt::PointingHandCursor);
    w.show();
    return a.exec();
}
