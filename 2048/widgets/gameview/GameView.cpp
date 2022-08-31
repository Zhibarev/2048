#include "GameView.hh"

#include "GameEventsEmitter.hh"
#include <QGraphicsScene>
#include <stdexcept>

GameView::GameView(QWidget *parent)
    : QGraphicsView(parent)
{
    setFrameStyle(0);

    QGraphicsScene *scene = new QGraphicsScene();
    setScene(scene);

    fieldRenderer = std::make_unique<FieldRenderer>(scene);

    QObject::connect(&appearanceDelayTimer, SIGNAL(timeout()), this, SLOT(createNewTwo()));
}

void GameView::startGame(const std::unique_ptr<Settings> &settings)
{
    goal = settings->getGoal();
    isStarted = true;

    gameBoard = std::make_shared<GameBoard>(settings->getSize());
    gameBoard->init_empty();
    gameBoard->fill(settings->getSeed());
    if (settings->isRemovalModeActive())
        gameBoard->activate_removal_mode(settings->getStepsToRemove());
    if (settings->isBlockModeActive())
        blockTile({ settings->getBlockedY(), settings->getBlockedX() });

    scene()->setSceneRect(rect());
    fieldRenderer->createField(gameBoard, settings->isGraphicsModeActive());

    emit GameEventsEmitter::instance().scoreChanged(gameBoard->get_score());
}

void GameView::move(Coords direction)
{
    if (!isStarted) {
        qWarning("You cannot make a move until the game has started.");
        return;
    }

    if (appearanceDelayTimer.isActive())
        return;

    bool isWin = gameBoard->move(direction, goal);

    fieldRenderer->update();

    if (isWin || gameBoard->is_full()) {
        isStarted = false;
        emit GameEventsEmitter::instance().gameEnded(isWin);
        emit GameEventsEmitter::instance().playerWon(gameBoard->get_score());
    }
    else {
        appearanceDelayTimer.start(APPEARANCE_DELAY);
    }
}

void GameView::blockTile(Coords coords)
{
    NumberTile *tile = gameBoard->get_item(coords);
    if (!tile->is_empty()) {
        gameBoard->set_tile_block(coords, true);
        gameBoard->new_value();
        fieldRenderer->update();
    }
    else {
        gameBoard->set_tile_block(coords, true);
    }
}

void GameView::createNewTwo()
{
    gameBoard->new_value();
    fieldRenderer->update();
    appearanceDelayTimer.stop();
    emit GameEventsEmitter::instance().scoreChanged(gameBoard->get_score());
}
