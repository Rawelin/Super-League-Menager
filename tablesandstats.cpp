#include "tablesandstats.h"
#include "ui_tablesandstats.h"

TablesAndStats::TablesAndStats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TablesAndStats)
{
    ui->setupUi(this);
}

TablesAndStats::~TablesAndStats()
{
    delete ui;
}

void TablesAndStats::on_table_button_clicked()
{
    Table table;
    table.setModal(true);
    table.exec();
}

void TablesAndStats::on_stat_button_clicked()
{
    Stats stats;
    stats.setModal(true);
    stats.exec();
}
