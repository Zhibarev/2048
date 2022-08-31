#ifndef NUMBERFIGURES_H
#define NUMBERFIGURES_H

#include <QPixmap>
#include <unordered_map>


class TilePixmapProvider
{
public:
    TilePixmapProvider();

    const QPixmap &getPixmap(unsigned value) const;

    unsigned getMaxValue() const;

private:
    const unsigned MAX_VALUE = 512;

    std::unordered_map<unsigned, QPixmap> storage;
};

#endif // NUMBERFIGURES_H
