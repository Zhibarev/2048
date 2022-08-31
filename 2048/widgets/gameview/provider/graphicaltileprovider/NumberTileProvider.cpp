#include "NumberTileProvider.hh"
#include <QFont>

QGraphicsItem *NumberTileProvider::getTileItem(unsigned tileValue, const QRectF &boundary) const {
    QString displayedText = QString::number(tileValue);
    QGraphicsTextItem *item = new QGraphicsTextItem(displayedText);

    QFont font = createFont(boundary);
    item->setFont(font);

    moveItemIntoBoundary(item, boundary);

    return item;
}

QFont NumberTileProvider::createFont(const QRectF &boundary) const {
    int fontSize = boundary.height() * FONT_MULTIPLIER;
    QFont font;
    font.setPixelSize(fontSize);
    font.setBold(true);
    return font;
}
