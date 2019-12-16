#include "matchsimulation.h"
#include <QDebug>

extern Container *container;

MatchSimulation::MatchSimulation(int ho, int aw)
{
    home = ho;
    away = aw;
    home_shots = away_shots = home_target = away_target = 0;
    home_team_power = away_team_power = 0;
    home_score = away_score = 0;

    container->matchAlgoritm->setAtributes(home, away);
}

void MatchSimulation::matchProgress()
{
    for(clock = 0; clock <= 90; ++clock)
    {
       //setParameters();
       container->matchAlgoritm->setParameters();

       container->matchAlgoritm->setClock(clock);
       container->matchAlgoritm->shotOrNot();

       container->artificialInteligence->changePlayerSimulation(home, true);
       container->artificialInteligence->changePlayerSimulation(away, false);
      //shotOrNot();
    }
       container->matchAlgoritm->setStatistic();
       container->artificialInteligence->resetVariable();
   // setStatistic();
}

void MatchSimulation::setParameters()
{
    container->functions->delay(10);

    player->staminaDecreaser(container->teams[home].getPlayer(), home);
    player->staminaDecreaser(container->teams[away].getPlayer(), away);

    home_team_power = team->teamOffensiveEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation()) -
                      team->teamDefensiveEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation());
    away_team_power = team->teamOffensiveEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation()) -
                      team->teamDefensiveEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation());

}

void MatchSimulation::shotOrNot()
{
    int difference = home_team_power - away_team_power ;  // sila gospodarz - jesli dodatnia to mocniejszty jesli ujemna to slabszy

    int range = container->functions->randInt(1,100);

    switch(difference)
        {
            case -15:
            case -14:
            case -13:
            case -12:
            case -11:
            case -10:
            case -9:
                    if(range >= 93 and range <= 100)
                        strikesHome();
                    if(range >= 0 and range <= 18)
                        strikesAway();
            break;
            case -8:
                     if(range >= 92 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 17)
                         strikesAway();
            break;
            case -7:
                     if(range >= 92 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 16)
                         strikesAway();
            break;
            case -6:
                     if(range >= 91 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 15)
                         strikesAway();
            break;
            case -5:
                     if(range >= 91 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 14)
                        strikesAway();
            break;
            case -4:
                     if(range >= 91 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 13)
                         strikesAway();
            break;
            case -3:
                     if(range >= 90 and range <= 100)
                        strikesHome();
                     if(range >= 0 and range <= 12)
                         strikesAway();
            break;
            case -2:
                     if(range >= 90 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 11)
                         strikesAway();
            break;
            case -1:
                     if(range >= 90 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 10)
                         strikesAway();
            break;
            case 0:
                     if(range >= 93 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 3)
                         strikesAway();
            break;
            case 1:
                     if(range >= 90 and range <= 100)
                        strikesHome();
                     if(range >= 0 and range <= 9)
                        strikesAway();
            break;
            case 2:
                     if(range >= 89 and range <= 100)
                        strikesHome();
                     if(range >= 0 and range <= 9)
                        strikesAway();
            break;
            case 3:
                     if(range >= 88 and range <= 100)
                        strikesHome();
                     if(range >= 0 and range <= 9)
                        strikesAway();
            break;
            case 4:

                     if(range >= 87 and range <= 100)
                        strikesHome();
                     if(range >= 0 and range <= 8)
                        strikesAway();
            break;
            case 5:
                     if(range >= 86 and range <= 100)
                         strikesHome();
                     if(range >= 0 and range <= 8)
                         strikesAway();

            break;
            case 6:
                     if(range >= 85 and range <= 100)
                        strikesHome();
                     if(range >= 0 and range <= 8)
                        strikesAway();
            break;
            case 7:
                     if(range >= 84 and range <= 100)
                        strikesHome();
                     if(range >= 0 and range <= 8)
                         strikesAway();
            break;
            case 8:
                    if(range >= 83 and range <= 100)
                        strikesHome();
                    if(range >= 0 and range <= 7)
                        strikesAway();
            break;
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                    if(range >= 82 and range <= 100)
                        strikesHome();
                    if(range >= 0 and range <= 6)
                        strikesAway();
            break;
    }
}

void MatchSimulation::strikesHome()
{
    home_shots++;
    getStriker(home, true);
}

void MatchSimulation::strikesAway()
{
    away_shots++;
    getStriker(away, false);
}

void MatchSimulation::getStriker(int hoa, bool locker)
{
    int striker = 0;

    for(int i = 0; i < 11; i++)
    {
        if(container->teams[hoa].getPlayer()[i].getAttack() >= 95)
        {
            striker =  container->functions->randInt(83,99);
            container->teams[hoa].getPlayer()[i].setShotTemp(striker);
        }
        if(container->teams[hoa].getPlayer()[i].getAttack() >= 90 && container->teams[hoa].getPlayer()[i].getAttack() < 95)
        {
            striker = container->functions->randInt(81,99);
            container->teams[hoa].getPlayer()[i].setShotTemp(striker);
        }
        if(container->teams[hoa].getPlayer()[i].getAttack() < 90 && container->teams[hoa].getPlayer()[i].getAttack() >= 80)
        {
            striker = container->functions->randInt(80,99);
            container->teams[hoa].getPlayer()[i].setShotTemp(striker);
        }
        if(container->teams[hoa].getPlayer()[i].getAttack() < 80 && container->teams[hoa].getPlayer()[i].getAttack() >= 70)
        {
            striker = container->functions->randInt(70,99);
            container->teams[hoa].getPlayer()[i].setShotTemp(striker);
        }
        if(container->teams[hoa].getPlayer()[i].getAttack() < 70 && container->teams[hoa].getPlayer()[i].getAttack() >= 60)
        {
            striker = container->functions->randInt(60,99);;
            container->teams[hoa].getPlayer()[i].setShotTemp(striker);
        }
        if(container->teams[hoa].getPlayer()[i].getAttack() < 60 && container->teams[hoa].getPlayer()[i].getAttack() >= 50)
        {
            striker = container->functions->randInt(50,99);
            container->teams[hoa].getPlayer()[i].setShotTemp(striker);
        }
        if(container->teams[hoa].getPlayer()[i].getAttack() < 50 && container->teams[hoa].getPlayer()[i].getAttack() >= 30)
        {
             striker = container->functions->randInt(40,99);
             container->teams[hoa].getPlayer()[i].setShotTemp(striker);
        }
        if(container->teams[hoa].getPlayer()[i].getAttack() < 30)
        {
             striker = container->functions->randInt(30,99);
             container->teams[hoa].getPlayer()[i].setShotTemp(striker);
        }
   }

 //  qSort(container->player[hoa].begin(), container->player[hoa].end(),
      //   [](const Player &p1,const Player &p2){return p1.getShotTemp() > p2.getShotTemp();});

  // qDebug() << "st " << container->player[hoa][10].getLname() << " "
           // << container->player[hoa][10].getShotTemp();
   int max = 0;
   QString fname;
   QString lname;
   QString position;

   for(int i = 1; i <= 10; ++i)                                 // ustale ktory zawodnik ma najwieksze szanse na oddanie strzalu
   {
       if(container->teams[hoa].getPlayer()[i].getShotTemp() > max)
       {
           max = container->teams[hoa].getPlayer()[i].getShotTemp();
           fname = container->teams[hoa].getPlayer()[i].getFname();
           lname = container->teams[hoa].getPlayer()[i].getLname();
           position = container->teams[hoa].getPlayer()[i].getPosition();
       }
   }

  /* for(int i = 1; i <= 10; ++i)
   {
       qDebug() << container->player[hoa][i].getLname() << " "
                << container->player[hoa][i].getShotTemp();
   }
   qDebug() << "Nastepny strzal";
   qDebug() << position << " " << fname << " " << lname << " " << max;*/
   int accuracy = 0;
   int range = 0;

   bool rep_prev = false;    // zapobiega powtornemu wskazaniu strzelca kiedy shottemp jest taki sam

   for(int i = 1; i <= 10; i++)
   {
        if( container->teams[hoa].getPlayer()[i].getShotTemp() == max && rep_prev == false)
        {
            rep_prev = true;

            container->teams[hoa].getPlayer()[i].setShotTemp(0);
            accuracy =  container->functions->randInt(1,99);
            range += container->teams[hoa].getPlayer()[i].getShotTemp() +
                    container->teams[hoa].getPlayer()[i].getShot() + accuracy;

            if(range <= 100)
            {


            }
            if(range > 100 && range <= 120)
            {

            }
            if(range > 120 && range <= 125 )
            {

                if(locker == true)
                {
                    home_target++;
                }
                else
                    away_target++;
            }
            if(range > 125 && range <= 130 )
            {

            }
            if(range > 130 && range <= 140 )
            {


                if(locker == true)
                {
                    home_target++;
                }
                else
                    away_target++;
            }
            if(range > 140 && range <= 150 )
            {


                if(locker == true)
                {
                    home_target++;
                }
                else
                    away_target++;
            }
            if(range > 150 && range <= 155)
            {

            }
            if(range > 155 && range <= 160)
            {

            }
            if(range > 160)
            {


               if(locker == true)
               {
                   home_target++;
                   home_score++;
                   container->teams[hoa].getPlayer()[i].setGoal();
                   container->teams[hoa].setStrikerList( container->teams[hoa].getPlayer()[i].getFname() + " "
                                                        + container->teams[hoa].getPlayer()[i].getLname() + "  "
                                                        + QString::number(clock + 1));

               }
               else
               {
                   away_target++;
                   away_score++;
                   container->teams[hoa].getPlayer()[i].setGoal();
                   container->teams[hoa].setStrikerList(container->teams[hoa].getPlayer()[i].getFname() + " "
                                                        + container->teams[hoa].getPlayer()[i].getLname() + "  "
                                                        + QString::number(clock + 1));

                  // qDebug() << "gol " << container->player[hoa][i].getLname() << " "
                         //   << container->player[hoa][i].getShotTemp();
               }
            }
       }
   }

}

void MatchSimulation::setStatistic()
{
    if(home_score > away_score)
    {
        container->teams[home].setPoint(3);
        container->teams[home].setWin();
        container->teams[home].setGoalScored(home_score);
        container->teams[home].setGoalLost(away_score);
        container->teams[home].setRound(1);

        container->teams[away].setPoint(0);
        container->teams[away].setLost();
        container->teams[away].setGoalScored(away_score);
        container->teams[away].setGoalLost(home_score);
        container->teams[away].setRound(1);

    }
    if(home_score == away_score)
    {
        container->teams[home].setPoint(1);
        container->teams[home].setDraw();
        container->teams[home].setGoalScored(home_score);
        container->teams[home].setGoalLost(away_score);
        container->teams[home].setRound(1);

        container->teams[away].setPoint(1);
        container->teams[away].setDraw();
        container->teams[away].setGoalScored(away_score);
        container->teams[away].setGoalLost(home_score);
        container->teams[away].setRound(1);
    }
    if(home_score < away_score)
    {
        container->teams[home].setPoint(0);
        container->teams[home].setLost();
        container->teams[home].setGoalScored(home_score);
        container->teams[home].setGoalLost(away_score);
        container->teams[home].setRound(1);

        container->teams[away].setPoint(3);
        container->teams[away].setWin();
        container->teams[away].setGoalScored(away_score);
        container->teams[away].setGoalLost(home_score);
        container->teams[away].setRound(1);
    }
    container->teams[home].setScore(home_score);
    container->teams[away].setScore(away_score);
}
