#ifndef OUTILINETEXTITEM_H
#define OUTILINETEXTITEM_H

#include <QQuickPaintedItem>
#include <QPainterPath>

class OutlineTextItemBorder : public QObject {
    Q_OBJECT
    Q_PROPERTY(int width MEMBER m_width NOTIFY widthChanged)
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged)
    Q_PROPERTY(int style MEMBER m_style NOTIFY styleChanged)
public:
    OutlineTextItemBorder(QObject *parent = 0);

    int width() const { return m_width; }
    QColor color() const { return m_color; }
    Qt::PenStyle style() const { return (Qt::PenStyle)m_style; }
    QPen pen() const;
signals:
    void widthChanged(int);
    void colorChanged(QColor);
    void styleChanged(int);
private:
    int m_width;
    QColor m_color;
    int m_style;
};


class OutlineTextItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER m_text NOTIFY textChanged)
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged)
    Q_PROPERTY(OutlineTextItemBorder* border READ border NOTIFY borderChanged)
    Q_PROPERTY(QString fontFamily MEMBER m_ffamily NOTIFY fontFamilyChanged)
    Q_PROPERTY(int fontPixelSize MEMBER m_fsize NOTIFY fontPixelSizeChanged)
public:
    OutlineTextItem(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    OutlineTextItemBorder* border() const { return m_border; }
    QPainterPath shape(const QPainterPath &path) const;
private slots:
    void updateItem();
signals:
    void textChanged(QString);
    void colorChanged(QColor);
    void borderChanged();
    void fontFamilyChanged(QString);
    void fontPixelSizeChanged(int);
private:
    OutlineTextItemBorder* m_border;
    QPainterPath m_path;
    QRectF m_br;
    QString m_text;
    QColor m_color;
    QString m_ffamily;
    int m_fsize;
};

#endif // OUTILINETEXTITEM_H
