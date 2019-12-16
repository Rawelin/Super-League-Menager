#include "playersupportfunction.h"

PlayerSupportFunction::PlayerSupportFunction(Player *player)
{
    this->player = player;
}

void PlayerSupportFunction::setSupportFunction()
{
    gkeeper = player->getGkeeper();
    defence = player->getDefence();
    midfield = player->getMidfield();
    attack = player->getAttack();
    tackle = player->getTackle();
    technick = player->getTechnik();
    shot = player->getShot();
    pass = player->getPass();
    header = player->getHeader();
    speed = player->getSpeed();
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



