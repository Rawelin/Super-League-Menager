#include "abaut.h"
#include "ui_abaut.h"
#include "container.h"

extern Container* container;

Abaut::Abaut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Abaut)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint);
    this->showFullScreen();

  //  setMouseTracking(true);
    setGraphics();

   // connect(this, SIGNAL(hovered()),this, SLOT(highLight()));
}

Abaut::~Abaut()
{
    delete ui;
}

void Abaut::setGraphics()
{ 
    ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->label_1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->label_4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
}

void Abaut::highLight()
{
    //QRect mainMenu = ui->mainMenu->geometry();


   // QString highlight = "background-color: rgba(0, 127, 255, 70);";
   // QString normal = "background-color: rgba(0, 127, 255, 30);";

    //container->functions->setHighLight(mainMenu, ui->mainMenu, highlight, normal);

}

void Abaut::mouseMoveEvent(QMouseEvent *event)
{
   // Q_EMIT hovered();

   // QWidget::enterEvent(event);
}


