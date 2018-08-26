#ifndef SHOWPLAYERSTATS_H
#define SHOWPLAYERSTATS_H

#include <QDialog>
#include "team.h"

namespace Ui {
class ShowPlayerStats;
}

class ShowPlayerStats : public QDialog
{
    Q_OBJECT

public:
    explicit ShowPlayerStats(QWidget *parent = 0, int i= 0);
    ~ShowPlayerStats();
    void setPlayerId(int i){id = i;}
    void setGraphics();
    void showStats();

private:
    Ui::ShowPlayerStats *ui;
    Team *team;
    enum Columna
    {
        POSITION, NAME, SURNAME, OVERALL
    };
    int id;
    int formation;

};

#endif // SHOWPLAYERSTATS_H
