#ifndef FIGURETILEPROVIDER_H
#define FIGURETILEPROVIDER_H

#include "TilePixmapProvider.hh"
#include "GraphicalTileProvider.hh"


class FigureTileProvider : public GraphicalTileProvider
{
public:
    QGraphicsItem *getTileItem(unsigned tileValue, const QRectF &boundary) const;

private:
    const double AVAILABLE_BOUNDARY_PART = 0.7;

    TilePixmapProvider pixmapProvider;


    QPixmap createPixmap(int tileValue, int pixmapRepeatCounter, const QRectF &boundary) const;

    unsigned countPixmapRepeat(unsigned &tileValue) const;

    QGraphicsItem *createFigureTile(const QPixmap &pixmap, unsigned figureRepeatCounter) const;
};

#endif // FIGURETILEPROVIDER_H
