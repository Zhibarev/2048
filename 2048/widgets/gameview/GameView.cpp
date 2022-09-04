#include "GameView.hh"
#include "GameEventsEmitter.hh"
#include "model/Model.hh"
#include "widgets/settings/Settings.hh"
#include "FieldRenderer.hh"
#include <QGraphicsScene>


GameView::GameView(QWidget *parent)
    : QGraphicsView(parent)
{
    setFrameStyle(0);

    QGraphicsScene *scene = new QGraphicsScene();
    setScene(scene);

    fieldRenderer = std::make_unique<FieldRenderer>(scene);

    connect(&appearanceDelayTimer, SIGNAL(timeout()),
            this, SLOT(createNewValue()));

    connect(&GameEventsEmitter::instance(), SIGNAL(gameStarted(Model)),
            this, SLOT(onGameStarted(Model)));
    connect(&GameEventsEmitter::instance(), SIGNAL(modelMoved(Model)),
            this, SLOT(onModelMoved(Model)));
    connect(&GameEventsEmitter::instance(), SIGNAL(modelCreatedNewValue(Model)),
            this, SLOT(onModelCreatedNewValue(Model)));
}

void GameView::createNewValue()
{
    fieldRenderer->updateField(gameBoard);
    appearanceDelayTimer.stop();
    emit GameEventsEmitter::instance().viewAnimationEnded();
}

void GameView::onGameStarted(const Model &model)
{
    gameBoard.resize(model.getSize());
    for (auto &row: gameBoard)
        row.resize(model.getSize());

    scene()->setSceneRect(rect());
    fieldRenderer->createField(model, model.isGraphicsModeActive());
}

void GameView::onModelMoved(const Model &model)
{
    fieldRenderer->updateField(model);
}

void GameView::onModelCreatedNewValue(const Model &model)
{
    for (size_t i = 0; i < gameBoard.size(); i++) {
        for (size_t j = 0; j < gameBoard.size(); j++) {
            gameBoard[i][j] = model.getTileNumber(i, j);
        }
    }

    appearanceDelayTimer.start(APPEARANCE_DELAY);
    emit GameEventsEmitter::instance().viewAnimationStarted();
}
