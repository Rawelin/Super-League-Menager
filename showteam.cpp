#include "showteam.h"
#include "ui_showteam.h"

extern Container *container;

ShowTeam::ShowTeam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTeam)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
}

ShowTeam::~ShowTeam()
{
    delete ui;
}
