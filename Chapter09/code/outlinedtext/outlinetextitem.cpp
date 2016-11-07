#include "outlinetextitem.h"
#include <QPainter>

OutlineTextItem::OutlineTextItem(QQuickItem *parent) : QQuickPaintedItem(parent) {
    m_border = new OutlineTextItemBorder(this);
    connect(this, SIGNAL(textChanged(QString)), this, SLOT(updateItem()));
    connect(this, SIGNAL(colorChanged(QColor)), this, SLOT(updateItem()));
    connect(this, SIGNAL(fontFamilyChanged(QString)), this, SLOT(updateItem()));
    connect(this, SIGNAL(fontPixelSizeChanged(int)), this, SLOT(updateItem()));
    connect(m_border, SIGNAL(widthChanged(int)), this, SLOT(updateItem()));
    connect(m_border, SIGNAL(colorChanged(QColor)), this, SLOT(updateItem()));
    connect(m_border, SIGNAL(styleChanged(int)), this, SLOT(updateItem()));
    updateItem();
}

void OutlineTextItem::paint(QPainter *painter) {
    if(m_text.isEmpty()) return;
    painter->setPen(m_border->pen());
    painter->setBrush(m_color);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->translate(-m_br.topLeft());
    painter->drawPath(m_path);
}

QPainterPath OutlineTextItem::shape(const QPainterPath &path) const
{
    QPainterPathStroker ps;
    if(m_border->width() > 0 && m_border->style() != Qt::NoPen) {
        ps.setWidth(m_border->width());
    } else {
        ps.setWidth(0.0000001);
    }
    QPainterPath p = ps.createStroke(path);
    p.addPath(path);
    return p;
}

void OutlineTextItem::updateItem() {
    QFont font(m_ffamily, m_fsize);
    m_path = QPainterPath();
    QFontMetrics fm(font);
    m_path.addText(0, /*fm.ascent()*/0 , font, m_text);
    m_br = shape(m_path).controlPointRect();
    setImplicitWidth(m_br.width());
    setImplicitHeight(m_br.height());
    update();
}


OutlineTextItemBorder::OutlineTextItemBorder(QObject *parent) : QObject(parent),
    m_width(0), m_color(Qt::transparent), m_style(Qt::SolidLine) {}

QPen OutlineTextItemBorder::pen() const {
    QPen p;
    p.setColor(m_color);
    p.setWidth(m_width);
    p.setStyle((Qt::PenStyle)m_style);
    return p;
}
