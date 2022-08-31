#ifndef NAMEDNUMBERWIDGET_H
#define NAMEDNUMBERWIDGET_H

#include <QWidget>

namespace Ui {
class NamedNumberWidget;
}

class NamedNumberWidget : public QWidget
{
    Q_OBJECT

public:
    NamedNumberWidget(const QString &name, QWidget *parent = nullptr);
    ~NamedNumberWidget();

protected:
    void setNumber(unsigned value);

    void changeEvent(QEvent *event) override;

private:
    Ui::NamedNumberWidget *ui;

    QString name;
};

#endif // NAMEDNUMBERWIDGET_H
