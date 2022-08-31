#include "LeaderboardWidget.hh"
#include "ui_LeaderboardWidget.h"

LeaderboardWidget::LeaderboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeaderboardWidget),
    leaderboard(MAX_RECORDS)
{
    ui->setupUi(this);
    updateWidget();
}

LeaderboardWidget::~LeaderboardWidget()
{
    delete ui;
}

void LeaderboardWidget::addScore(const ScoreInfo &scoreInfo)
{
    leaderboard.addScore(scoreInfo);
    updateWidget();
}

void LeaderboardWidget::updateWidget()
{
    ui->leaderboardBrowser->setText(leaderboard.toString());
}
