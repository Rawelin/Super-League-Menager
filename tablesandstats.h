#ifndef TABLESANDSTATS_H
#define TABLESANDSTATS_H

#include <QDialog>
#include "table.h"
#include "stats.h"

namespace Ui {
class TablesAndStats;
}

class TablesAndStats : public QDialog
{
    Q_OBJECT

public:
    explicit TablesAndStats(QWidget *parent = 0);
    ~TablesAndStats();

private slots:
    void on_table_button_clicked();
    void on_stat_button_clicked();

private:
    Ui::TablesAndStats *ui;
};

#endif // TABLESANDSTATS_H
