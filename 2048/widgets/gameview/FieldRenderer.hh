#ifndef FIELDRENDERER_H
#define FIELDRENDERER_H

#include <QGraphicsScene>
#include <memory>
#include "provider/TileColorProvider.hh"
#include "provider/graphicaltileprovider/GraphicalTileProvider.hh"
#include <vector>
#include <functional>

class Model;


class FieldRenderer
{
public:

    explicit FieldRenderer(QGraphicsScene *scene);

    void createField(const Model &model, bool isGraphicsModeActive);

    void updateField(const Model &model);
    void updateField(const std::vector<std::vector<unsigned>> &gameBoard);

private:
    const double TILE_MARGIN = 6;
    const QColor BACKGROUND_COLOR{187, 173, 160};

    QGraphicsScene *scene = nullptr;

    std::vector<std::vector<QGraphicsRectItem *>> tileBackgroundRects;
    std::vector<QGraphicsItem *> tiles;

    TileColorProvider tileColorProvider;
    std::unique_ptr<GraphicalTileProvider> graphicalTileProvider;


    void clearTiles();

    void updateTile(size_t i, size_t j, unsigned value);

    void drawGrid(size_t size);

    void updateField(const std::function<unsigned(size_t, size_t)> &getTileNumber);
};

#endif // FIELDRENDERER_H
