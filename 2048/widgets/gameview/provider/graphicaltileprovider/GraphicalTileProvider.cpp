#include "GraphicalTileProvider.hh"

void GraphicalTileProvider::moveItemIntoBoundary(QGraphicsItem *item, const QRectF &boundary) {
    double itemX = boundary.x() + (boundary.width() - item->boundingRect().width()) / 2;
    double itemY = boundary.y() + (boundary.height() - item->boundingRect().height()) / 2;
    item->moveBy(itemX, itemY);
}
