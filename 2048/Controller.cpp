#include "Controller.hh"
#include "GameEventsEmitter.hh"

Controller::Controller(GameView *gameView)
      : gameView(gameView),
        isRunning(false)
{
    QObject::connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameStarted,
                     [this]() { isRunning = true; });
    QObject::connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gamePaused,
                     [this]() { isRunning = false; });
    QObject::connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameUnpaused,
                     [this]() { isRunning = true; });
    QObject::connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameReseted,
                     [this]() { isRunning = false; });
    QObject::connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameEnded,
                     [this]() { isRunning = false; });
}

void Controller::move(QKeyEvent *event) const
{
    if (isRunning) {
        Coords direction;
        switch (event->key()) {
            case Qt::Key_A:
                direction = LEFT;
                break;
            case Qt::Key_D:
                direction = RIGHT;
                break;
            case Qt::Key_W:
                direction = UP;
                break;
            case Qt::Key_S:
                direction = DOWN;
                break;
            default:
                return;
        }
        gameView->move(direction);
    }
}
