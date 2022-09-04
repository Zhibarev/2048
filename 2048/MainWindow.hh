#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "translator/Translator.hh"
#include "Controller.hh"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event) override;

protected:
    void changeEvent(QEvent * event) override;

private:
    Ui::MainWindow *ui;

    Controller controller;

    Translator translator;


    void connectSignalsAndSlots();

private slots:
    void OnUserTriedToStart();

    void showInstruction();
};

#endif // MAINWINDOW_H
