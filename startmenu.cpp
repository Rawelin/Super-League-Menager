#include "startmenu.h"
#include "ui_startmenu.h"
#include "mainmenu.h"

StartMenu::StartMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartMenu)
{
    ui->setupUi(this);
}

StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::on_pushButton_clicked()
{
    MainMenu* mainmenu = new MainMenu();
    mainmenu->show();
    StartMenu::close();
}
