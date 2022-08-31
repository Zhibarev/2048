#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QObject>


class Settings : public QObject
{
    Q_OBJECT

public:
    Settings(const QString &name, unsigned goal, unsigned size, int seed);

    void activateRemoval(unsigned stepsToRemove);
    void acitivateBlock(size_t blockedX, size_t blockedY);
    void activateGraphics();

    const QString &getName() const;
    unsigned getGoal() const;
    unsigned getSize() const;
    int getSeed() const;

    bool isRemovalModeActive() const;
    unsigned getStepsToRemove() const;

    bool isBlockModeActive() const;
    size_t getBlockedX() const;
    size_t getBlockedY() const;

    bool isGraphicsModeActive() const;

private:
    const size_t MAX_SIZE = 5;
    const unsigned MAX_NAME_LENGTH = 16;

    QString name;
    unsigned goal;
    unsigned size;
    int seed;

    bool isRemovalActive = false;
    unsigned stepsToRemove;

    bool isBlockActive = false;
    size_t blockedX;
    size_t blockedY;

    bool isGraphicsActive = false;

    void validateSize();
    void validateGoal();
    void validateBlock();
    void validateName();

    static bool isPowOfTwo(unsigned value);
};

#endif // SETTINGS_H
