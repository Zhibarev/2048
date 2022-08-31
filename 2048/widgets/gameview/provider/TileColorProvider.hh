#ifndef TILEBACKGROUND_H
#define TILEBACKGROUND_H

#include <QColor>
#include <unordered_map>


class TileColorProvider
{
public:
    TileColorProvider();

    const QColor &getColor(unsigned value);

private:
    std::unordered_map<unsigned, QColor> storage;

    unsigned maxValue = 0;


    void addTileColor(int red, int blue, int green);
};

#endif // TILEBACKGROUND_H
