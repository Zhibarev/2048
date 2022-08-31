#ifndef GRAPHICALTILEPROVIDER_H
#define GRAPHICALTILEPROVIDER_H

#include <QGraphicsItem>


class GraphicalTileProvider {
public:
    virtual ~GraphicalTileProvider() = default;

    virtual QGraphicsItem *getTileItem(unsigned tileValue, const QRectF &boundary) const = 0;

protected:
    static void moveItemIntoBoundary(QGraphicsItem *item, const QRectF &boundary);
};

#endif // GRAPHICALTILEPROVIDER_H
