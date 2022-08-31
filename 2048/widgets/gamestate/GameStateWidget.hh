#ifndef GAMESTATEWIDGET_H
#define GAMESTATEWIDGET_H

#include <QWidget>

namespace Ui {
class GameStateWidget;
}


class GameStateWidget : public QWidget
{
    Q_OBJECT

signals:
    void userTriedToStart();

public:
    explicit GameStateWidget(QWidget *parent = nullptr);
    ~GameStateWidget();

protected:
    void changeEvent(QEvent *event) override;

private:
    Ui::GameStateWidget *ui;

    bool isPaused = false;


    void changeButtonsState(bool isGameStartred);

private slots:
    void changePauseState();
    void onResetClicked();
};

#endif // GAMESTATEWIDGET_H
