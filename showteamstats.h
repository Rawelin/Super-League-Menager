#ifndef SHOWTEAMSTATS_H
#define SHOWTEAMSTATS_H

#include <QDialog>
#include "container.h"
#include "team.h"

class Team;

namespace Ui {
class ShowTeamStats;
}

class ShowTeamStats : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTeamStats(QWidget *parent = 0, int i = 0);
    ~ShowTeamStats();
    void setTeamId(int i){id = i;}
    void setGraphics();
    void showStats();
    void table();

private:
    Ui::ShowTeamStats *ui;
    Team *team;
    int id;
};

#endif // SHOWTEAMSTATS_H
