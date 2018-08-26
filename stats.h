#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include <QtWidgets>
#include "container.h"
#include "person.h"
#include "team.h"


namespace Ui {
class Stats;
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = 0);
    ~Stats();
    void setGraphic();
    void table();

private slots:
     void on_pushButton_clicked();
     void on_back_clicked();

private:
    Ui::Stats *ui;
    Team *team;
    enum Columna{
        TEAM, STRENGTH
    };
};

#endif // STATS_H
