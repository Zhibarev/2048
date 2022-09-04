#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <memory>

class Settings;

namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = nullptr);
    ~SettingsWidget();

    std::unique_ptr<Settings> getSettings() const;

protected:
    void changeEvent(QEvent *event) override;

private:
    Ui::SettingsWidget *ui;

    void connectSignalsAndSlots();

private slots:
    void changeRemovalState();
    void changeBlockState();
};

#endif // SETTINGSWIDGET_H
