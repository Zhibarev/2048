#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "model/GameBoard.hh"
#include "FieldRenderer.hh"
#include "widgets/settings/Settings.hh"

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <memory>


class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = nullptr);

    void startGame(const std::unique_ptr<Settings> &settings);

    void move(Coords direction);

private:
    const unsigned APPEARANCE_DELAY = 200;
    QTimer appearanceDelayTimer;

    std::shared_ptr<GameBoard> gameBoard;

    std::unique_ptr<FieldRenderer> fieldRenderer;

    bool isStarted = false;

    unsigned goal = 0;


    void blockTile(Coords coords);

private slots:
    void createNewTwo();
};

#endif // GAMEVIEW_H
