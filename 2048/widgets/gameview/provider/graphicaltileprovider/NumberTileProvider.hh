#ifndef NUMBERTILEPROVIDER_H
#define NUMBERTILEPROVIDER_H

#include "GraphicalTileProvider.hh"


class NumberTileProvider : public GraphicalTileProvider
{
public:
    QGraphicsItem *getTileItem(unsigned tileValue, const QRectF &boundary) const;

private:
    const double FONT_MULTIPLIER = 0.3;


    QFont createFont(const QRectF &boundary) const;
};

#endif // NUMBERTILEPROVIDER_H
