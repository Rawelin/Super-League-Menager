#include "holder.h"
#include "ui_holder.h"

Holder::Holder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Holder)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    this->move(800,640);

    ui->play->setStyleSheet("background-color: rgba(255, 255, 255, 50);");


}

Holder::~Holder()
{
    delete ui;
}
