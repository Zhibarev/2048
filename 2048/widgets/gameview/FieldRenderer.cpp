#include "FieldRenderer.hh"
#include "provider/graphicaltileprovider/FigureTileProvider.hh"
#include "provider/graphicaltileprovider/NumberTileProvider.hh"
#include "model/Model.hh"
#include <QGraphicsRectItem>
#include <algorithm>

FieldRenderer::FieldRenderer(QGraphicsScene *scene) : scene(scene)
{
    scene->setBackgroundBrush(BACKGROUND_COLOR);
}

void FieldRenderer::createField(const Model &model, bool isGraphicsModeActive)
{
    if (isGraphicsModeActive)
        graphicalTileProvider = std::make_unique<FigureTileProvider>();
    else
        graphicalTileProvider = std::make_unique<NumberTileProvider>();

    drawGrid(model.getSize());
    updateField(model);
}

void FieldRenderer::updateField(const Model &model)
{
    std::function<unsigned (size_t, size_t)> getTileNumber =
            [&model](size_t i, size_t j) { return model.getTileNumber(i, j); };
    updateField(getTileNumber);
}

void FieldRenderer::updateField(const std::vector<std::vector<unsigned>> &gameBoard)
{
    std::function<unsigned (size_t, size_t)> getTileNumber =
            [&gameBoard](size_t i, size_t j) { return gameBoard[i][j]; };
    updateField(getTileNumber);
}

void FieldRenderer::updateTile(size_t i, size_t j, unsigned int value) {
    tileBackgroundRects[i][j]->setBrush(tileColorProvider.getColor(value));

    if (value != 0) {
        QGraphicsItem *item = graphicalTileProvider->getTileItem(value, tileBackgroundRects[i][j]->rect());
        scene->addItem(item);
        tiles.push_back(item);
    }
}

void FieldRenderer::drawGrid(size_t size)
{
    clearTiles();
    tileBackgroundRects.clear();
    scene->clear();

    auto sceneRect = scene->sceneRect();
    double sceneWidth = sceneRect.width();
    double sceneHeight = sceneRect.height();
    double sceneMinSide = qMin(sceneWidth, sceneHeight);
    double sceneMaxSide = qMax(sceneWidth, sceneHeight);

    double tileSide = (sceneMinSide - TILE_MARGIN * (size + 1)) / size;

    double initialX = TILE_MARGIN;
    double initialY = TILE_MARGIN + (sceneMaxSide - sceneMinSide) / 2;
    if (sceneWidth > sceneHeight)
        std::swap(initialX, initialY);

    tileBackgroundRects.resize(size);
    for (size_t i = 0; i < size; i++) {
        tileBackgroundRects[i].resize(size);
        for (size_t j = 0; j < size; j++) {
            double rectX = initialX + (TILE_MARGIN + tileSide) * i;
            double rectY = initialY + (TILE_MARGIN + tileSide) * j;
            tileBackgroundRects[i][j] = new QGraphicsRectItem(rectX, rectY, tileSide, tileSide);
            scene->addItem(tileBackgroundRects[i][j]);
        }
    }
}

void FieldRenderer::updateField(const std::function<unsigned (size_t, size_t)> &getTileNumber)
{
    clearTiles();

    size_t size = tileBackgroundRects.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            unsigned value = getTileNumber(i, j);
            updateTile(i, j, value);
        }
    }

    scene->update();
}

void FieldRenderer::clearTiles()
{
    for (QGraphicsItem *item: tiles)
        delete item;
    tiles.clear();
}
