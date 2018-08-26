#ifndef LIVEMATCH_H
#define LIVEMATCH_H

#include <QDialog>
#include <QTime>
#include "container.h"
#include "team.h"
#include "matchinterface.h"
#include "player.h"
#include "artificialintelligence.h"

class MatchInterface;
class Player;
class Team;
class ArtificialIntelligence;

namespace Ui {
class LiveMatch;
}

class LiveMatch : public QDialog
{
    Q_OBJECT

public:
    explicit LiveMatch(QWidget *parent = 0, int ho = 0, int aw = 0);
    ~LiveMatch();

    void delay(int);
    void matchProgress();
    void setParameters();
    void setGraphic();
    void displayMatchStats();
    void shotsStatusBar();
    void shotsOnTargetStatusBar();
    void possessionStatusBar();
    void attackLevel();
    void computerStrategy();
    void commentary();

private slots:
    void on_back_clicked();
    void on_pause_clicked();
    void on_squad_clicked();

private:
    Ui::LiveMatch *ui;
    Team *team;
    Player *player;
    MatchInterface *matchinterface;
    ArtificialIntelligence *artificial;

    int clock;
    int home, away;
    int home_team_power, away_team_power;
    int home_amount, away_amount;
};

#endif // LIVEMATCH_H
