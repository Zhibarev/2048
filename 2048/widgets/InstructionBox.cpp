#include "InstructionBox.hh"

#include <QEvent>

InstructionBox::InstructionBox(QWidget *parent)
    : QMessageBox(parent)
{
    setTextFormat(Qt::RichText);
    updateText();
}

void InstructionBox::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
        updateText();
    else {
        QMessageBox::changeEvent(event);
    }
}

void InstructionBox::updateText()
{
    QString instructionTitle = tr("Instruction");
    setWindowTitle(instructionTitle);

    QString instruction = tr("Welcome to the 2048 game!<br>");
    instruction += tr("The general rules you can find here: <a href='https://en.wikipedia.org/wiki/2048_(video_game)#Gameplay'>rules</a><br>");
    instruction += tr("To start the game, specify the desired settings and click on Start button<br>");
    instruction += tr("<br>Control:<br>W - Up<br>S - Down<br>A - Left<br>D - Right<br>");
    setText(instruction);
}
