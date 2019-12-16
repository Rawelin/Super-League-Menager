#ifndef PLAYERSUPPORTFUNCTION_H
#define PLAYERSUPPORTFUNCTION_H

#include "container.h"

class PlayerSupportFunction
{
private:

    double gkeeper;
    double defence;
    double midfield;
    double attack;
    double tackle;
    double technick;
    double shot;
    double pass;
    double header;
    double speed;
    double overall;
    Player *player;

public:
    PlayerSupportFunction(Player *player);
    void setSupportFunction();
    double setGoalKeeperRatings();
    double setCBRatings();
    double setRBLBRatings();
    double setDMRatings();
    double setCMRatings();
    double setRMLMRatings();
    double setAMRatings();
    double setRWLWRatings();
    double setSSRatings();
    double setCFRatings();

};

#endif // PLAYERSUPPORTFUNCTION_H
