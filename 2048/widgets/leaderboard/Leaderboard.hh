#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QString>
#include <QFile>
#include <set>

#include "ScoreInfo.hh"


class Leaderboard
{
public:
    Leaderboard(size_t maxRecords = 10);
    ~Leaderboard();

    void addScore(const ScoreInfo &scoreInfo);

    QString toString() const;

private:
    const QString FILE_NAME = "leaderboard";

    size_t maxRecords = 0;

    std::multiset<ScoreInfo, std::greater<ScoreInfo>> data;
};

#endif // LEADERBOARD_H
