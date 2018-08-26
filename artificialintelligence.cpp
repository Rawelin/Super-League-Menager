#include "artificialintelligence.h"
#include <QDebug>

extern Container *container;

ArtificialIntelligence::ArtificialIntelligence()
{
    home = false;
    away = false;
    home_sub = away_sub = 3;
    home_stamina_limit = away_stamina_limit = 40;
}

void ArtificialIntelligence::setStrategy(int clock, int home_score, int away_score)
{
    if(home == true)
    {
        if(away_score > home_score)
            container->teams[id].setPressing(80);
        if(away_score < home_score)
            container->teams[id].setPressing(30);
        if(away_score == home_score)
        {
            if(clock > 35)
                container->teams[id].setPressing(80);
            if(clock > 50)
                container->teams[id].setPressing(default_pressing);
        }
    }

    if(away == true)
    {
        if(away_score < home_score)
            container->teams[id].setPressing(80);
        if(away_score > home_score)
            container->teams[id].setPressing(30);
        if(away_score == home_score)
        {
            if(clock > 35)
                container->teams[id].setPressing(80);
            if(clock > 50)
                container->teams[id].setPressing(default_pressing);
        }
    }

    if(clock > 90)
        container->teams[id].setPressing(default_pressing);

  //  qDebug() << home_score;
  //  qDebug() << away_score;

}

void ArtificialIntelligence::changePlayer()
{
    int team_size = container->teams[id].getPlayer().size();

    for(int i = 0; i < 11; i++)
    {
        for(int j = 11; j < team_size; j++)
        {
            if(container->teams[id].getPlayer()[i].getStamina() < home_stamina_limit)
            {
                if(container->teams[id].getPlayer()[i].getPosition() == container->teams[id].getPlayer()[j].getPosition())
                {
                   if(home_sub > 0)
                   {
                      Player::swapPlayer(container->teams[id].getPlayer()[i], container->teams[id].getPlayer()[j]);
                      home_sub--;
                      home_stamina_limit -= 8;
                      qDebug() << home_sub;
                      qDebug() << container->teams[id].getPlayer()[i].getLname();
                   }
                }
            }
        }
    }

}

void ArtificialIntelligence::changePlayerSimulation(int ids, bool flag)
{
    int team_size = container->teams[ids].getPlayer().size();

    if(flag == true)
    {
        for(int i = 0; i < 11; i++)
        {
            for(int j = 11; j < team_size; j++)
            {
                if(container->teams[ids].getPlayer()[i].getStamina() < home_stamina_limit)
                {
                    if(container->teams[ids].getPlayer()[i].getPosition() == container->teams[ids].getPlayer()[j].getPosition())
                    {
                       if(home_sub > 0)
                       {
                          Player::swapPlayer(container->teams[ids].getPlayer()[i], container->teams[ids].getPlayer()[j]);
                          home_sub--;
                          home_stamina_limit -= 8;
                          qDebug() << home_sub;
                          qDebug() << container->teams[ids].getPlayer()[i].getLname();
                      }
                    }
                }
            }
        }
    }

    if(flag == false)
    {
        for(int i = 0; i < 11; i++)
        {
            for(int j = 11; j < team_size; j++)
            {
                if(container->teams[ids].getPlayer()[i].getStamina() < away_stamina_limit)
                {
                    if(container->teams[ids].getPlayer()[i].getPosition() == container->teams[ids].getPlayer()[j].getPosition())
                    {
                       if(away_sub > 0)
                       {
                          Player::swapPlayer(container->teams[ids].getPlayer()[i], container->teams[ids].getPlayer()[j]);
                          away_sub--;
                          away_stamina_limit -= 8;
                          qDebug() << away_sub;
                          qDebug() << container->teams[ids].getPlayer()[i].getLname();
                       }
                    }
                }
            }
        }
    }



}

void ArtificialIntelligence::sortPlayers()
{
    int team_size = container->teams[id].getPlayer().size();

    for(int i = 0; i < team_size; i++)
    {
        for(int j = 0; j < team_size; j++)
        {
            //if(container->teams[id].getPlayer()[i].getEnergyOverall())
        }
    }
}

void ArtificialIntelligence::resetVariable()
{
    home_sub = away_sub = 3;
    home_stamina_limit = away_stamina_limit = 33;
}
