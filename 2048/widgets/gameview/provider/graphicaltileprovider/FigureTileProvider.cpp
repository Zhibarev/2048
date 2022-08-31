#include "FigureTileProvider.hh"

QGraphicsItem *FigureTileProvider::getTileItem(unsigned tileValue, const QRectF &boundary) const
{
    unsigned pixmapRepeatCounter = countPixmapRepeat(tileValue);
    QPixmap pixmap = createPixmap(tileValue, pixmapRepeatCounter, boundary);
    QGraphicsItem *item = createFigureTile(pixmap, pixmapRepeatCounter);
    moveItemIntoBoundary(item, boundary);
    return item;
}

QPixmap FigureTileProvider::createPixmap(int tileValue, int pixmapRepeatCounter, const QRectF &boundary) const
{
    double tileWidth = boundary.width();
    double tileHeight = boundary.height();
    double figureWidth = tileWidth * AVAILABLE_BOUNDARY_PART / pixmapRepeatCounter;
    double figureHeight = tileHeight * AVAILABLE_BOUNDARY_PART / pixmapRepeatCounter;
    const QPixmap &pixmap = pixmapProvider.getPixmap(tileValue);
    return pixmap.scaled(figureWidth, figureHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

unsigned FigureTileProvider::countPixmapRepeat(unsigned &tileValue) const
{
    unsigned maxFigureValue = pixmapProvider.getMaxValue();
    unsigned figureRepeatCounter = 1;
    while (tileValue > maxFigureValue) {
        tileValue /= maxFigureValue;
        figureRepeatCounter++;
    }
    return figureRepeatCounter;
}

QGraphicsItem *FigureTileProvider::createFigureTile(const QPixmap &pixmap, unsigned figureRepeatCounter) const {
    QGraphicsItemGroup *itemGroup = new QGraphicsItemGroup();
    double figureX = 0;
    double figureY = 0;
    for (unsigned i = 0; i < figureRepeatCounter; i++) {
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
        item->moveBy(figureX, figureY);
        figureX += pixmap.width();
        itemGroup->addToGroup(item);
    }
    return itemGroup;
}
