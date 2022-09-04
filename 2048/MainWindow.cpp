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
    controller.move(event);
}

void MainWindow::connectSignalsAndSlots()
{
    connect(ui->gameStateWidget, SIGNAL(userTriedToStart()),
            this, SLOT(OnUserTriedToStart()));

    connect(ui->actionEnglish, &QAction::triggered,
            [this]() { translator.loadTranslation(Language::ENGLISH); } );
    connect(ui->actionFinnish, &QAction::triggered,
            [this]() { translator.loadTranslation(Language::FINISH); } );

    connect(ui->actionInstruction, SIGNAL(triggered(bool)),
            this, SLOT(showInstruction()));
}

void MainWindow::OnUserTriedToStart()
{
    statusBar()->clearMessage();

    try {
        auto settings = ui->settingsTab->getSettings();
        controller.startGame(settings);
    }
    catch (const IncorrectSettingsException &exception) {
        statusBar()->showMessage(exception.what());
    }
}

void MainWindow::showInstruction()
{
    InstructionBox instructionBox;
    instructionBox.exec();
}
