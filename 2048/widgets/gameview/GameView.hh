#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QTimer>
#include <memory>
#include <vector>
#include "FieldRenderer.hh"


class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = nullptr);

private:
    const unsigned APPEARANCE_DELAY = 200;
    QTimer appearanceDelayTimer;

    bool isGraphicsModeActive = false;

    std::unique_ptr<FieldRenderer> fieldRenderer;

    std::vector<std::vector<unsigned>> gameBoard;

private slots:
    void createNewValue();

    void onGameStarted(const Model &model);
    void onModelMoved(const Model& model);
    void onModelCreatedNewValue(const Model &model);
};

#endif // GAMEVIEW_H
