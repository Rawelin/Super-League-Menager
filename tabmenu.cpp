#include "tabmenu.h"
#include "ui_tabmenu.h"

TabMenu::TabMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabMenu)
{
    ui->setupUi(this);
 //   ui->tabWidget->addTab(new Table(), QString("Tabela"));

    TabMenu::showFullScreen();

    ui->tabWidget->showFullScreen();
    ui->tab->showFullScreen();
    ui->tab_2->showFullScreen();
}

TabMenu::~TabMenu()
{
    delete ui;
}

void TabMenu::on_tabWidget_destroyed()
{

}

void TabMenu::on_tabWidget_tabBarClicked(int index)
{
    index = 0;
    Table table;
    table.exec();
}
