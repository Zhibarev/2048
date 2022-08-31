#include "ScoreInfo.hh"

ScoreInfo::ScoreInfo(const QString &userName, unsigned score)
    : userName(userName), score(score)
{
}

unsigned ScoreInfo::getScore() const
{
    return score;
}

const QString &ScoreInfo::getUserName() const
{
    return userName;
}

bool operator<(const ScoreInfo &lhs, const ScoreInfo &rhs) {
    return lhs.getScore() < rhs.getScore();
}

bool operator>(const ScoreInfo &lhs, const ScoreInfo &rhs) {
    return lhs.getScore() > rhs.getScore();
}

bool operator==(const ScoreInfo &lhs, const ScoreInfo &rhs) {
    return lhs.getScore() == rhs.getScore();
}

bool operator!=(const ScoreInfo &lhs, const ScoreInfo &rhs) {
    return lhs.getScore() != rhs.getScore();
}

bool operator<=(const ScoreInfo &lhs, const ScoreInfo &rhs) {
    return lhs.getScore() <= rhs.getScore();
}

bool operator>=(const ScoreInfo &lhs, const ScoreInfo &rhs) {
    return lhs.getScore() >= rhs.getScore();
}
