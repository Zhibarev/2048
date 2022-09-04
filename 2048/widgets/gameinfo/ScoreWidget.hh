#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include "namednumber/NamedNumberWidget.hh"

class Model;


class ScoreWidget : public NamedNumberWidget
{
    Q_OBJECT

public:
    explicit ScoreWidget(QWidget *parent = nullptr);

private slots:
    void onScoreChanged(const Model &model);
};

#endif // SCOREWIDGET_H
