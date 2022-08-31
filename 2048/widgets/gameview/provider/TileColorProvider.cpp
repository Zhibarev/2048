#include "TileColorProvider.hh"
#include <stdexcept>

TileColorProvider::TileColorProvider() {
    addTileColor(200, 195, 180);
    addTileColor(240, 227, 220);
    addTileColor(236, 224, 200);
    addTileColor(239, 176, 124);
    addTileColor(243, 150, 106);
    addTileColor(243, 125, 99);
    addTileColor(244, 96, 66);
    addTileColor(234, 207, 118);
    addTileColor(237, 203, 103);
    addTileColor(236, 200, 90);
    addTileColor(231, 194, 87);
    addTileColor(232, 190, 78);
    addTileColor(250, 115, 110);
    addTileColor(250, 90, 90);
    addTileColor(240, 80, 55);
    addTileColor(110, 175, 220);
    addTileColor(90, 155, 230);
}

const QColor &TileColorProvider::getColor(unsigned value)
{
    auto it = storage.find(value);
    if (it != storage.end())
        return it->second;
    return storage.at(maxValue);
}

void TileColorProvider::addTileColor(int red, int blue, int green)
{
    if (storage.empty()) {
        storage[0] = QColor(red, blue, green);
        maxValue = 1;
    }
    else {
        maxValue *= 2;
        storage[maxValue] = QColor(red, blue, green);
    }
}
