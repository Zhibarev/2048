#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QTimer>
#include "namednumber/NamedNumberWidget.hh"


class TimeWidget : public NamedNumberWidget
{
    Q_OBJECT

public:
    explicit TimeWidget(QWidget *parent = nullptr);

private:
    const int UPDATE_INTERVAL = 1000;

    int timePassed;
    QTimer timer;


    void setTime(int time);

private slots:
    void updateTime();

    void onGameStarted();
    void onGameUnpaused();
    void stopTimer();
};

#endif // TIMEWIDGET_H
