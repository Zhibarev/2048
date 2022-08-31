#ifndef INSTRUCTIONBOX_H
#define INSTRUCTIONBOX_H

#include <QMessageBox>

class InstructionBox : public QMessageBox
{
    Q_OBJECT

public:
    explicit InstructionBox(QWidget *parent = nullptr);

protected:
    void changeEvent(QEvent *event) override;

private:
    void updateText();
};

#endif // INSTRUCTIONBOX_H
