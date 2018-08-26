#ifndef MATCHSIMULATION_H
#define MATCHSIMULATION_H

#include "container.h"
#include "team.h"
#include "player.h"
#include "matchalgorithms.h"

class Player;
class MatchAlgorithms;

class MatchSimulation
{

public:
    MatchSimulation(int ho, int aw);

    void matchProgress();
    void setParameters();
    void shotOrNot();
    void strikesHome();
    void strikesAway();
    void getStriker(int,bool);
    void setStatistic();
    int getClock(){return clock;}

private:
    Team *team;
    Player *player;
    MatchAlgorithms* matchAlgo;
    int clock;
    int home, away;
    int home_shots, away_shots, home_target, away_target;
    int home_team_power, away_team_power;
    int home_score, away_score;
};

#endif // MATCHSIMULATION_H
