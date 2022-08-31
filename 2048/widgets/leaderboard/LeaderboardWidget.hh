#ifndef LEADERBOARDWIDGET_H
#define LEADERBOARDWIDGET_H

#include "ScoreInfo.hh"
#include "Leaderboard.hh"
#include <QWidget>

namespace Ui {
class LeaderboardWidget;
}

class LeaderboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LeaderboardWidget(QWidget *parent = nullptr);
    ~LeaderboardWidget();

    void addScore(const ScoreInfo &scoreInfo);

private:
    const size_t MAX_RECORDS = 10;

    Ui::LeaderboardWidget *ui;

    Leaderboard leaderboard;


    void updateWidget();
};

#endif // LEADERBOARDWIDGET_H
