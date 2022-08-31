#include "SettingsWidget.hh"
#include "ui_SettingsWidget.h"
#include "GameEventsEmitter.hh"

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);

    connectSignalsAndSlots();
}

SettingsWidget::~SettingsWidget()
{
    delete ui;
}

std::unique_ptr<Settings> SettingsWidget::getSettings() const
{
    QString name = ui->nameEdit->text();
    unsigned goal = ui->goalSpinBox->value();
    int seed = ui->seedSpinBox->value();
    size_t size = ui->sizeSpinBox->value();

    auto settings = std::make_unique<Settings>(name, goal, size, seed);

    bool isGraphicsActive = ui->graphicsModeCheckBox->isChecked();
    if (isGraphicsActive)
        settings->activateGraphics();

    bool isRemovalActive = ui->removalCheckBox->isChecked();
    if (isRemovalActive) {
        unsigned stepsToRemoval = ui->removalSpinBox->value();
        settings->activateRemoval(stepsToRemoval);
    }

    bool isBlockActive = ui->blockCheckBox->isChecked();
    if (isBlockActive) {
        size_t blockedX = ui->blockXSpinBox->value();
        size_t blockedY = ui->blockYSpinBox->value();
        settings->acitivateBlock(blockedX, blockedY);
    }

    return settings;
}

void SettingsWidget::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
        ui->retranslateUi(this);
    else
        QWidget::changeEvent(event);
}

void SettingsWidget::connectSignalsAndSlots()
{
    connect(ui->removalCheckBox, SIGNAL(stateChanged(int)),
            this, SLOT(changeRemovalState()));
    connect(ui->blockCheckBox, SIGNAL(stateChanged(int)),
            this, SLOT(changeBlockState()));

    connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameStarted,
            [this]() { setDisabled(true); });
    connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameEnded,
            [this]() { setEnabled(true); });
    connect(&GameEventsEmitter::instance(), &GameEventsEmitter::gameReseted,
            [this]() { setEnabled(true); });
}

void SettingsWidget::changeRemovalState()
{
    bool isEnabled = ui->removalCheckBox->isChecked();
    ui->removalSpinBox->setEnabled(isEnabled);
}

void SettingsWidget::changeBlockState()
{
    bool isEnabled = ui->blockCheckBox->isChecked();
    ui->blockXSpinBox->setEnabled(isEnabled);
    ui->blockYSpinBox->setEnabled(isEnabled);
}
