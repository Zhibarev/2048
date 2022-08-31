#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QKeyEvent>
#include "widgets/gameview/model/NumberTile.hh"
#include "widgets/gameview/GameView.hh"


class Controller : public QObject
{
public:
    explicit Controller(GameView *gameView);

    void move(QKeyEvent *action) const;

private:
    const Coords LEFT = {0, -1};
    const Coords UP = {-1, 0};
    const Coords RIGHT = {0, 1};
    const Coords DOWN = {1, 0};

    GameView *gameView;
    bool isRunning;
};

#endif // CONTROLLER_H
