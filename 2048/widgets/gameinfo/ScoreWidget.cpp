#include "ScoreWidget.hh"
#include "GameEventsEmitter.hh"
#include "model/Model.hh"


ScoreWidget::ScoreWidget(QWidget *parent)
    : NamedNumberWidget(QObject::tr("Score: "), parent)
{
    connect(&GameEventsEmitter::instance(), SIGNAL(modelMoved(Model)),
            this, SLOT(onScoreChanged(Model)));
    connect(&GameEventsEmitter::instance(), SIGNAL(modelCreatedNewValue(Model)),
            this, SLOT(onScoreChanged(Model)));
    connect(&GameEventsEmitter::instance(), SIGNAL(gameStarted(Model)),
            this, SLOT(onScoreChanged(Model)));
}

void ScoreWidget::onScoreChanged(const Model &model)
{
    setNumber(model.getScore());
}
