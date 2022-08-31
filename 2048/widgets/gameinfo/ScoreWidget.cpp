#include "ScoreWidget.hh"
#include "GameEventsEmitter.hh"


ScoreWidget::ScoreWidget(QWidget *parent)
    : NamedNumberWidget(QObject::tr("Score: "), parent)
{
    connect(&GameEventsEmitter::instance(), &GameEventsEmitter::scoreChanged,
            [this](unsigned score) { setNumber(score); });
}
