#ifndef GAMEINFOWIDGET_H
#define GAMEINFOWIDGET_H

#include <QWidget>
#include <QString>

class Model;

namespace Ui {
class GameInfoWidget;
}

class GameInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameInfoWidget(QWidget *parent = nullptr);
    ~GameInfoWidget();

protected:
    void changeEvent(QEvent *event) override;

private:
    const QString PAUSE_MESSAGE = tr("Game paused");
    const QString WIN_MESSAGE = tr("You won!");
    const QString LOSE_MESSAGE = tr("You lose :(");

    Ui::GameInfoWidget *ui;

    QString infoLabelText;


    void setInfoLabelText(const QString &text);

private slots:
    void onGamePaused();
    void onGameEnded(const Model &model);
};

#endif // GAMEINFOWIDGET_H
