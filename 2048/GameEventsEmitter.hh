#ifndef GAMEEVENTS_H
#define GAMEEVENTS_H

#include <QObject>

class GameEventsEmitter : public QObject
{
    Q_OBJECT

signals:
    void gameStarted();
    void gamePaused();
    void gameUnpaused();
    void gameReseted();
    void gameEnded(bool isWin);
    void playerWon(unsigned finalScore);
    void scoreChanged(unsigned newScore);

public:
    static GameEventsEmitter &instance();

    GameEventsEmitter(const GameEventsEmitter &) = delete;
    GameEventsEmitter &operator=(const GameEventsEmitter &) = delete;

private:
    GameEventsEmitter() = default;
};

#endif // GAMEEVENTS_H
