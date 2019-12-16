#include <QDebug>
#include "player.h"
#include "playersupportfunction.h"

extern Container *container;

int Player::getOverall(int current_position, int formation)
{
    setPlayerSupportFunction();

    if(current_position < 11)
    {
        if(formation == 1)                                                                //  4-4-2
        {
            switch(current_position)
            {
                case 0:
                     return overall = player_support_function->setGoalKeeperRatings();    // GK
                break;
                case 1:
                     if(position == "RB")
                        return overall = player_support_function->setRBLBRatings() * 0.95;
                     else if(position == "RM")
                         return overall = player_support_function->setRMLMRatings() * 0.95;
                     else if(position == "RW")
                         return overall = player_support_function->setRWLWRatings() * 0.95;
                     else
                        return overall = player_support_function->setRBLBRatings();       // LB
                break;
                    case 2:
                         return overall = player_support_function->setCBRatings();        // CB
                    break;
                    case 3:
                          return overall = player_support_function->setCBRatings();       // CB
                    break;
                case 4:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRBLBRatings();        // RB
                break;
                case 5:
                    if(position == "RB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "RM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "RW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                     else
                        return overall = player_support_function->setRMLMRatings();        // LM
                break;
                case 6:
                       return overall = player_support_function->setDMRatings();           // DM
                break;
                case 7:
                       return overall = player_support_function->setCMRatings();           // CM
                break;
                case 8:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRMLMRatings();        // RM
                break;
                case 9:
                     return overall = player_support_function->setCFRatings();             // CF
                break;
                case 10:
                     return overall = player_support_function->setSSRatings();             // SS
                break;
            }
        }
        if(formation == 2)                                                                //  4-3-3
        {
            switch(current_position)
            {
                case 0:
                     return overall = player_support_function->setGoalKeeperRatings();    // GK
                break;
                case 1:
                    if(position == "RB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "RM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "RW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                       return overall = player_support_function->setRBLBRatings();        // LB
                case 2:
                    return overall = player_support_function->setCBRatings();             // CB
                break;
                case 3:
                         return overall = player_support_function->setCBRatings();        // CB
                break;
                case 4:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRBLBRatings();       // RB
                break;
                case 5:
                      return overall = player_support_function->setCMRatings();           // CM
                break;
                case 6:
                       return overall = player_support_function->setDMRatings();           //  DM
                break;
                case 7:
                       return overall = player_support_function->setCMRatings();           // CM
                break;
                case 8:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRWLWRatings();       // RW
                break;
                case 9:
                    if(position == "RB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "RM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "RW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                       return overall = player_support_function->setRWLWRatings();        // LW
                break;
                case 10:
                     return overall = player_support_function->setCFRatings();            // CF
                break;
            }
        }
        if(formation == 3)                                                                //  3-5-2
        {
            switch(current_position)
            {
                case 0:
                     return overall = player_support_function->setGoalKeeperRatings();   // GK
                break;
                case 1:
                     return overall = player_support_function->setCBRatings();            // CB
                break;
                case 2:
                     return overall = player_support_function->setCBRatings();            // CB
                break;
                case 3:
                     return overall = player_support_function->setCBRatings();            // CB
                break;
                case 4:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRMLMRatings();        // RM
            break;
                break;
                case 5:
                    if(position == "RB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "RM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "RW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                     else
                        return overall = player_support_function->setRMLMRatings();          // LM
                break;
                case 6:
                       return overall = player_support_function->setDMRatings();             //  DM
                break;
                case 7:
                       return overall = player_support_function->setCMRatings();             // CM
                break;
                case 8:
                       return overall = player_support_function->setAMRatings();             // AM
                break;
                case 9:
                       return overall = player_support_function->setCFRatings();            // CF
                break;
                case 10:
                       return overall = player_support_function->setSSRatings();            // SS
                break;
            }
        }
    }
    else
    {
        if(position == "GK")
            return overall = player_support_function->setGoalKeeperRatings();
        else if(position == "CB")
             return overall = player_support_function->setCBRatings();
        else if(position == "LB" || position == "RB")
            return overall = player_support_function->setRBLBRatings();
        else if(position == "DM")
            return overall = player_support_function->setDMRatings();
        else if(position == "CM")
            return overall = player_support_function->setCMRatings();
        else if(position == "LM" || position == "RM")
            return overall = player_support_function->setRMLMRatings();
        else if(position == "AM")
            return overall = player_support_function->setAMRatings();
        else if(position == "RW" || position == "LW")
            return overall = player_support_function->setRWLWRatings();
        else if(position =="SS")
            return overall = player_support_function->setSSRatings();
        else if(position == "CF")
            return overall = player_support_function->setCFRatings();
        else
            return 0;
    }
    return 0;
}

int Player::getEnergyOverall(int current_position, int formation)
{
    setPlayerSupportFunction();

    if(current_position < 11)
    {
        if(formation == 1)                                                                //  4-4-2
        {
            switch(current_position)
            {
                case 0:
                     return overall = player_support_function->setGoalKeeperRatings() * rateEnergy();     // GK
                break;
                case 1:
                     if(position == "RB")
                        return overall = player_support_function->setRBLBRatings() * rateEnergy() * 0.95;
                     else if(position == "RM")
                         return overall = player_support_function->setRMLMRatings() * rateEnergy() * 0.95;
                     else if(position == "RW")
                         return overall = player_support_function->setRWLWRatings() * rateEnergy() * 0.95;
                     else
                        return overall = player_support_function->setRBLBRatings() * rateEnergy();       // LB
                break;
                    case 2:
                         return overall = player_support_function->setCBRatings() * rateEnergy();        // CB
                    break;
                    case 3:
                          return overall = player_support_function->setCBRatings() * rateEnergy();      // CB
                    break;
                case 4:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRBLBRatings() * rateEnergy();        // RB
                break;
                case 5:
                    if(position == "RB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "RM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "RW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                     else
                        return overall = player_support_function->setRMLMRatings() * rateEnergy();        // LM
                break;
                case 6:
                       return overall = player_support_function->setDMRatings() * rateEnergy();           // DM
                break;
                case 7:
                       return overall = player_support_function->setCMRatings() * rateEnergy();           // CM
                break;
                case 8:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRMLMRatings() * rateEnergy();       // RM
                break;
                case 9:
                     return overall = player_support_function->setCFRatings() * rateEnergy();             // CF
                break;
                case 10:
                     return overall = player_support_function->setSSRatings() * rateEnergy();             // SS
                break;
            }
        }
        if(formation == 2)                                                                //  4-3-3
        {
            switch(current_position)
            {
                case 0:
                     return overall = player_support_function->setGoalKeeperRatings() * rateEnergy();     // GK
                break;
                case 1:
                    if(position == "RB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "RM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "RW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                       return overall = player_support_function->setRBLBRatings() * rateEnergy();        // LB
                case 2:
                    return overall = player_support_function->setCBRatings() * rateEnergy();             // CB
                break;
                case 3:
                         return overall = player_support_function->setCBRatings() * rateEnergy();        // CB
                break;
                case 4:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRBLBRatings() * rateEnergy();       // RB
                break;
                case 5:
                      return overall = player_support_function->setCMRatings() * rateEnergy();           // CM
                break;
                case 6:
                       return overall = player_support_function->setDMRatings() * rateEnergy();           //  DM
                break;
                case 7:
                       return overall = player_support_function->setCMRatings() * rateEnergy();           // CM
                break;
                case 8:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRWLWRatings() * rateEnergy();       // RW
                break;
                case 9:
                    if(position == "RB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "RM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "RW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                       return overall = player_support_function->setRWLWRatings() * rateEnergy();        // LW
                break;
                case 10:
                     return overall = player_support_function->setCFRatings() * rateEnergy() * rateEnergy();            // CF
                break;
            }
        }
        if(formation == 3)                                                                //  3-5-2
        {
            switch(current_position)
            {
                case 0:
                     return overall = player_support_function->setGoalKeeperRatings() * rateEnergy();    // GK
                break;
                case 1:
                     return overall = player_support_function->setCBRatings() * rateEnergy();            // CB
                break;
                case 2:
                     return overall = player_support_function->setCBRatings() * rateEnergy();            // CB
                break;
                case 3:
                     return overall = player_support_function->setCBRatings() * rateEnergy();            // CB
                break;
                case 4:
                    if(position == "LB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "LM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "LW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                    else
                        return overall = player_support_function->setRMLMRatings() * rateEnergy();        // RM
            break;
                break;
                case 5:
                    if(position == "RB")
                       return overall = player_support_function->setRBLBRatings() * 0.95;
                    else if(position == "RM")
                        return overall = player_support_function->setRMLMRatings() * 0.95;
                    else if(position == "RW")
                        return overall = player_support_function->setRWLWRatings() * 0.95;
                     else
                        return overall = player_support_function->setRMLMRatings() * rateEnergy();         // LM
                break;
                case 6:
                       return overall = player_support_function->setDMRatings() * rateEnergy();             //  DM
                break;
                case 7:
                       return overall = player_support_function->setCMRatings() * rateEnergy();             // CM
                break;
                case 8:
                       return overall = player_support_function->setAMRatings() * rateEnergy();             // AM
                break;
                case 9:
                       return overall = player_support_function->setCFRatings() * rateEnergy();            // CF
                break;
                case 10:
                       return overall = player_support_function->setSSRatings() * rateEnergy();            // SS
                break;
            }
        }
    }
    else
    {
        if(position == "GK")
            return overall = player_support_function->setGoalKeeperRatings() * rateEnergy();
        else if(position == "CB")
             return overall = player_support_function->setCBRatings() * rateEnergy();
        else if(position == "LB" || position == "RB")
            return overall = player_support_function->setRBLBRatings() * rateEnergy();
        else if(position == "DM")
            return overall = player_support_function->setDMRatings() * rateEnergy();
        else if(position == "CM")
            return overall = player_support_function->setCMRatings() * rateEnergy();
        else if(position == "LM" || position == "RM")
            return overall = player_support_function->setRMLMRatings() * rateEnergy();
        else if(position == "AM")
            return overall = player_support_function->setAMRatings() * rateEnergy();
        else if(position == "RW" || position == "LW")
            return overall = player_support_function->setRWLWRatings() * rateEnergy();
        else if(position =="SS")
            return overall = player_support_function->setSSRatings() * rateEnergy();
        else if(position == "CF")
            return overall = player_support_function->setCFRatings() * rateEnergy();
        else
            return 0;
    }
    return 0;
}

int Player::getRealOveral()
{
    setPlayerSupportFunction();

    if(position == "GK")
        return overall = player_support_function->setGoalKeeperRatings();
    else if(position == "CB")
         return overall = player_support_function->setCBRatings();
    else if(position == "LB" || position == "RB")
        return overall = player_support_function->setRBLBRatings();
    else if(position == "DM")
        return overall = player_support_function->setDMRatings();
    else if(position == "CM")
        return overall = player_support_function->setCMRatings();
    else if(position == "LM" || position == "RM")
        return overall = player_support_function->setRMLMRatings();
    else if(position == "AM")
        return overall = player_support_function->setAMRatings();
    else if(position == "RW" || position == "LW")
        return overall = player_support_function->setRWLWRatings();
    else if(position =="SS")
        return overall = player_support_function->setSSRatings();
    else if(position == "CF")
        return overall = player_support_function->setCFRatings();
    else
        return 0;
}

void Player::staminaDecreaser(QVector<Player> &player, int id)
{
    double RATE, RATE2, RATE3;


    int pressing = container->teams[id].getPressing();
    qDebug() <<  container->teams[id].getName() << " " << pressing;

    if(pressing < 20)
    {
        RATE = 0.017;
        RATE2 = 0.029;
        RATE3 = 0.022;
    }
    if(pressing >= 20 && pressing < 40)
    {
        RATE = 0.015;
        RATE2 = 0.027;
        RATE3 = 0.018;
    }

    if(pressing >= 40 && pressing < 60)
    {
        RATE = 0.013;
        RATE2 = 0.025;
        RATE3 = 0.015;
    }
    else if(pressing >= 60 && pressing < 80)
    {
        RATE = 0.011;
        RATE2 = 0.024;
        RATE3 = 0.013;
    }
    else if(pressing >= 80)
    {
        RATE = 0.009;
        RATE2 = 0.022;
        RATE3 = 0.011;
    }

    for(int i = 0; i < 11; ++i)
    {
        if(player[i].stamina > 1)
        {
            if(player[i].getPosition() == "GK")
                player[i].stamina -= 1/(player[i].endurance * RATE2);
            else if(player[i].getPosition() == "CB")
                player[i].stamina -= 1/(player[i].endurance * RATE3);
            else
                player[i].stamina -= 1/(player[i].endurance * RATE);
        }
    }
}

void Player::playerRecovery(QVector<Player> &player)
{
    for(int i = 0; i < player.size(); ++i)
    {
        if(player[i].stamina < 100)
        {
            if(player[i].age < 18)
                player[i].stamina += 40;
            else if(player[i].age >= 18 && player[i].age < 21)
                player[i].stamina += 35;
            else if(player[i].age >= 21 && player[i].age < 26)
                player[i].stamina += 30;
            else if(player[i].age >= 26 && player[i].age < 29)
                player[i].stamina += 25;
            else if(player[i].age >= 29 && player[i].age < 32)
                player[i].stamina += 20;
            else if(player[i].age >= 32)
                player[i].stamina += 15;
        }
        if(player[i].stamina > 100)
            player[i].stamina = 100;

    }
}

void Player::setPlayerSupportFunction()
{
    player_support_function = new PlayerSupportFunction(this);
    player_support_function->setSupportFunction();
}
double Player::calcEnergy()
{
   return rateEnergy();
}

QPixmap Player::getFoto() const
{
    return foto;
}

void Player::setFoto(const QPixmap &value)
{
    foto = value;
}

QString Player::getFotoPath() const
{
    return foto_path;
}

void Player::setFotoPath(const QString &value)
{
    foto_path = value;
}

void Player::swapPlayer(Player &p1, Player &p2)
{
    qSwap(p1.id, p2.id);
    qSwap(p1.fname, p2.fname);
    qSwap(p1.lname, p2.lname);
    qSwap(p1.nationality, p2.nationality);
    qSwap(p1.position, p2.position);
    qSwap(p1.age, p2.age);
    qSwap(p1.gkeeper, p2.gkeeper);
    qSwap(p1.defence, p2.defence);
    qSwap(p1.midfield, p2.midfield);
    qSwap(p1.attack, p2.attack);
    qSwap(p1.tackle, p2.tackle);
    qSwap(p1.technik, p2.technik);
    qSwap(p1.shot, p2.shot);
    qSwap(p1.pass, p2.pass);
    qSwap(p1.header, p2.header);
    qSwap(p1.speed, p2.speed);
    qSwap(p1.endurance, p2.endurance);
    qSwap(p1.goals, p2.goals);
    qSwap(p1.stamina, p2.stamina);
    qSwap(p1.overall, p2.overall);
    qSwap(p1.shot_temp, p2.shot_temp);
    qSwap(p1.number, p2.number);
    qSwap(p1.first_team, p2.first_team);
    qSwap(p1.foto, p2.foto);
    qSwap(p1.foto_path, p2.foto_path);
}

double Player::rateEnergy()
{
    double rate = 0;
    
    if(stamina <= 100 && stamina > 90)
        return rate = 1;
    else if(stamina <= 90 && stamina > 80)
        return rate = 0.99;
    else if(stamina <= 80 && stamina > 70)
        return rate = 0.98;
    else if(stamina <= 70 && stamina > 60)
        return rate = 0.97;
    else if(stamina <= 60 && stamina > 50)
        return rate = 0.96;
    else if(stamina <= 50 && stamina > 40)
        return rate = 0.95;
    else if(stamina <= 40 && stamina > 30)
        return rate = 0.94;
    else if(stamina <= 30 && stamina > 20)
        return rate = 0.93;
    else if(stamina <= 20 && stamina > 10)
        return rate = 0.92;
    else if(stamina <= 10 && stamina >= 0)
        return rate = 0.91;

    return 0;
}

