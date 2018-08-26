#include "hovered.h"
#include "ui_hovered.h"

Hovered::Hovered(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hovered)
{
    ui->setupUi(this);

    connect(this, SIGNAL(hovered()), this, SLOT(setHighLight()));
}

Hovered::~Hovered()
{
    delete ui;
}

void Hovered::setHighLight(QRect rect, QPushButton *button, QString &highlight_1, QString &highlight_2)
{
    setMouseTracking(true);

    button->setMouseTracking(true);

    if(rect.contains(QCursor::pos()))
       button->setStyleSheet(highlight_1);
    else
        button->setStyleSheet(highlight_2);
}


void Hovered::mouseMoveEvent(QMouseEvent *event)
{
    Q_EMIT hovered();
    QWidget::enterEvent(event);
}
