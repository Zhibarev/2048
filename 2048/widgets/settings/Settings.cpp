#include "Settings.hh"
#include "IncorrectSettingsException.hh"
#include <QtMath>

Settings::Settings(const QString &name, unsigned goal, unsigned size, int seed)
    : name(name),
      goal(goal),
      size(size),
      seed(seed)
{
    validateName();
    validateSize();
    validateGoal();
}

void Settings::activateRemoval(unsigned stepsToRemove)
{
    this->isRemovalActive = true;
    this->stepsToRemove = stepsToRemove;
}

void Settings::acitivateBlock(size_t blockedX, size_t blockedY)
{
    this->blockedX = blockedX;
    this->blockedY = blockedY;
    validateBlock();
    this->isBlockActive = true;
}

void Settings::activateGraphics()
{
    isGraphicsActive = true;
}

const QString &Settings::getName() const
{
    return name;
}

unsigned Settings::getGoal() const
{
    return goal;
}

unsigned Settings::getSize() const
{
    return size;
}

int Settings::getSeed() const
{
    return seed;
}

bool Settings::isRemovalModeActive() const
{
    return isRemovalActive;
}

bool Settings::isBlockModeActive() const
{
    return isBlockActive;
}

bool Settings::isGraphicsModeActive() const
{
    return isGraphicsActive;
}

size_t Settings::getBlockedX() const
{
    if (!isBlockActive)
        throw std::logic_error("Unable to get blockedX while blocking mode is not active");
    return blockedX;
}

size_t Settings::getBlockedY() const
{
    if (!isBlockActive)
        throw std::logic_error("Unable to get blockedY while blocking mode is not active");
    return blockedY;
}

unsigned Settings::getStepsToRemove() const
{
    if (!isRemovalActive)
        throw std::logic_error("Unable to get stepsToRemove while removal mode is not active");
    return stepsToRemove;
}

void Settings::validateSize()
{
    if (size > MAX_SIZE)
        throw IncorrectSettingsException(tr("Size must not exceed ") + QString::number(MAX_SIZE));
}

void Settings::validateGoal()
{
    unsigned maxGoal = qPow(2, size * size);
    if (goal > maxGoal)
        throw IncorrectSettingsException(tr("Goal exceeds maximum achievable"));

    if (!isPowOfTwo(goal))
        throw IncorrectSettingsException(tr("Goal must be a power of two"));
}

void Settings::validateBlock()
{
    if (blockedX >= size || blockedY >= size)
        throw IncorrectSettingsException(tr("The blocking tile coords must be smaller than the size"));
}

void Settings::validateName()
{
    if (name.size() > MAX_NAME_LENGTH)
        throw IncorrectSettingsException(tr("Name must not exceed 16 characters"));
}

bool Settings::isPowOfTwo(unsigned value)
{
    return value != 0 && !(value & (value - 1));
}
