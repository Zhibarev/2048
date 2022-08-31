#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include "namednumber/NamedNumberWidget.hh"


class ScoreWidget : public NamedNumberWidget
{
    Q_OBJECT

public:
    explicit ScoreWidget(QWidget *parent = nullptr);
};

#endif // SCOREWIDGET_H
