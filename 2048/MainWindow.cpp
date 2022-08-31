#include "MainWindow.hh"
#include "ui_Mainwindow.h"

#include "widgets/settings/Settings.hh"
#include "widgets/settings/IncorrectSettingsException.hh"
#include "widgets/InstructionBox.hh"
#include "GameEventsEmitter.hh"
#include "translator/Language.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    controller = std::make_unique<Controller>(ui->gameView);

    connectSignalsAndSlots();
}

void MainWindow::changeEvent(QEvent * event) {
    if (event->type() == QEvent::LanguageChange)
        ui->retranslateUi(this);
    else
        QWidget::changeEvent(event);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    controller->move(event);
}

void MainWindow::connectSignalsAndSlots()
{
    connect(ui->gameStateWidget, SIGNAL(userTriedToStart()),
            this, SLOT(OnUserTriedToStart()));
    connect(&GameEventsEmitter::instance(), SIGNAL(playerWon(uint)),
            this, SLOT(onPlayerWon(uint)));

    connect(ui->actionEnglish, &QAction::triggered,
            [this]() { translator.loadTranslation(Language::ENGLISH); } );
    connect(ui->actionFinnish, &QAction::triggered,
            [this]() { translator.loadTranslation(Language::FINISH); } );

    connect(ui->actionInstruction, SIGNAL(triggered(bool)),
            this, SLOT(showInstruction()));
}

void MainWindow::OnUserTriedToStart()
{
    ui->statusbar->clearMessage();

    try {
        auto settings = ui->settingsTab->getSettings();
        playerName = settings->getName();
        ui->gameView->startGame(settings);
        emit GameEventsEmitter::instance().gameStarted();
    }
    catch (const IncorrectSettingsException &exception) {
        statusBar()->showMessage(exception.what());
    }
}

void MainWindow::onPlayerWon(unsigned finalScore)
{
    ScoreInfo scoreInfo(playerName, finalScore);
    ui->leaderboardTab->addScore(scoreInfo);
}

void MainWindow::showInstruction()
{
    InstructionBox instructionBox;
    instructionBox.exec();
}
