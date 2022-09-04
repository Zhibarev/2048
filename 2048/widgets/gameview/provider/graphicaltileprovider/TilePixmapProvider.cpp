#include "TilePixmapProvider.hh"
#include <QString>

TilePixmapProvider::TilePixmapProvider()
{
    for (unsigned value = 2; value <= MAX_VALUE; value *= 2) {
        QString pixmapPath = QString("resources/") + QString::number(value) + ".png";
        auto it = storage.emplace(value, pixmapPath);
        if (it.first->second.isNull())
            qFatal("Failed to load tile image: \"%s\"", qPrintable(pixmapPath));
    }
}

const QPixmap &TilePixmapProvider::getPixmap(unsigned value) const
{
    auto it = storage.find(value);

    if (it == storage.end())
        qFatal("Pixmap is not stored in the provider");

    return it->second;
}

unsigned TilePixmapProvider::getMaxValue() const
{
    return MAX_VALUE;
}
