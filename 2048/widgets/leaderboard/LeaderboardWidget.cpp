#include "LeaderboardWidget.hh"
#include "ui_LeaderboardWidget.h"
#include "model/Model.hh"
#include "ScoreInfo.hh"
#include "GameEventsEmitter.hh"

LeaderboardWidget::LeaderboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeaderboardWidget),
    leaderboard(MAX_RECORDS)
{
    ui->setupUi(this);
    updateWidget();

    connect(&GameEventsEmitter::instance(), SIGNAL(gameEnded(Model)),
            this, SLOT(onGameEnded(Model)));
}

LeaderboardWidget::~LeaderboardWidget()
{
    delete ui;
}

void LeaderboardWidget::updateWidget()
{
    ui->leaderboardBrowser->setText(leaderboard.toString());
}

void LeaderboardWidget::onGameEnded(const Model &model)
{
    if (model.isWin()) {
        ScoreInfo scoreInfo(model.getPlayerName(), model.getScore());
        leaderboard.addScore(scoreInfo);
        updateWidget();
    }
}
