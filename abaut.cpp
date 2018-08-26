#include "abaut.h"
#include "ui_abaut.h"

Abaut::Abaut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Abaut)
{
    ui->setupUi(this);
}

Abaut::~Abaut()
{
    delete ui;
}
