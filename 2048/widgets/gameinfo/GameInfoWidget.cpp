#include "GameInfoWidget.hh"
#include "ui_GameInfoWidget.h"
#include "GameEventsEmitter.hh"

GameInfoWidget::GameInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameInfoWidget)
{
    ui->setupUi(this);

    connect(&GameEventsEmitter::instance(), SIGNAL(gameStarted()),
            ui->infoLabel, SLOT(clear()));
    connect(&GameEventsEmitter::instance(), SIGNAL(gameUnpaused()),
            ui->infoLabel, SLOT(clear()));
    connect(&GameEventsEmitter::instance(), SIGNAL(gameReseted()),
            ui->infoLabel, SLOT(clear()));

    connect(&GameEventsEmitter::instance(), SIGNAL(gamePaused()),
            this, SLOT(onGamePaused()));
    connect(&GameEventsEmitter::instance(), SIGNAL(gameEnded(bool)),
            this, SLOT(onGameEnded(bool)));
}

GameInfoWidget::~GameInfoWidget()
{
    delete ui;
}

void GameInfoWidget::onGamePaused()
{
    setInfoLabelText(PAUSE_MESSAGE);
}

void GameInfoWidget::onGameEnded(bool isWin)
{
    if (isWin)
        setInfoLabelText(WIN_MESSAGE);
    else
        setInfoLabelText(LOSE_MESSAGE);
}

void GameInfoWidget::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
        ui->infoLabel->setText(tr(qPrintable(infoLabelText)));
    }
    else
        QWidget::changeEvent(event);
}

void GameInfoWidget::setInfoLabelText(const QString &text)
{
    infoLabelText = text;
    ui->infoLabel->setText(tr(qPrintable(infoLabelText)));
}
