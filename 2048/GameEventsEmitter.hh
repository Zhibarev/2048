#ifndef GAMEEVENTS_H
#define GAMEEVENTS_H

#include <QObject>

class Model;

class GameEventsEmitter : public QObject
{
    Q_OBJECT

signals:
    void gameStarted(const Model &model);
    void gamePaused();
    void gameUnpaused();
    void gameReseted();
    void gameEnded(const Model &model);
    void modelCreatedNewValue(const Model &model);
    void modelMoved(const Model &model);
    void viewAnimationStarted();
    void viewAnimationEnded();

public:
    static GameEventsEmitter &instance();

    GameEventsEmitter(const GameEventsEmitter &) = delete;
    GameEventsEmitter &operator=(const GameEventsEmitter &) = delete;

private:
    GameEventsEmitter() = default;
};

#endif // GAMEEVENTS_H
