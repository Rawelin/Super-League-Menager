#ifndef MATCHALGORITHMS_H
#define MATCHALGORITHMS_H

#include <container.h>
#include "player.h"
#include "team.h"

class Player;
class Team;

class MatchAlgorithms
{
private:
    Team *team;
    Player *player;
    QString comentary;
    QString action;
    QString strikers_name;
    QString team_name;
    QString home_striker;
    QString away_striker;
    int home, away;
    int home_shots, away_shots, home_target, away_target;
    int home_score, away_score;
    int home_team_power, away_team_power;
    int clock;
    int striker;
    int difference;
    bool start_display;
    bool live_match;
    bool home_goal_flag;
    bool away_goal_flag;

public:
    MatchAlgorithms();

    void setClock(int);
    void setAtributes(int, int);
    void setLiveMatch(bool l){live_match = l;}
    void setParameters();
    void shotOrNot();
    void strikesAway();
    void strikesHome();
    void strikerValue(int);
    void getStriker(int, bool);
    void getStrikerLive(int, bool);
    void setStatistic();
    void clearVariables();
    int getHomeScore(){return home_score;}
    int getAwayScore(){return away_score;}
    int getHomeTeamPower(){return home_team_power;}
    int getAwayTeamPower(){return away_team_power;}
    int getHomeShots(){return home_shots;}
    int getAwayShots(){return away_shots;}
    int getHomeTarget(){return home_target;}
    int getAwayTargrt(){return away_target;}
    int getDifference(){return difference;}
    QString getComentary(){return comentary;}
    QString getAction(){return action;}
    QString getStrikersName(){return strikers_name;}
    QString getTeamName(){return team_name;}
    QString getHomeStriker(){return home_striker;}
    QString getAwayStriker(){return away_striker;}
    bool getStartDisplay(){return start_display;}
    void setStartDisplay(bool d){start_display = d;}
    bool getHomeGoalFlag(){return home_goal_flag;}
    void setHomeGoalFlag(bool g){home_goal_flag = g;}
    bool getAwayGoalFlag(){return away_goal_flag;}
    void setAwayGoalFlag(bool g){away_goal_flag = g;}
};

#endif // MATCHALGORITHMS_H
