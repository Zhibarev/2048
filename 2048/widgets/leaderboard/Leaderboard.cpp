#include "Leaderboard.hh"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <algorithm>
#include <iterator>

Leaderboard::Leaderboard(size_t maxRecords)
    : maxRecords(maxRecords)
{
    QFile leaderboardFile(FILE_NAME);
    if (leaderboardFile.open(QIODevice::ReadOnly)) {
        QTextStream input(&leaderboardFile);
        char separator = ' ';
        while (!input.atEnd()) {
            QString line = input.readLine();
            QStringList splitted = line.split(separator);
            QString name = splitted[0];
            unsigned score = splitted[1].toUInt();
            data.emplace(name, score);
            if (data.size() == maxRecords)
                break;
        }
    }
}

Leaderboard::~Leaderboard()
{
    QFile leaderboardFile(FILE_NAME);
    if (leaderboardFile.open(QIODevice::WriteOnly)) {
        QTextStream output(&leaderboardFile);
        for (const ScoreInfo &scoreInfo: data) {
            output << scoreInfo.getUserName() << " " << scoreInfo.getScore() << "\n";
        }
    }
}

void Leaderboard::addScore(const ScoreInfo &scoreInfo)
{
    data.emplace(scoreInfo);

    if (data.size() > maxRecords)
        data.erase(std::prev(data.end()));
}

QString Leaderboard::toString() const
{
    QString result;
    size_t position = 1;
    for (const auto &scoreInfo: data) {
        QString positionString = QString::number(position);
        QString name = scoreInfo.getUserName();
        QString scoreString = QString::number(scoreInfo.getScore());
        result += QString("%1. %2 %3\n").arg(positionString, name, scoreString);
        position++;
    }
    return result;
}
