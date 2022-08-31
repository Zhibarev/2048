#ifndef FIELDRENDERER_H
#define FIELDRENDERER_H

#include "model/GameBoard.hh"
#include "provider/TileColorProvider.hh"
#include "provider/graphicaltileprovider/GraphicalTileProvider.hh"

#include <QGraphicsScene>
#include <memory>


class FieldRenderer
{
public:

    explicit FieldRenderer(QGraphicsScene *scene);

    void createField(const std::shared_ptr<GameBoard> &gameBoard, bool isGraphicsModeActive);

    void update();

private:
    const double TILE_MARGIN = 6;
    const QColor BACKGROUND_COLOR{187, 173, 160};

    QGraphicsScene *scene = nullptr;

    std::shared_ptr<GameBoard> gameBoard;

    std::vector<std::vector<QGraphicsRectItem *>> tileBackgroundRects;
    std::vector<QGraphicsItem *> tiles;

    TileColorProvider tileColorProvider;
    std::unique_ptr<GraphicalTileProvider> graphicalTileProvider;


    void clearTiles();

    void updateTile(size_t i, size_t j, unsigned value);

    void drawGrid();
};

#endif // FIELDRENDERER_H
