#include "TimeWidget.hh"
#include "GameEventsEmitter.hh"


TimeWidget::TimeWidget(QWidget *parent)
    : NamedNumberWidget(QObject::tr("Time: "), parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));

    connect(&GameEventsEmitter::instance(), SIGNAL(gameStarted()),
            this, SLOT(onGameStarted()));
    connect(&GameEventsEmitter::instance(), SIGNAL(gameUnpaused()),
            this, SLOT(onGameUnpaused()));
    connect(&GameEventsEmitter::instance(), SIGNAL(gamePaused()),
            this, SLOT(stopTimer()));
    connect(&GameEventsEmitter::instance(), SIGNAL(gameReseted()),
            this, SLOT(stopTimer()));
    connect(&GameEventsEmitter::instance(), SIGNAL(gameEnded(bool)),
            this, SLOT(stopTimer()));
}

void TimeWidget::setTime(int time)
{
    const int MILLISECONDS_TO_SECONDS = 1000;
    int timeInSeconds = time / MILLISECONDS_TO_SECONDS;
    setNumber(timeInSeconds);
}

void TimeWidget::updateTime()
{
    timePassed += timer.interval();
    setTime(timePassed);
}

void TimeWidget::stopTimer()
{
    timePassed += timer.interval() - timer.remainingTime();
    setTime(timePassed);
    timer.stop();
}

void TimeWidget::onGameStarted()
{
    timePassed = 0;
    setTime(timePassed);
    timer.start(UPDATE_INTERVAL);
}

void TimeWidget::onGameUnpaused()
{
    timer.start(UPDATE_INTERVAL);
}
