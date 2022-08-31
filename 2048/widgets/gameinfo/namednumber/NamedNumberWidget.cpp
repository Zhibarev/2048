#include "NamedNumberWidget.hh"
#include "ui_NamedNumberWidget.h"

NamedNumberWidget::NamedNumberWidget(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NamedNumberWidget),
    name(name)
{
    ui->setupUi(this);
    ui->nameLabel->setText(name);
}

NamedNumberWidget::~NamedNumberWidget()
{
    delete ui;
}

void NamedNumberWidget::setNumber(unsigned value)
{
    ui->numberLabel->setText(QString::number(value));
}

void NamedNumberWidget::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
        ui->nameLabel->setText(QObject::tr(qPrintable(name)));
    else
        QWidget::changeEvent(event);
}
