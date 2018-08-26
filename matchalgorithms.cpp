#include "matchalgorithms.h"
#include <QDebug>

extern Container *container;

MatchAlgorithms::MatchAlgorithms()
{

}

void MatchAlgorithms::setClock(int clock)
{
    this->clock = clock;
}

void MatchAlgorithms::setAtributes(int ho, int aw)
{
    home = ho;
    away = aw;
    home_shots = away_shots = home_target = away_target = 0;
    home_score = away_score = 0;
    home_team_power = away_team_power = 0;
    live_match = false;
    home_goal_flag = false;
    away_goal_flag = false;
}

void MatchAlgorithms::setParameters()
{
    int home_pressing = container->teams[home].getPressing();
    int away_pressing = container->teams[away].getPressing();

    int home_tackle = container->teams[home].teamTackleEnergy(container->teams[home].getPlayer(), home_pressing);
    int away_tackle = container->teams[away].teamTackleEnergy(container->teams[away].getPlayer(), away_pressing);

    container->functions->delay(10);

    player->staminaDecreaser(container->teams[home].getPlayer(), home);
    player->staminaDecreaser(container->teams[away].getPlayer(), away);

    home_team_power = team->teamOffensiveEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation()) -
                      team->teamDefensiveEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation());
    away_team_power = team->teamOffensiveEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation()) -
                      team->teamDefensiveEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation());

    home_team_power += home_tackle;
    away_team_power += away_tackle;

}

void MatchAlgorithms::shotOrNot()
{
    difference = home_team_power - away_team_power ;  // sila gospodarz - jesli dodatnia to mocniejszty jesli ujemna to slabszy

   if(difference > 20)
      difference = 20;
   else if(difference < - 20)
      difference = -20;

    int range = container->functions->randInt(1,100);


    switch(difference)
    {
            case -20:
            case -19:
            case -18:
            case -17:
            case -16:
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
                     if(range >= 0 and range <= 5)
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
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
                    if(range >= 82 and range <= 100)
                        strikesHome();
                    if(range >= 0 and range <= 6)
                        strikesAway();
            break;
    }
}

void MatchAlgorithms::strikesAway()
{
    away_shots++;

    if(live_match == true)
        getStrikerLive(away, false);
    else
        getStriker(away, false);
}

void MatchAlgorithms::strikesHome()
{
    home_shots++;

    if(live_match == true)
        getStrikerLive(home, true);
    else
        getStriker(home, true);
}

void MatchAlgorithms::strikerValue(int hoa)
{
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
}

void MatchAlgorithms::getStriker(int hoa, bool locker)
{
   strikerValue(hoa);

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

               }
            }
       }
   }

}

void MatchAlgorithms::getStrikerLive(int hoa , bool locker)
{
    strikerValue(hoa);

    int max = 0;
    QString fname;
    QString lname;
    QString position;

    action = "AKCJE PRZEPROWADZA ";
    team_name = container->teams[hoa].getName() + " " + container->teams[hoa].getCity() ;
    start_display = true;

    for(int i = 1; i <= 10; ++i)                                 // ustale ktory zawodnik ma najwieksze szanse na oddanie strzalu
    {
         if(container->teams[hoa].getPlayer()[i].getShotTemp() > max)
         {
             max = container->teams[hoa].getPlayer()[i].getShotTemp();
             fname = container->teams[hoa].getPlayer()[i].getFname();
             lname = container->teams[hoa].getPlayer()[i].getLname();
             position = container->teams[hoa].getPlayer()[i].getPosition();

             strikers_name = "Strzela " + fname + " " + lname + " " + position;
         }
    }

    int accuracy = 0;
    int range = 0;

    bool rep_prev = false;    // zapobiega powtornemu wskazaniu strzelca kiedy shottemp jest taki sam

    for(int i = 1; i <= 10; i++)
    {
         if(container->teams[hoa].getPlayer()[i].getShotTemp() == max && rep_prev == false)
         {
             rep_prev = true;

             container->teams[hoa].getPlayer()[i].setShotTemp(0);
             accuracy =  container->functions->randInt(1,99);

             if(container->teams[hoa].getPlayer()[i].getPosition() == "CB")
                 range += container->teams[hoa].getPlayer()[i].getShotTemp() +
                     container->teams[hoa].getPlayer()[i].getHeader() + accuracy;
             else
                 range += container->teams[hoa].getPlayer()[i].getShotTemp() +
                     container->teams[hoa].getPlayer()[i].getShot() + accuracy;


             if(range <= 100)
             {
                 comentary = "WYSOKO NAD BRAMKA";
             }
             if(range > 100 && range <= 120)
             {
                 comentary = "OBOK BRAMKI";
             }
             if(range > 120 && range <= 125 )
             {
                 comentary = "BRAMKARZ LAPIE PILKE";

                 if(locker == true)
                 {
                     home_target++;
                 }
                 else
                     away_target++;

             }
             if(range > 125 && range <= 130 )
             {
                 comentary = "STRZAL ZABLOKOWANY";
             }
             if(range > 130 && range <= 140 )
             {
                 comentary = "BRAMKARZ WYBIJA PILKE NA RZUT ROZNY";

                 if(locker == true)
                 {
                     home_target++;
                 }
                 else
                     away_target++;

             }
             if(range > 140 && range <= 150 )
             {
                  if(range > 145 && range <= 147)
                  {
                      comentary = "BRAMKARZ SPAROWAŁ PIŁKE NA SŁUPEK";
                  }
                  if(range > 148 && range <= 150)
                  {
                      comentary = "BRAMKARZ SPAROWAŁ PIŁKE NA POPRZECZKE";
                  }
                  else
                  {
                      comentary = "BRAMKARZ WYBIJA PILKE Z NAJWIEKSZYM TRUDEM";
                  }

                 if(locker == true)
                 {
                     home_target++;
                 }
                 else
                     away_target++;

             }
             if(range > 150 && range <= 155)
             {
                 comentary = "SLUPEK";
             }
             if(range > 155 && range <= 160)
             {
                 comentary = "POPRZECZKA";
             }
             if(range > 160)
             {
                comentary = "GOOOOL!!!";
                if(locker == true)
                {
                    home_goal_flag = true;

                    home_target++;
                    home_score++;
                    container->teams[hoa].getPlayer()[i].setGoal();

                    home_striker = container->teams[hoa].getPlayer()[i].getFname() + " "
                                             + container->teams[hoa].getPlayer()[i].getLname() + " "
                                             + QString::number(clock + 1);

                    container->teams[hoa].setStrikerList( container->teams[hoa].getPlayer()[i].getFname() + " "
                                                         + container->teams[hoa].getPlayer()[i].getLname() + "  "
                                                         + QString::number(clock + 1));
                }
                else
                {
                    away_goal_flag = true;

                    away_target++;
                    away_score++;
                    container->teams[hoa].getPlayer()[i].setGoal();

                    away_striker = container->teams[hoa].getPlayer()[i].getFname() + " "
                                              + container->teams[hoa].getPlayer()[i].getLname() + " "
                                              + QString::number(clock + 1);

                    container->teams[hoa].setStrikerList( container->teams[hoa].getPlayer()[i].getFname() + " "
                                                         + container->teams[hoa].getPlayer()[i].getLname() + "  "
                                                         + QString::number(clock + 1));
                }

             }
        }
    }
}

void MatchAlgorithms::setStatistic()
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

void MatchAlgorithms::clearVariables()
{
    comentary.clear();
    action.clear();
    strikers_name.clear();
    team_name.clear();
    home_striker.clear();
    away_striker.clear();
}
