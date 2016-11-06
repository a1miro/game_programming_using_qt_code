#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void addPoint(unsigned yVal) { m_points << qMax(0u, yVal); update(); }
    void clear() { m_points.clear(); update(); }

protected:
    void paintEvent(QPaintEvent *);
    void drawChart(QPainter *painter, const QRect &rect);
    QList<quint16> m_points;
};

#endif // WIDGET_H
