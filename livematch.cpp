#include <QMessageBox>
#include <algorithm>
#include <qalgorithms.h>
#include "livematch.h"
#include "ui_livematch.h"
#include "contextmenu.h"

extern Container *container;

LiveMatch::LiveMatch(QWidget *parent, int ho, int aw) :
    QDialog(parent),
    ui(new Ui::LiveMatch)
{
    home = ho;
    away = aw;

    home_team_power = away_team_power = 0;
    home_amount = away_amount = 0;

    ui->setupUi(this);
    this->showFullScreen();

    container->matchAlgo->setAtributes(home, away);
    container->matchAlgo->setLiveMatch(true);

    setGraphic();
    matchProgress();

}
LiveMatch::~LiveMatch()
{
    delete ui;
}

void LiveMatch::matchProgress()
{
    ui->hometeam->setText(container->teams[home].getName() + " " +
                          container->teams[home].getCity());
    ui->awayteam->setText(container->teams[away].getName() + " " +
                          container->teams[away].getCity());

    for(clock = 0; clock <= 90; ++clock)
    {
        displayMatchStats();
        setParameters();
        container->matchAlgo->setParameters();
        container->matchAlgo->setClock(clock);
        container->matchAlgo->shotOrNot();
        commentary();
        computerStrategy();

        if(clock == 45)
        {
           UserSquad squad(0, true);
           squad.exec();
        }
    }
    container->matchAlgo->setStatistic();
    container->artificial->resetVariable();
}

void LiveMatch::setParameters()
{
    container->functions->delay(500);
    // player->staminaDecreaser(container->teams[home].getPlayer(), home);
    // player->staminaDecreaser(container->teams[away].getPlayer(), away);
    ui->lcdNumber->display(clock);
    possessionStatusBar();
}

void LiveMatch::setGraphic()
{

    QPixmap bkgnd = container->teams[home].getStadium().getFoto();

    container->functions->setBackground(this, bkgnd);;

    ui->homelist->setFrameShape(QFrame::NoFrame);
    ui->awaylist->setFrameShape(QFrame::NoFrame);

    setStyleSheet("QListWidget {background-color: transparent;}");

   // ui->lcdNumber->setStyleSheet("color:rgb(0, 0, 255);");

    ui->progHomeShot->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  "QProgressBar::chunk{"
                                  "background-color: rgba(0, 255, 0, 150);"
                                  "}");

    ui->progAwayShot->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  "QProgressBar::chunk{"
                                  "background-color: rgba(0, 0, 255, 150);"
                                  "}");

    ui->progHomeShotTarget->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  "QProgressBar::chunk{"
                                  "background-color: rgba(0, 255, 0, 150);"
                                  "}");

    ui->progAwayShotTarget->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  "QProgressBar::chunk{"
                                  "background-color: rgba(0, 0, 255, 150);"
                                  "}");

    ui->progHomePossession->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  "QProgressBar::chunk{"
                                  "background-color: rgba(0, 255, 0, 150);"
                                  "}");

    ui->progAwayPossession->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  "QProgressBar::chunk{"
                                  "background-color: rgba(0, 0, 255, 150);"
                                  "}");

    ui->progHomePossession_2->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  "QProgressBar::chunk{"
                                  "background-color: rgba(0, 255, 0, 150);"
                                  "}");

    ui->progAwayPossession_2->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  "QProgressBar::chunk{"
                                  "background-color: rgba(0, 0, 255, 150);"
                                  "}");


    ui->homebackground->setStyleSheet("background-color: rgba(255, 255, 255, 70);");
    ui->statsbackground->setStyleSheet("background-color: rgba(255, 255, 255, 70);");
    ui->awaybackground->setStyleSheet("background-color: rgba(255, 255, 255, 70);");
    ui->clockbackground->setStyleSheet("background-color: rgba(255, 255, 255, 70);");
    ui->comentarybackground->setStyleSheet("background-color: rgba(255, 255, 255, 70);");

    ui->pause->setStyleSheet("background-color: rgba(255, 255, 255, 70);");
    ui->squad->setStyleSheet("background-color: rgba(255, 255, 255, 70);");
    ui->back->setStyleSheet("background-color: rgba(255, 255, 255, 70);");

    ui->lcdNumber->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->hometeam->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awayteam->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homescore->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awayscore->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->homelist->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homestrikes->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->hometarget->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homegk->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homedef->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homemid->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homeatack->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homespd->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->hometech->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homedefensive->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homeofensive->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homeenergy->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homestrength->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homepossession->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->homepossession_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->awaylist->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaystrikes->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaytarget->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaygk->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaydef->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaymid->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awayattack->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awayspd->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaytech->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaydefensive->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awayofensive->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awayenergy->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaystrength->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaypossession->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->awaypossession_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");


    ui->strike->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->ontarget->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->gk->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->def->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->mid->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->atack->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->spd->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tech->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->ofen->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->def_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->energy->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->stren->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->possession->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->possession_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->action->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->teamaction->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->coments->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->shottemp->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->result->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->action->clear();
    ui->teamaction->clear();
    ui->coments->clear();
    ui->shottemp->clear();
    ui->result->clear();
}

void LiveMatch::displayMatchStats()
{
    int home_pressing = container->teams[home].getPressing();
    int away_pressing = container->teams[away].getPressing();

    int home_tackle = container->teams[home].teamTackleEnergy(container->teams[home].getPlayer(), home_pressing);
    int away_tackle = container->teams[away].teamTackleEnergy(container->teams[away].getPlayer(), away_pressing);

    int difference = container->matchAlgo->getDifference();

    home_team_power = container->matchAlgo->getHomeTeamPower() + home_tackle;
    away_team_power = container->matchAlgo->getAwayTeamPower() + away_tackle;

    ui->dif->setNum(difference);

    ui->homepower->setNum(container->matchAlgo->getHomeTeamPower());
    ui->awaypower->setNum(container->matchAlgo->getAwayTeamPower());

    ui->homescore->setNum(container->matchAlgo->getHomeScore());
    ui->homestrikes->setNum(container->matchAlgo->getHomeShots());
    ui->hometarget->setNum(container->matchAlgo->getHomeTarget());

    ui->homegk->setNum(team->teamGoalkeeperEnergy(container->teams[home].getPlayer()));
    ui->homedef->setNum(team->teamDefenceEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation()));
    ui->homemid->setNum(team->teamMidfieldEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation()));
    ui->homeatack->setNum(team->teamAttackEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation()));
    ui->homespd->setNum(team->teamSpeedEnergy(container->teams[home].getPlayer()));
    ui->hometech->setNum(team->teamTechnickEnergy(container->teams[home].getPlayer()));
    ui->homeofensive->setNum(team->teamOffensiveEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation()));
    ui->homedefensive->setNum(team->teamDefensiveEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation()));
    ui->homeenergy->setNum(team->teamEnergy(container->teams[home].getPlayer()));
    ui->homestrength->setNum(team->teamStrengthEnergy(container->teams[home].getPlayer(), container->teams[home].getFormation()));

    ui->awayscore->setNum(container->matchAlgo->getAwayScore());
    ui->awaystrikes->setNum(container->matchAlgo->getAwayShots());
    ui->awaytarget->setNum(container->matchAlgo->getAwayTargrt());

    ui->awaygk->setNum(team->teamGoalkeeperEnergy(container->teams[away].getPlayer()));
    ui->awaydef->setNum(team->teamDefenceEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation()));
    ui->awaymid->setNum(team->teamMidfieldEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation()));
    ui->awayattack->setNum(team->teamAttackEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation()));
    ui->awayspd->setNum(team->teamSpeedEnergy(container->teams[away].getPlayer()));
    ui->awaytech->setNum(team->teamTechnickEnergy(container->teams[away].getPlayer()));
    ui->awayofensive->setNum(team->teamOffensiveEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation()));
    ui->awaydefensive->setNum(team->teamDefensiveEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation()));
    ui->awayenergy->setNum(team->teamEnergy(container->teams[away].getPlayer()));
    ui->awaystrength->setNum(team->teamStrengthEnergy(container->teams[away].getPlayer(), container->teams[away].getFormation()));

    ui->homeTackle->setNum(container->teams[home].teamTackleEnergy(container->teams[home].getPlayer(), home_pressing));
    ui->awayTackle->setNum(container->teams[away].teamTackleEnergy(container->teams[away].getPlayer(), away_pressing));
}

void LiveMatch::shotsStatusBar()
{
    const int PERCENT = 100;

    int home_shots_progress, away_shots_progress;
    int home_shots = container->matchAlgo->getHomeShots();
    int away_shots = container->matchAlgo->getAwayShots();

    home_shots_progress = (home_shots * PERCENT)/(away_shots + home_shots);
    away_shots_progress = (away_shots * PERCENT)/(away_shots + home_shots);

    ui->progHomeShot->setValue(home_shots_progress);
    ui->progAwayShot->setValue(away_shots_progress);
}

void LiveMatch::shotsOnTargetStatusBar()
{
    const int PERCENT = 100;

    int home_shots_progress_target, away_shots_progress_target;
    int home_target = container->matchAlgo->getHomeTarget();
    int away_target = container->matchAlgo->getAwayTargrt();

    home_shots_progress_target = (home_target * PERCENT)/(away_target + home_target);
    away_shots_progress_target = (away_target * PERCENT)/(away_target + home_target);

    ui->progHomeShotTarget->setValue(home_shots_progress_target);
    ui->progAwayShotTarget->setValue(away_shots_progress_target);
}

void LiveMatch::possessionStatusBar()
{
    const int PERCENT = 101;

    int border = container->functions->randInt(1, 3);

    double home_pressing = container->teams[home].getPressing();
    double away_pressing = container->teams[away].getPressing();

    int home_possession_progress, away_possession_progress, home_possession_progress_2, away_possession_progress_2;
    double home_possession, away_possession;

    int home_amount_temp, away_amount_temp;

    home_possession = home_team_power;
    away_possession = away_team_power;

    home_pressing /= 55;
    away_pressing /= 55;

    home_possession *= home_pressing + border;
    away_possession *= away_pressing + border;

    home_possession_progress = (home_possession * PERCENT)/(home_possession + away_possession);
    away_possession_progress = (away_possession * PERCENT)/(home_possession + away_possession);

    ui->homepossession->setNum(home_possession_progress);
    ui->awaypossession->setNum(away_possession_progress);

    ui->progHomePossession->setValue(home_possession_progress);
    ui->progAwayPossession->setValue(away_possession_progress);

    home_amount += home_possession;
    away_amount += away_possession;

    home_amount_temp = home_amount;
    away_amount_temp = away_amount;

    if(clock > 0)
    {
        home_amount_temp /= clock;
        away_amount_temp /= clock;
    }

    home_possession_progress_2 = (home_amount_temp * PERCENT)/(home_amount_temp + away_amount_temp);
    away_possession_progress_2= (away_amount_temp * PERCENT)/(home_amount_temp + away_amount_temp);

    ui->progHomePossession_2->setValue(home_possession_progress_2);
    ui->progAwayPossession_2->setValue(away_possession_progress_2);

    ui->homepossession_2->setNum(home_possession_progress_2);
    ui->awaypossession_2->setNum(away_possession_progress_2);
}

void LiveMatch::attackLevel()
{


}

void LiveMatch::computerStrategy()
{
    int home_score = container->matchAlgo->getHomeScore();
    int away_score = container->matchAlgo->getAwayScore();

    container->artificial->setStrategy(clock, home_score, away_score);

    container->artificial->changePlayer();                             // potrrzebny obiekt to inicjacji zmiennych w konstruktorze
}

void LiveMatch::commentary()
{
    ui->action->setText(container->matchAlgo->getAction());
    ui->teamaction->setText(container->matchAlgo->getTeamName());
    ui->coments->setText(container->matchAlgo->getStrikersName());
    ui->result->setText(container->matchAlgo->getComentary());

    if(container->matchAlgo->getStartDisplay() == true)
        container->functions->delay(2000);

    if(container->matchAlgo->getHomeGoalFlag() == true)
        ui->homelist->addItem(container->matchAlgo->getHomeStriker());

    if(container->matchAlgo->getAwayGoalFlag() == true)
        ui->awaylist->addItem(container->matchAlgo->getAwayStriker());

    container->matchAlgo->clearVariables();
    container->matchAlgo->setStartDisplay(false);
    container->matchAlgo->setHomeGoalFlag(false);
    container->matchAlgo->setAwayGoalFlag(false);
}

void LiveMatch::on_back_clicked()
{
    LiveMatch::close();
}

void LiveMatch::on_pause_clicked()
{
    //QMessageBox::information(this, "Pauza", "Nacisnij aby wznowic");
    ContextMenu contextmenu(0, "KONTYNUACJA");
    contextmenu.exec();
}
void LiveMatch::on_squad_clicked()
{
    container->functions->delay(100);
    UserSquad squad(0, true);
    squad.exec();
}
