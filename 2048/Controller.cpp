#include "Controller.hh"
#include "GameEventsEmitter.hh"
#include "model/Direction.hh"

Controller::Controller()
    : isRunning(false),
      isAnimationPlaying(false)
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

    QObject::connect(&GameEventsEmitter::instance(), &GameEventsEmitter::viewAnimationStarted,
                     [this]() { isAnimationPlaying = true; });
    QObject::connect(&GameEventsEmitter::instance(), &GameEventsEmitter::viewAnimationEnded,
                     [this]() { isAnimationPlaying = false; });
}

void Controller::startGame(const std::unique_ptr<Settings> &settings)
{
    model.startGame(settings);
}

void Controller::move(QKeyEvent *event)
{
    if (isRunning && !isAnimationPlaying) {
        Direction direction;
        switch (event->key()) {
            case Qt::Key_A:
                direction = Direction::LEFT;
                break;
            case Qt::Key_D:
                direction = Direction::RIGHT;
                break;
            case Qt::Key_W:
                direction = Direction::UP;
                break;
            case Qt::Key_S:
                direction = Direction::DOWN;
                break;
            default:
                return;
        }

        model.move(direction);
        if (isRunning)
            model.createNewValue();
    }
}
