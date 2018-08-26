#ifndef TEAM_H
#define TEAM_H

#include <QtWidgets>
#include "player.h"
#include "stadium.h"

class Player;

class Team
{
private:
    QString name;
    QString city;
    QString separator;
    QString short_name;
    int round;
    int points;
    int win;
    int draw;
    int lost;
    int goal_scored;
    int goal_lost;
    int difference;
    int strength;
    int formation;
    int score;
    int team_id;
    int pressing;
    int tackle;
    int attack_level;
    QVector<Player>player;
    Stadium stadium;
    QList<QString> strikerslist;
    QPixmap logo;
    QPixmap tshirt;

public:
    Team() {}
    Team(const QString& n,const QString& c)
    : name(n), city(c), separator("-"), round(0), points(0), win(0), draw(0), lost(0), goal_scored(0), goal_lost(0),
      difference(0), strength(0), formation(0), score(0), pressing(50){}
    ~Team () {}

    friend class Serialization;

    QString getName()const{return name;}
    QString getCity()const{return city;}
    QString getSeparator(){return separator;}
    QString getShortName(){return short_name;}
    int getRound()const{return round;}
    int getPoint()const{return points;}
    int getWin()const{return win;}
    int getDraw()const{return draw;}
    int getLost()const{return lost;}
    int getGoalScored()const{return goal_scored;}
    int getGoalLost()const{return goal_lost;}
    int getDiffer()const{return goal_scored - goal_lost;}
    int getStrength()const{return strength;}
    int getFormation()const{return formation;}
    int getScore()const{return score;}
    int getTeamId()const{return team_id;}
    int getPressing()const{return pressing;}
    int getTackle()const{return tackle;}
    int getAttackLevel()const{return attack_level;}
    QVector<Player>getPlayer()const{return player;}
    QVector<Player>&getPlayer(){return player;}
    Stadium &getStadium(){return stadium;}
    QPixmap getLogo(){return logo;}
    QPixmap getTshirt(){return tshirt;}
    QList<QString> getStrikerList(){return strikerslist;}

    void setName(QString& n){name = n;}
    void setCity(QString& c){city = c;}
    void setSeparator(){separator = "-";}
    void setRound(int r){round += r;}
    void setPoint(int p){points += p;}
    void setWin(){win++;}
    void setDraw(){draw++;}
    void setLost(){lost++;}
    void setGoalScored(int g){goal_scored += g;}
    void setGoalLost(int g){goal_lost += g;}
    void setDiffer(int d){difference += d;}
    void setStrength(int s){strength = s;}
    void setFormation(int f){formation = f;}
    void setScore(int s){score = s;}
    void setPressing(int p){pressing = p;}
    void setAttackLevel(int a){attack_level = a;}
    void setPlayer(const Player &p){player.push_back(p);}
    void setStadium(const Stadium &s){stadium = s;}
    void setLogo(QPixmap l){logo = l;}
    void setTshirt(QPixmap t){tshirt = t;}
    void setStrikerList(const QString);

    int teamStrength(QVector<Player>&, int);
    int teamGoalkeeper(QVector<Player>&);
    int teamDefence(QVector<Player>&, int);
    int teamMidfield(QVector<Player>&, int);
    int teamAttack(QVector<Player>&, int);
    int teamSpeed(QVector<Player>&);
    int teamTechnick(QVector<Player>&);
    int teamDefensive(QVector<Player>&, int);
    int teamOffensive(QVector<Player>&, int);

    int teamStrengthEnergy(QVector<Player>&, int);
    int teamGoalkeeperEnergy(QVector<Player>&);
    int teamDefenceEnergy(QVector<Player>&, int);
    int teamMidfieldEnergy(QVector<Player>&, int);
    int teamAttackEnergy(QVector<Player>&, int);
    int teamSpeedEnergy(QVector<Player>&);
    int teamTechnickEnergy(QVector<Player>&);
    int teamTackleEnergy(QVector<Player>&, double);
    int teamDefensiveEnergy(QVector<Player>&, int);
    int teamOffensiveEnergy(QVector<Player>&, int);
    int teamEnergy(QVector<Player>&);

    void clearStrikerList(){strikerslist.clear();}
    void clearTeamStats(QList<Team>&);

};

#endif // TEAM_H
