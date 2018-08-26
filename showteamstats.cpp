#include <QDebug>
#include "showteamstats.h"
#include "ui_showteamstats.h"

extern Container *container;

ShowTeamStats::ShowTeamStats(QWidget *parent, int i) :
    QDialog(parent),
    ui(new Ui::ShowTeamStats)
{
    //setAttribute(Qt::WA_TranslucentBackground);
    id = i;
    setWindowFlags(Qt::WindowTitleHint);
    ui->setupUi(this);
    setGraphics();
}

ShowTeamStats::~ShowTeamStats()
{
    delete ui;
}

void ShowTeamStats::setGraphics()
{
    ui->showTeamFrame->setStyleSheet("background-color: rgba(255 , 255, 255, 10);");

    ui->teamname->setStyleSheet("background-color: rgba(0 , 0, 255, 0);");
    ui->gkLabel->setStyleSheet("background-color: rgba(0 , 0, 255, 0);");
    ui->defLabel->setStyleSheet("background-color: rgba(0 , 0, 255, 0);");
    ui->midLabel->setStyleSheet("background-color: rgba(0 , 0, 255, 0);");
    ui->atackLabel->setStyleSheet("background-color: rgba(0 , 0, 255, 0);");
    ui->overallLabel->setStyleSheet("background-color: rgba(0 , 0, 255, 0);");

    ui->gkProgress->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(0,0,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  );

    ui->defProgress->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(0,0,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  );
    ui->midProgress->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(0,0,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  );
    ui->attProgress->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(0,0,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  );
    ui->overallProgress->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(0,0,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  );

}

void ShowTeamStats::showStats()
{
    ui->teamname->setText(container->teams[id].getName() + " " + container->teams[id].getCity());
    container->functions->setIcon(container->teams[id].getLogo(), ui->logo, 120, 120);

   // int average = (team->teamDefenceEnergy(container->player[id], container->teams[id].getFormation()) +
   //               team->teamMidfieldEnergy(container->player[id], container->teams[id].getFormation()) +
   //               team->teamAttackEnergy(container->player[id], container->teams[id].getFormation())) / 3;

    ui->gkProgress->setValue(team->teamGoalkeeperEnergy(container->teams[id].getPlayer()));
    ui->defProgress->setValue(team->teamDefenceEnergy(container->teams[id].getPlayer(), container->teams[id].getFormation()));
    ui->midProgress->setValue(team->teamMidfieldEnergy(container->teams[id].getPlayer(), container->teams[id].getFormation()));
    ui->attProgress->setValue(team->teamAttackEnergy(container->teams[id].getPlayer(), container->teams[id].getFormation()));
    ui->overallProgress->setValue(team->teamStrengthEnergy(container->teams[id].getPlayer(), container->teams[id].getFormation()));
}

void ShowTeamStats::table()
{

}




