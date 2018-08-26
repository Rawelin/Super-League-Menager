#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QtWidgets>
#include "person.h"
#include "team.h"

class Team;


namespace Ui {
class Table;
}

class Table : public QDialog
{
    Q_OBJECT

public:
    explicit Table(QDialog *parent = 0);
    ~Table();
   void setGraphic();
   void table();
   void setLogoAtTable(QList<Team>&);

private slots:
   void on_powrot_clicked();

private:
    QDialog *gameDialog;
    Ui::Table *ui;

    enum Columna
    {
        TEAM, ROUND, WIN, DRAW, LOST, GS, SEP, GL, DIF, POINTS
    };
};

bool worseTeam(const Team &, const Team &);

#endif // TABLE_H
