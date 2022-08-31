#include "GameStateWidget.hh"
#include "ui_GameStateWidget.h"
#include "GameEventsEmitter.hh"

GameStateWidget::GameStateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStateWidget),
    isPaused(false)
{
    ui->setupUi(this);

    connect(ui->startButton, SIGNAL(clicked()),
            this, SIGNAL(userTriedToStart()));
    connect(ui->pauseButton, SIGNAL(clicked()),
            this, SLOT(changePauseState()));
    connect(ui->resetButton, SIGNAL(clicked()),
            this, SLOT(onResetClicked()));

    connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameStarted,
            [this]() { changeButtonsState(true); });
    connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameEnded,
            [this]() { changeButtonsState(false); });
}

GameStateWidget::~GameStateWidget()
{
    delete ui;
}

void GameStateWidget::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
        ui->retranslateUi(this);
    else
        QWidget::changeEvent(event);
}

void GameStateWidget::changePauseState()
{
    if (isPaused) {
        isPaused = false;
        ui->pauseButton->setText(tr("Pause"));
        emit GameEventsEmitter::instance().gameUnpaused();
    }
    else {
        isPaused = true;
        ui->pauseButton->setText(tr("Unpause"));
        emit GameEventsEmitter::instance().gamePaused();
    }
}

void GameStateWidget::onResetClicked()
{
    if (isPaused)
        changePauseState();
    changeButtonsState(false);
    emit GameEventsEmitter::instance().gameReseted();
}

void GameStateWidget::changeButtonsState(bool isGameStartred)
{
    ui->startButton->setEnabled(!isGameStartred);
    ui->pauseButton->setEnabled(isGameStartred);
    ui->resetButton->setEnabled(isGameStartred);
}
