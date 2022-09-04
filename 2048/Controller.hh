#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QKeyEvent>
#include <memory>
#include "model/Model.hh"
#include "widgets/settings/Settings.hh"


class Controller : public QObject
{
public:
    Controller();

    void startGame(const std::unique_ptr<Settings> &settings);

    void move(QKeyEvent *action);

private:
    Model model;

    bool isRunning;
    bool isAnimationPlaying;
};

#endif // CONTROLLER_H
