#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>
#include <memory>
#include "GameBoard.hh"
#include "widgets/settings/Settings.hh"
#include "Direction.hh"

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

    void startGame(const std::unique_ptr<Settings> &settings);

    void move(Direction direction);

    void createNewValue();

    unsigned getTileNumber(size_t x, size_t y) const;

    unsigned getScore() const;

    size_t getSize() const;

    bool isWin() const;

    bool isGraphicsModeActive() const;

    const QString &getPlayerName() const;

private:
    std::unique_ptr<GameBoard> gameBoard;

    QString playerName;

    unsigned goal = 0;

    bool isPlayerWin = false;

    bool isGameStarted = false;

    bool isGraphicsActive = false;


    void blockTile(size_t x, size_t y);

    bool isInitialized() const;
};

#endif // MODEL_H
