#include "intro.h"
#include "ui_intro.h"

extern Container *container;

Intro::Intro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Intro)
{
    ui->setupUi(this);
    this->showFullScreen();

     QPixmap bkgnd("Stadiony/bernabeu.jpg");

    container->functions->setBackground(this, bkgnd);

    ui->go->setStyleSheet("background-color:rgba(255, 255, 255, 30);");
    container->functions->delay(200);
    ui->go->setStyleSheet("background-color:rgba(255, 255, 255, 70);");
    container->functions->delay(200);
    ui->go->setStyleSheet("background-color:rgba(255, 255, 255, 30);");
}

Intro::~Intro()
{
    delete ui;
}

void Intro::on_go_clicked()
{
    MainMenu mainmenu;
    Intro::close();
    mainmenu.exec();
}
