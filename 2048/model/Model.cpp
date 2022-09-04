#include "Model.hh"
#include "GameEventsEmitter.hh"

Model::Model(QObject *parent)
    : QObject(parent)
{
    connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameReseted,
            [this]() { isGameStarted = false; });
}

void Model::move(Direction direction)
{
    if (!isInitialized())
        qFatal("Unable to move while the game is uninitialized");

    if (!isGameStarted)
        qFatal("Unable to move while the game is not started");

    Coords coordsDirection;
    switch (direction) {
        case Direction::LEFT:
             coordsDirection = {0, -1};
            break;
        case Direction::RIGHT:
            coordsDirection = {0, 1};
            break;
        case Direction::UP:
            coordsDirection = {-1, 0};
            break;
        case Direction::DOWN:
            coordsDirection = {1, 0};
            break;
        default:
            return;
    }

    isPlayerWin = gameBoard->move(coordsDirection, goal);

    emit GameEventsEmitter::instance().modelMoved(*this);

    if (isPlayerWin) {
        isGameStarted = false;
        emit GameEventsEmitter::instance().gameEnded(*this);
    }
}

void Model::createNewValue()
{
    if (!isInitialized())
        qFatal("Unable to create new value while the game is uninitialized");

    if (!isGameStarted)
        qFatal("Unable to create new value while the game is not started");

    if (gameBoard->is_full()) {
        isGameStarted = false;
        emit GameEventsEmitter::instance().gameEnded(*this);
        return;
    }

    gameBoard->new_value();
    emit GameEventsEmitter::instance().modelCreatedNewValue(*this);
}

unsigned Model::getTileNumber(size_t x, size_t y) const
{
    if (!isInitialized())
        qFatal("Unable to get tile's number while the game is uninitialized");

    return gameBoard->get_item({ y, x })->get_value();
}

size_t Model::getSize() const
{
    if (!isInitialized())
        qFatal("Unable to get size of model while the game is uninitialized");

    return gameBoard->get_size();
}

unsigned Model::getScore() const
{
    if (!isInitialized())
        qFatal("Unable to get score while the game is uninitialized");

    return gameBoard->get_score();
}

const QString &Model::getPlayerName() const
{
    if (!isInitialized())
        qFatal("Unable to get player's name while the game is uninitialized");

    return playerName;
}

bool Model::isWin() const
{
    if (!isInitialized())
        qFatal("Unable to check is player win while the game is uninitialized");

    return isPlayerWin;
}

bool Model::isGraphicsModeActive() const
{
    if (!isInitialized())
        qFatal("Unable to check is graphics active while the game is uninitialized");

    return isGraphicsActive;
}

bool Model::isInitialized() const
{
    return gameBoard != nullptr;
}

void Model::startGame(const std::unique_ptr<Settings> &settings)
{
    if (isGameStarted)
        qFatal("Unable to start the game, it is already started");

    isPlayerWin = false;
    isGameStarted = true;
    isGraphicsActive = settings->isGraphicsModeActive();
    goal = settings->getGoal();
    playerName = settings->getName();

    gameBoard = std::make_unique<GameBoard>(settings->getSize());
    gameBoard->init_empty();
    gameBoard->fill(settings->getSeed());
    if (settings->isRemovalModeActive())
        gameBoard->activate_removal_mode(settings->getStepsToRemove());
    if (settings->isBlockModeActive())
        blockTile(settings->getBlockedX(), settings->getBlockedY());

    emit GameEventsEmitter::instance().gameStarted(*this);
}

void Model::blockTile(size_t x, size_t y)
{
    Coords coordinates = { y, x };
    NumberTile *tile = gameBoard->get_item(coordinates);
    if (!tile->is_empty()) {
        gameBoard->set_tile_block(coordinates, true);
        gameBoard->new_value();
    }
    else {
        gameBoard->set_tile_block(coordinates, true);
    }
}
