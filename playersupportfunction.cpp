#include "playersupportfunction.h"

PlayerSupportFunction::PlayerSupportFunction()
{

}

void PlayerSupportFunction::setSupportFunction(double gk, double def, double mid, double at,
                                               double tac , double tech, double sh, double pa,
                                               double he, double sp)
{
    gkeeper = gk;
    defence = def;
    midfield = mid;
    attack = at;
    tackle = tac;
    technick = tech;
    shot = sh;
    pass = pa;
    header = he;
    speed = sp;
}

double PlayerSupportFunction::setGoalKeeperRatings()
{
    return overall = gkeeper;
}

double PlayerSupportFunction::setCBRatings()
{
    return overall = (defence + tackle + speed + header) / 4;
}

double PlayerSupportFunction::setRBLBRatings()
{
    return overall = (defence + speed + (attack * 1.2) + technick + pass) / 5;
}

double PlayerSupportFunction::setDMRatings()
{
    return overall = (defence + midfield + tackle + speed) / 4;
}

double PlayerSupportFunction::setCMRatings()
{
    return overall = (midfield + technick + pass + speed) / 4;
}

double PlayerSupportFunction::setRMLMRatings()
{
    return overall = (midfield + attack + technick + speed) /4;
}

double PlayerSupportFunction::setAMRatings()
{
    return overall = (midfield + attack + technick + shot + speed) /5;
}

double PlayerSupportFunction::setRWLWRatings()
{
    return overall = (attack + midfield + technick + shot + speed) / 5;
}

double PlayerSupportFunction::setSSRatings()
{
    return overall = (attack + speed + shot + technick + midfield) / 5;
}

double PlayerSupportFunction::setCFRatings()
{
    return overall = (attack + speed + shot + technick) / 4;
}



