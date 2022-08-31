#ifndef SCOREINFO_H
#define SCOREINFO_H

#include <QString>


class ScoreInfo
{
public:
    ScoreInfo() = default;

    ScoreInfo(const QString &userName, unsigned score);

    unsigned getScore() const;
    const QString &getUserName() const;

private:
    QString userName;
    unsigned score = 0;
};

// comparison operators, the comparison is based on the number of points.
bool operator<(const ScoreInfo &lhs, const ScoreInfo &rhs);
bool operator>(const ScoreInfo &lhs, const ScoreInfo &rhs);
bool operator==(const ScoreInfo &lhs, const ScoreInfo &rhs);
bool operator!=(const ScoreInfo &lhs, const ScoreInfo &rhs);
bool operator<=(const ScoreInfo &lhs, const ScoreInfo &rhs);
bool operator>=(const ScoreInfo &lhs, const ScoreInfo &rhs);

#endif // SCOREINFO_H
