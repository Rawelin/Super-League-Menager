#include "team.h"


int Team::teamStrength(QVector<Player> &player, int formation)
{
    int team_strength = 0;


    team_strength += (teamGoalkeeper(player)/4) + teamDefence(player, formation)
                   + teamMidfield(player, formation) + teamAttack(player, formation);

    return team_strength / 3.25;
}

int Team::teamGoalkeeper(QVector<Player> &player)
{
    return player[0].getGkeeper();
}
int Team::teamDefence(QVector<Player> &player, int formation)
{
    int team_defence = 0;

    if(formation == 1 || formation == 2)
    {
        for(int i = 1; i <= 4; ++i)
        {
            team_defence += player[i].getOverall(i, formation);
        }
         return team_defence /= 4;
    }
    if(formation == 3)
    {
        for(int i = 1; i <= 3; ++i)
        {
            team_defence += player[i].getOverall(i, formation);
        }
         return team_defence /= 3;
    }

   return 0;
}

int Team::teamMidfield(QVector<Player> &player, int formation)
{
    int team_midfield = 0;

    if(formation == 1)
    {
        for(int i = 5; i <= 8; ++i)
        {
            team_midfield += player[i].getOverall(i, formation);

        }
        return team_midfield /= 4;
    }
    if(formation == 2)
    {
        for(int i = 5; i <= 7; ++i)
        {
            team_midfield += player[i].getOverall(i, formation);

        }
        return team_midfield /= 3;
    }
    if(formation == 3)
    {
        for(int i = 4; i <= 8; ++i)
        {
            team_midfield += player[i].getOverall(i, formation);

        }
        return team_midfield /= 5;
    }
    return 0;
}

int Team::teamAttack(QVector<Player> &player, int formation)
{
    int team_attack = 0;

    if(formation == 1 || formation == 3)
    {
        for(int i = 9; i <= 10; ++i)
        {
            team_attack += player[i].getOverall(i, formation);
        }
        return team_attack /= 2;
    }
    if(formation == 2)
    {
        for(int i = 8; i <= 10; ++i)
        {
            team_attack += player[i].getOverall(i, formation);
        }
        return team_attack /= 3;
    }
    return 0;
}

int Team::teamSpeed(QVector<Player> &player)
{
    int team_speed = 0;

    for(int i = 1; i <= 10; ++i)
    {
        team_speed += player[i].getSpeed();
    }
    return team_speed / 10;
}

int Team::teamTechnick(QVector<Player> &player)
{
    int team_technick = 0;

    for(int i = 1; i <= 10; ++i)
    {
        team_technick += player[i].getTechnik();
    }
    return team_technick / 10;
}

int Team::teamDefensive(QVector<Player> &player, int formation)
{
    int team_defensive = 0;

    team_defensive += teamDefence(player, formation)
                   + teamMidfield(player, formation) + teamSpeed(player)
                   + teamTechnick(player);

    return team_defensive / 4;
}

int Team::teamOffensive(QVector<Player> &player, int formation)
{
    int team_offensive = 0;

    team_offensive += teamAttack(player, formation)
                   + teamMidfield(player, formation) + teamSpeed(player)
                   + teamTechnick(player);

    return team_offensive / 4;
}

int Team::teamStrengthEnergy(QVector<Player> &player, int formation)
{
    int team_strength = 0;


    team_strength += (teamGoalkeeperEnergy(player)/4) + teamDefenceEnergy(player, formation)
                   + teamMidfieldEnergy(player, formation) + teamAttackEnergy(player, formation);

    return team_strength / 3.25;
}

int Team::teamGoalkeeperEnergy(QVector<Player> &player)
{
    return player[0].getGkeeper() * player[0].calcEnergy();
}

int Team::teamDefenceEnergy(QVector<Player> &player, int formation)
{
    int team_defence = 0;

    if(formation == 1 || formation == 2)
    {
        for(int i = 1; i <= 4; ++i)
        {
            team_defence += player[i].getEnergyOverall(i, formation);
        }
         return team_defence /= 4;
    }
    if(formation == 3)
    {
        for(int i = 1; i <= 3; ++i)
        {
            team_defence += player[i].getEnergyOverall(i, formation);
        }
         return team_defence /= 3;
    }

   return 0;
}

int Team::teamMidfieldEnergy(QVector<Player> &player, int formation)
{
    int team_midfield = 0;

    if(formation == 1)
    {
        for(int i = 5; i <= 8; ++i)
        {
            team_midfield += player[i].getEnergyOverall(i, formation);

        }
        return team_midfield /= 4;
    }
    if(formation == 2)
    {
        for(int i = 5; i <= 7; ++i)
        {
            team_midfield += player[i].getEnergyOverall(i, formation);

        }
        return team_midfield /= 3;
    }
    if(formation == 3)
    {
        for(int i = 4; i <= 8; ++i)
        {
            team_midfield += player[i].getEnergyOverall(i, formation);

        }
        return team_midfield /= 5;
    }
    return 0;
}

int Team::teamAttackEnergy(QVector<Player> &player, int formation)
{
    int team_attack = 0;

    if(formation == 1 || formation == 3)
    {
        for(int i = 9; i <= 10; ++i)
        {
            team_attack += player[i].getEnergyOverall(i, formation);
        }
        return team_attack /= 2;
    }
    if(formation == 2)
    {
        for(int i = 8; i <= 10; ++i)
        {
            team_attack += player[i].getEnergyOverall(i, formation);
        }
        return team_attack /= 3;
    }
    return 0;
}

int Team::teamSpeedEnergy(QVector<Player> &player)
{
    int team_speed = 0;

    for(int i = 1; i <= 10; ++i)
    {
        team_speed += player[i].getSpeed() * player[i].calcEnergy();
    }
    return team_speed / 10;
}

int Team::teamTechnickEnergy(QVector<Player> &player)
{
    int team_technick = 0;
    for(int i = 1; i <= 10; ++i)
    {
        team_technick += player[i].getTechnik() * player[i].calcEnergy();
    }
    return team_technick / 10;
}

int Team::teamTackleEnergy(QVector<Player> &player, double pressing)
{
    int team_tackle = 0;
    double RATE = 1;

    pressing /= 500;
    RATE += pressing;

    for(int i = 1; i <= 10; ++i)
    {
        team_tackle += player[i].getTackle() * player[i].calcEnergy() * RATE;
    }
    return team_tackle / 10;
}

int Team::teamDefensiveEnergy(QVector<Player> &player, int formation)
{
    int team_defensive = 0;

    team_defensive += teamDefenceEnergy(player, formation)
                   + teamMidfieldEnergy(player, formation) + teamSpeedEnergy(player)
                   + teamTechnickEnergy(player);

    return team_defensive / 4;
}

int Team::teamOffensiveEnergy(QVector<Player> &player, int formation)
{
    int team_offensive = 0;

    team_offensive += teamAttackEnergy(player, formation)
                   + teamMidfieldEnergy(player, formation) + teamSpeedEnergy(player)
                   + teamTechnickEnergy(player);

    return team_offensive / 4;
}

int Team::teamEnergy(QVector<Player> &player)
{
    int team_energy = 0;

    for(int i = 0; i <= 10; i++)
    {
        team_energy += player[i].getStamina();
    }

    return team_energy / 11;
}

void Team::clearTeamStats(QList<Team> &teams)
{
   for(int i = 0; i <teams.size(); i++)
   {
       teams[i].round = 0;
       teams[i].points = 0;
       teams[i].win = 0;
       teams[i].draw = 0;
       teams[i].lost = 0;
       teams[i].goal_scored = 0;
       teams[i].goal_lost = 0;
       teams[i].difference = 0;
   }
}


void Team::setStrikerList(const QString striker)
{
    strikerslist.push_back(striker);
}



