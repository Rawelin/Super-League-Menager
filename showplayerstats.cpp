#include "showplayerstats.h"
#include "ui_showplayerstats.h"

extern Container *container;

ShowPlayerStats::ShowPlayerStats(QWidget *parent, int i) :
    QDialog(parent),
    ui(new Ui::ShowPlayerStats)
{
    id = i;
    formation = container->teams[id].getFormation();
    setWindowFlags(Qt::WindowTitleHint);
    ui->setupUi(this);
    setGraphics();
}

ShowPlayerStats::~ShowPlayerStats()
{
    delete ui;
}

void ShowPlayerStats::setGraphics()
{
    ui->showPlayerframe->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    setStyleSheet("QTableWidget {background-color: transparent;}"
                  "QTableWidget {color: rgb(255, 255, 255);}"
                  "QTableWidget {selection-background-color: rgb(0, 255, 0, 0);}"
                  "QHeaderView::section {background-color: transparent;}"
                  "QHeaderView {background-color: transparent;}"
                  "QTableCornerButton::section {background-color: transparent;}"
                  "QHeaderView { font-size: 14pt; }");

    ui->tableWidget->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->tableWidget->horizontalHeader()->setStyleSheet("color: green");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: green");
}

void ShowPlayerStats::showStats()
{
    ui->tableWidget->setFrameShape(QFrame::NoFrame);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget->setColumnWidth(1, 120);
    ui->tableWidget->setColumnWidth(2, 130);
    ui->tableWidget->setColumnWidth(3, 40);

    int fila;

    int i;
    int limit = container->player[id].size();

    if(i >= limit)
       ui->tableWidget->setRowCount(0);

    for(i = 0; i < container->player[id].size(); ++i)
    {

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila = ui->tableWidget->rowCount() - 1;

        ui->tableWidget->setItem(fila, POSITION, new QTableWidgetItem(container->player[id][i].getPosition()));
        ui->tableWidget->setItem(fila, NAME, new QTableWidgetItem(container->player[id][i].getFname()));
        ui->tableWidget->setItem(fila, SURNAME, new QTableWidgetItem(container->player[id][i].getLname()));
        ui->tableWidget->setItem(fila, OVERALL, new QTableWidgetItem(QString::number(container->player[id][i].getRealOveral())));
    }
    for(int i = 0; i < limit; i++)
        ui->tableWidget->item(i, 3)->setTextColor(Qt::red);


}
