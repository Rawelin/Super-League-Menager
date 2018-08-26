#include "usersquad.h"
#include "ui_usersquad.h"
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <QProgressBar>
#include <QtWidgets>

extern Container *container;

UserSquad::UserSquad(QWidget *parent, bool wpm) :
    QDialog(parent),
    ui(new Ui::UserSquad)
{
    ui->setupUi(this);
    this->showFullScreen();
    setWindowFlags(Qt::FramelessWindowHint);

    id = container->userData->getId();                           // numer skladu w vektorze 2d
    when_playing_match = wpm;
    substitutions = 3;
    taken = false;
    no_changes = false;

    ui->frame->setVisible(false);
    ui->personalFrame->setVisible(false);

    maximum_size = container->player[id].size();
    formation_number = container->teams[id].getFormation();

    setGraphic();
    attackValue(container->teams[id].getAttackLevel());

   // ui->spinBox->setMaximum(maximum_size);
   // ui->spinBox_2->setMaximum(maximum_size);
    squad();
    formationColor(formation_number);

    ui->teamname->setText(container->teams[id].getName() + " "
                          +container->teams[id].getCity());

    connect(ui->form1, SIGNAL(clicked(bool)), this, SLOT(formation442()));
    connect(ui->form2, SIGNAL(clicked(bool)), this, SLOT(formation433()));
    connect(ui->form3, SIGNAL(clicked(bool)), this, SLOT(formation352()));

    connect(ui->tableWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(take()));
    connect(ui->tableWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(personalData()));
    //connect(ui->tableWidget, SIGNAL(itemPressed(QTableWidgetItem*)),this, SLOT(put()));
    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)),this, SLOT(put()));
    connect(ui->pressingSlider, SIGNAL(valueChanged(int)), this, SLOT(pressingControler()));
    connect(ui->attackSlider, SIGNAL(valueChanged(int)), this, SLOT(attackControler()));
}

UserSquad::~UserSquad()
{
    delete ui;
}

void UserSquad::setGraphic()
{
    QPixmap bkgnd("Background/back2.jpg");
    container->functions->setBackground(this, bkgnd);

    ui->frame4->setVisible(false);

    ui->tableWidget->setFrameShape(QFrame::NoFrame);
    ui->tableWidget->setGridStyle(Qt::SolidLine);

    container->functions->setIcon(container->teams[id].getLogo(), ui->logo, 80, 80);
    container->functions->setIcon(container->teams[id].getLogo(), ui->logo2, 80, 80);

    setStyleSheet("QTableWidget {background-color: transparent;}"
                  "QHeaderView::section {background-color: transparent;}"
                  "QHeaderView {background-color: transparent;}"
                  "QTableCornerButton::section {background-color: transparent;}");


    ui->back->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->form1->setStyleSheet("background-color: rgba(255, 255, 255, 30);");
    ui->form2->setStyleSheet("background-color: rgba(255, 255, 255, 30);");
    ui->form3->setStyleSheet("background-color: rgba(255, 255, 255, 30);");
    ui->frame2->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame3->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame4->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->managerFrame->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    ui->tableWidget->horizontalHeader()->setStyleSheet("color: blue");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: blue");
    QSize icon_size(5,5);
    ui->tableWidget->verticalHeader()->setIconSize(icon_size);

    ui->personalFrame->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->realSkils->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->slash->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->difference->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->skils->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->powerskils->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->l4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l10->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l11->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l12->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l13->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l14->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l15->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l16->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l17->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l18->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l19->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->energy->setStyleSheet("background-color: rgba(255, 0, 0, 100);");
    ui->gk->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->def->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->mid->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->att->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->spd->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tech->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->offensive->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->defensive->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->str->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->gk_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->def_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->mid_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->att_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->spd_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tech_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->offensive_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->defensive_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->str_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->form->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->formation->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->change->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->changecount->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->managerName->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->pitch->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->p1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p9->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p10->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->p11->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->pressing->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pressing2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pressingDig->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pressingSlider->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->attack->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->attack2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->attackDig->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->attackSlider->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->controlFrame->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    ui->firstName->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->secondName->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pos->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->gkLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->defLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->midLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->attackLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tackleLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->techLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->shotLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->passLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->headLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->speedLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->enduranceLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->goalLab->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->energy->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->nameLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->surnameLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->positionLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->gkLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->defLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->midLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->atackLebel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tackleLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->techLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->shotLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->passLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->headlabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->speadLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->enduranceLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->goalLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->pressingSlider->setToolTip("Im większy presing tym szybciej spada stamina");

    ui->teamenergy->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  );

    ui->energy->setStyleSheet("QProgressBar"
                                  "{"
                                  "border: 1px solid transparent;"
                                  "color:rgba(255,255,255,255);"
                                  "border-radius: 5px;"
                                  "background-color: rgba(255, 255, 255, 20);"
                                  "}"
                                  );

    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_1, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_2, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_3, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_4, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_5, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_6, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_7, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_8, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_9, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_10, 50, 50);
    container->functions->setIcon(container->teams[id].getTshirt(), ui->ts_11, 50, 50);
}
void UserSquad::squad()
{
    int fila;

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setColumnWidth(0,150);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,40);
    ui->tableWidget->setColumnWidth(3,45);
    ui->tableWidget->setColumnWidth(4,40);
    ui->tableWidget->setColumnWidth(5,40);
    ui->tableWidget->setColumnWidth(6,30);
    ui->tableWidget->setColumnWidth(7,30);

    titles.clear();

    titles << "IMIE" << "NAZWISKO" << "POZ"  << "KRAJ" << "WIEK"  << "STA"
           << "OVE" << "GOL";


    ui->tableWidget->setHorizontalHeaderLabels(titles);

    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);

    ui->tableWidget->horizontalHeaderItem(0)->setToolTip("Imię");
    ui->tableWidget->horizontalHeaderItem(1)->setToolTip("Nazwisko");
    ui->tableWidget->horizontalHeaderItem(2)->setToolTip("Pozycja");
    ui->tableWidget->horizontalHeaderItem(3)->setToolTip("Kraj pochodzenia");
    ui->tableWidget->horizontalHeaderItem(4)->setToolTip("Wiek");
    ui->tableWidget->horizontalHeaderItem(5)->setToolTip("Energia");
    ui->tableWidget->horizontalHeaderItem(6)->setToolTip("Średnia umiejętności zawodnika");
    ui->tableWidget->horizontalHeaderItem(7)->setToolTip("Zdobyte gole");

    int first_team_player = 0;
    int limit = container->teams[id].getPlayer().size();

    for(int i = 0, j= 0; i < limit ; ++i, ++j)
    {

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila = ui->tableWidget->rowCount() - 1;

        ui->tableWidget->setItem(fila, NAME, new QTableWidgetItem(container->teams[id].getPlayer()[i].getFname()));
        ui->tableWidget->setItem(fila, SURNAME, new QTableWidgetItem(container->teams[id].getPlayer()[i].getLname()));
        ui->tableWidget->setItem(fila, POSITION, new QTableWidgetItem(container->teams[id].getPlayer()[i].getPosition()));
        ui->tableWidget->setItem(fila, NATIONALITY, new QTableWidgetItem(container->teams[id].getPlayer()[i].getNationality()));
        ui->tableWidget->setItem(fila, AGE, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getAge())));
        ui->tableWidget->setItem(fila, STAMINA, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getStamina())));
        ui->tableWidget->setItem(fila, OVERALL, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getOverall(i, formation_number))));
        ui->tableWidget->setItem(fila, GOALS, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getGoals())));

        for(int i = 2; i < titles.size(); ++i)
        {
            ui->tableWidget->item(j, i)->setTextAlignment(Qt::AlignCenter);
        }


        if(container->teams[id].getPlayer()[i].getFirstTeam() == 0)
        {
            if(i <= 10)
                first_team_player++;
        }
        if(container->teams[id].getPlayer()[i].getFirstTeam() == 4)
        {
            if(i <= 10)
                first_team_player--;
        }
        if(container->teams[id].getPlayer()[i].getFirstTeam() == 5)
        {
            if(i <= 10)
                first_team_player -= 2;
        }
        if(when_playing_match == false)
        {
            if(i <= 10)
            {
                container->teams[id].getPlayer()[i].setFirstTeam(0);
            }
            else
            {
                container->teams[id].getPlayer()[i].setFirstTeam(1);
            }
         //   qDebug() << i << " " << container->player[squad_number][i].getLname() << " "
         //            << container->player[squad_number][i].getFirstTeam();
        }
        if(when_playing_match == true)
        {
            ui->frame4->setVisible(true);

         //   qDebug() << i << " " << container->player[squad_number][i].getLname() << " "
         //            << container->player[squad_number][i].getFirstTeam();
         //   qDebug() << "ft: " << first_team_player;

            if(first_team_player == 11 )
            {
                substitutions = 3;
            }
            else if(first_team_player == 10)
            {
                substitutions = 2;
            }
            else if(first_team_player == 9)
            {
                substitutions = 1;

            }
            else if(first_team_player <= 8)
            {
                substitutions = 0;
            }
        }

    //    qDebug() << no_changes;

    }

    formationColor(formation_number);
    updateTeamStats();
}


void UserSquad::formationPitch(int formation)
{

    ui->p1->setText(container->teams[id].getPlayer()[0].getLname());
    ui->p2->setText(container->teams[id].getPlayer()[1].getLname());
    ui->p3->setText(container->teams[id].getPlayer()[2].getLname());
    ui->p4->setText(container->teams[id].getPlayer()[3].getLname());
    ui->p5->setText(container->teams[id].getPlayer()[4].getLname());
    ui->p6->setText(container->teams[id].getPlayer()[5].getLname());
    ui->p7->setText(container->teams[id].getPlayer()[6].getLname());
    ui->p8->setText(container->teams[id].getPlayer()[7].getLname());
    ui->p9->setText(container->teams[id].getPlayer()[8].getLname());
    ui->p10->setText(container->teams[id].getPlayer()[9].getLname());
    ui->p11->setText(container->teams[id].getPlayer()[10].getLname());


    int w = 110;
    int h = 21;

    if(formation == 1)
    {
        ui->p2->setGeometry(20, 230, w, h);
        ui->p3->setGeometry(150, 260, w, h);
        ui->p4->setGeometry(290, 260, w, h);
        ui->p5->setGeometry(420, 230, w, h);
        ui->p6->setGeometry(20, 140, w, h);
        ui->p7->setGeometry(150, 170, w, h);
        ui->p8->setGeometry(290, 170, w, h);
        ui->p9->setGeometry(420, 140, w, h);
        ui->p10->setGeometry(150, 70, w, h);
        ui->p11->setGeometry(290, 70, w, h);

        ui->ts_1->setGeometry(250, 260, 100, 100);
        ui->ts_2->setGeometry(50, 150, 100, 100);
        ui->ts_3->setGeometry(180, 180, 100, 100);
        ui->ts_4->setGeometry(320, 180, 100, 100);
        ui->ts_5->setGeometry(450, 150, 100, 100);
        ui->ts_6->setGeometry(50, 60, 100, 100);
        ui->ts_7->setGeometry(180, 90, 100, 100);
        ui->ts_8->setGeometry(320, 90, 100, 100);
        ui->ts_9->setGeometry(450, 60, 100, 100);
        ui->ts_10->setGeometry(180, -10, 100, 100);
        ui->ts_11->setGeometry(320, -10, 100, 100);
    }
    if(formation == 2)
    {
        ui->p2->setGeometry(20, 230, w, h);
        ui->p3->setGeometry(150, 260, w, h);
        ui->p4->setGeometry(290, 260, w, h);
        ui->p5->setGeometry(420, 230, w, h);
        ui->p6->setGeometry(100, 160, w, h);
        ui->p7->setGeometry(220, 190, w, h);
        ui->p8->setGeometry(340, 160, w, h);
        ui->p9->setGeometry(340, 80, w, h);
        ui->p10->setGeometry(100, 80, w, h);
        ui->p11->setGeometry(220, 60, w, h);

        ui->ts_1->setGeometry(250, 260, 100, 100);
        ui->ts_2->setGeometry(50, 150, 100, 100);
        ui->ts_3->setGeometry(180, 180, 100, 100);
        ui->ts_4->setGeometry(320, 180, 100, 100);
        ui->ts_5->setGeometry(450, 150, 100, 100);
        ui->ts_6->setGeometry(130, 80, 100, 100);
        ui->ts_7->setGeometry(250, 110, 100, 100);
        ui->ts_8->setGeometry(370, 80, 100, 100);
        ui->ts_9->setGeometry(370, 0, 100, 100);
        ui->ts_10->setGeometry(130, 0, 100, 100);
        ui->ts_11->setGeometry(250, -20, 100, 100);
    }
    if(formation == 3)
    {
        ui->p2->setGeometry(90, 260, w, h);
        ui->p3->setGeometry(220, 260, w, h);
        ui->p4->setGeometry(360, 260, w, h);
        ui->p5->setGeometry(420, 140, w, h);
        ui->p6->setGeometry(20, 140, w, h);
        ui->p7->setGeometry(150, 200, w, h);
        ui->p8->setGeometry(290, 200, w, h);
        ui->p9->setGeometry(220, 140, w, h);
        ui->p10->setGeometry(150, 70, w, h);
        ui->p11->setGeometry(290, 70, w, h);

        ui->ts_1->setGeometry(250, 260, 100, 100);


        ui->ts_2->setGeometry(120, 180, 100, 100);
        ui->ts_3->setGeometry(250, 180, 100, 100);
        ui->ts_4->setGeometry(390, 180, 100, 100);
        ui->ts_5->setGeometry(450, 60, 100, 100);
        ui->ts_6->setGeometry(50, 60, 100, 100);
        ui->ts_7->setGeometry(180, 120, 100, 100);
        ui->ts_8->setGeometry(320, 120, 100, 100);
        ui->ts_9->setGeometry(250, 60, 100, 100);
        ui->ts_10->setGeometry(180, -10, 100, 100);
        ui->ts_11->setGeometry(320, -10, 100, 100);
    }

}

void UserSquad::personalData()
{
    int difference =   container->teams[id].getPlayer()[index].getOverall(index, formation_number) -
                       container->teams[id].getPlayer()[index].getRealOveral();

    ui->frame->setVisible(true);
    ui->personalFrame->setVisible(true);

     container->functions->setLabelTextColor(ui->difference, difference);

    if(difference < 0)
    {
        ui->difference->setVisible(true);
        ui->difference->setStyleSheet("color: rgb(255, 0, 0)");
        ui->difference->setText(QString::number(difference));
    }

    else if(difference > 0)
    {
        ui->difference->setVisible(true);
        ui->difference->setStyleSheet("color: rgb(0, 255, 0)");
        ui->difference->setText("+" + QString::number(difference));
    }
    else
        ui->difference->setVisible(false);

    container->functions->setLabelTextColor(ui->pos, container->teams[id].getPlayer()[index].getPosition());
    container->functions->setLabelTextColor(ui->gkLab, container->teams[id].getPlayer()[index].getGkeeper());
    container->functions->setLabelTextColor(ui->defLab, container->teams[id].getPlayer()[index].getDefence());
    container->functions->setLabelTextColor(ui->midLab, container->teams[id].getPlayer()[index].getMidfield());
    container->functions->setLabelTextColor(ui->attackLab, container->teams[id].getPlayer()[index].getAttack());
    container->functions->setLabelTextColor(ui->tackleLab, container->teams[id].getPlayer()[index].getTackle());
    container->functions->setLabelTextColor(ui->techLab, container->teams[id].getPlayer()[index].getTechnik());
    container->functions->setLabelTextColor(ui->shotLab, container->teams[id].getPlayer()[index].getShot());
    container->functions->setLabelTextColor(ui->passLab, container->teams[id].getPlayer()[index].getPass());
    container->functions->setLabelTextColor(ui->headLab, container->teams[id].getPlayer()[index].getHeader());
    container->functions->setLabelTextColor(ui->speedLab, container->teams[id].getPlayer()[index].getSpeed());
    container->functions->setLabelTextColor(ui->enduranceLab, container->teams[id].getPlayer()[index].getEndurance());

    container->functions->setLabelTextColor(ui->realSkils, container->teams[id].getPlayer()[index].getRealOveral());
    container->functions->setLabelTextColor(ui->skils, container->teams[id].getPlayer()[index].getOverall(index, formation_number));
    container->functions->setLabelTextColor(ui->powerskils, container->teams[id].getPlayer()[index].getEnergyOverall(index, formation_number));

    ui->realSkils->setText(QString::number(container->teams[id].getPlayer()[index].getRealOveral()));
    ui->skils->setText(QString::number(container->teams[id].getPlayer()[index].getOverall(index, formation_number)));
    ui->powerskils->setText(QString::number(container->teams[id].getPlayer()[index].getEnergyOverall(index, formation_number)));


    ui->firstName->setText(container->teams[id].getPlayer()[index].getFname());
    ui->secondName->setText(container->teams[id].getPlayer()[index].getLname());
    ui->pos->setText(container->teams[id].getPlayer()[index].getPosition());
    ui->gkLab->setText(QString::number(container->teams[id].getPlayer()[index].getGkeeper()));
    ui->defLab->setText(QString::number(container->teams[id].getPlayer()[index].getDefence()));
    ui->midLab->setText(QString::number(container->teams[id].getPlayer()[index].getMidfield()));
    ui->attackLab->setText(QString::number(container->teams[id].getPlayer()[index].getAttack()));
    ui->tackleLab->setText(QString::number(container->teams[id].getPlayer()[index].getTackle()));
    ui->techLab->setText(QString::number(container->teams[id].getPlayer()[index].getTechnik()));
    ui->shotLab->setText(QString::number(container->teams[id].getPlayer()[index].getShot()));
    ui->passLab->setText(QString::number(container->teams[id].getPlayer()[index].getPass()));
    ui->headLab->setText(QString::number(container->teams[id].getPlayer()[index].getHeader()));
    ui->speedLab->setText(QString::number(container->teams[id].getPlayer()[index].getSpeed()));
    ui->enduranceLab->setText(QString::number(container->teams[id].getPlayer()[index].getEndurance()));
    ui->goalLab->setText(QString::number(container->teams[id].getPlayer()[index].getGoals()));
    ui->energy->setValue(container->teams[id].getPlayer()[index].getStamina());
}
void UserSquad::formationColor(int formation)
{

    if(formation == 1)
    {
        container->formations->formation442(ui->tableWidget, titles);
        ui->formation->setText("4-4-2");
    }

    if(formation == 2)
    {
        container->formations->formation433(ui->tableWidget, titles);
        ui->formation->setText("4-4-3");
    }
    if(formation == 3)
    {
        container->formations->formation352(ui->tableWidget, titles);
        ui->formation->setText("3-5-2");
    }
}

void UserSquad::updateTeamStats()
{
    ui->str->setNum(team->teamStrength(container->teams[id].getPlayer(), formation_number));
    ui->gk->setNum(team->teamGoalkeeper(container->teams[id].getPlayer()));
    ui->def->setNum(team->teamDefence(container->teams[id].getPlayer(), formation_number));        // formation_color odpowiada rodzajowi formacji
    ui->mid->setNum(team->teamMidfield(container->teams[id].getPlayer(), formation_number));
    ui->att->setNum(team->teamAttack(container->teams[id].getPlayer(), formation_number));
    ui->spd->setNum(team->teamSpeed(container->teams[id].getPlayer()));
    ui->tech->setNum(team->teamTechnick(container->teams[id].getPlayer()));
    ui->defensive->setNum(team->teamDefensive(container->teams[id].getPlayer(), formation_number));
    ui->offensive->setNum(team->teamOffensive(container->teams[id].getPlayer(), formation_number));
    container->teams[id].setFormation(formation_number);

    ui->str_2->setNum(team->teamStrengthEnergy(container->teams[id].getPlayer(), formation_number));
    ui->gk_2->setNum(team->teamGoalkeeperEnergy(container->teams[id].getPlayer()));
    ui->def_2->setNum(team->teamDefenceEnergy(container->teams[id].getPlayer(), formation_number));
    ui->mid_2->setNum(team->teamMidfieldEnergy(container->teams[id].getPlayer(), formation_number));
    ui->att_2->setNum(team->teamAttackEnergy(container->teams[id].getPlayer(), formation_number));
    ui->spd_2->setNum(team->teamSpeedEnergy(container->teams[id].getPlayer()));
    ui->tech_2->setNum(team->teamTechnickEnergy(container->teams[id].getPlayer()));
    ui->defensive_2->setNum(team->teamDefensiveEnergy(container->teams[id].getPlayer(), formation_number));
    ui->offensive_2->setNum(team->teamOffensiveEnergy(container->teams[id].getPlayer(), formation_number));

    ui->pressingSlider->setValue(container->teams[id].getPressing());
    ui->pressingDig->setNum(ui->pressingSlider->value());

    ui->attackSlider->setValue(container->teams[id].getAttackLevel());
    ui->attackDig->setNum(ui->attackSlider->value());

    container->teams[id].setFormation(formation_number);
    formationPitch(container->teams[id].getFormation());

    ui->teamenergy->setValue(team->teamEnergy(container->teams[id].getPlayer()));
    ui->changecount->setNum(substitutions);

    ui->managerName->setText(container->userData->getFname() + " " + container->userData->getLname());

    for(int i = 0; i < container->teams.size(); ++i)
    {
        container->teams[i].setStrength(team->teamStrength(container->teams[id].getPlayer(), container->teams[i].getFormation())) ;
    }
    int pressing = container->teams[id].getPressing();

    pressingValue(pressing);
}

void UserSquad::changePlayer()
{
    //num1 = ui->spinBox->value();
    //num2 = ui->spinBox_2->value();

    QVector<Player> temp;

    temp.push_back(container->teams[id].getPlayer()[num1 - 1]);

    container->teams[id].getPlayer()[num1 - 1] = container->teams[id].getPlayer()[num2 - 1];
    container->teams[id].getPlayer()[num2 - 1] = temp[0];

    ui->tableWidget->setRowCount(0);
        //Serialization serializattion;
        //serializattion.saveSquad(save_path, container->player[squad_number]);
    squad();
}

void UserSquad::highlightPlayer(QTableWidget *tableWidget,QLabel *label, int index)
{
    if(tableWidget->currentRow()+1 == index)
        label->setStyleSheet("background-color: rgba(255, 255, 255, 30);");
    else
        label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
}

void UserSquad::pressingValue(int pressing)
{
    if(pressing < 20)
        ui->pressing2->setText("NAJNIŻSZY");
    else if(pressing >= 20 && pressing < 40)
        ui->pressing2->setText("NISKI");
    else if(pressing >= 40 && pressing < 60)
        ui->pressing2->setText("ŚREDNI");
    else if(pressing >= 60 && pressing < 80)
        ui->pressing2->setText("WYSOKI");
    else if(pressing >= 80)
        ui->pressing2->setText("NAJWYŻSZY");
}

void UserSquad::attackValue(int attack)
{
    if(attack < 33)
        ui->attack2->setText("KONTRATAK");
    else if(attack >= 33 && attack < 66)
        ui->attack2->setText("POZYCYJNY");
    else if(attack >= 66)
        ui->attack2->setText("CAŁKOWITY");
}

void UserSquad::pressingControler()
{
     ui->pressingDig->setNum(ui->pressingSlider->value());
     container->teams[id].setPressing(ui->pressingSlider->value());

     int pressing = container->teams[id].getPressing();

     pressingValue(pressing);
}

void UserSquad::attackControler()
{
    ui->attackDig->setNum(ui->attackSlider->value());
    container->teams[id].setAttackLevel(ui->attackSlider->value());

    int attack = ui->attackSlider->value();

    attackValue(attack);
}

void UserSquad::formation442()
{
    formationColor(1);
    formation_number = 1;
    updateTeamStats();
    ui->tableWidget->setRowCount(0);
    squad();
}

void UserSquad::formation433()
{
    formationColor(2);
    formation_number = 2;
    updateTeamStats();
    ui->tableWidget->setRowCount(0);
    squad();
}

void UserSquad::formation352()
{
    formationColor(3);
    container->formations->formation352(ui->tableWidget, titles);
    formation_number = 3;
    updateTeamStats();
    ui->tableWidget->setRowCount(0);
    squad();
}

void UserSquad::on_back_clicked()
{
    for(int i = 0; i < container->teams[id].getPlayer().size(); ++i)
    {
        if(i > 10)
            if(container->teams[id].getPlayer()[i].getFirstTeam() == 0)
                container->teams[id].getPlayer()[i].setFirstTeam(2);
        if(i <= 10)
            if(container->teams[id].getPlayer()[i].getFirstTeam() == 1)
                container->teams[id].getPlayer()[i].setFirstTeam(3);
        if(i > 10)
            if(container->teams[id].getPlayer()[i].getFirstTeam() == 3)
                container->teams[id].getPlayer()[i].setFirstTeam(2);

        if(i > 10)
            if(container->teams[id].getPlayer()[i].getFirstTeam() == 4)
               container->teams[id].getPlayer()[i].setFirstTeam(2);
    }

    if(substitutions == 0)
        no_changes = true;

    UserSquad::close();

}

void UserSquad::take()
{
    highlightPlayer(ui->tableWidget, ui->p1, 1);
    highlightPlayer(ui->tableWidget, ui->p2, 2);
    highlightPlayer(ui->tableWidget, ui->p3, 3);
    highlightPlayer(ui->tableWidget, ui->p4, 4);
    highlightPlayer(ui->tableWidget, ui->p5, 5);
    highlightPlayer(ui->tableWidget, ui->p6, 6);
    highlightPlayer(ui->tableWidget, ui->p7, 7);
    highlightPlayer(ui->tableWidget, ui->p8, 8);
    highlightPlayer(ui->tableWidget, ui->p9, 9);
    highlightPlayer(ui->tableWidget, ui->p10, 10);
    highlightPlayer(ui->tableWidget, ui->p11, 11);

    num1 = ui->tableWidget->currentRow()+1;
    index = ui->tableWidget->currentRow();

    QString foto_path = container->teams[id].getPlayer()[index].getFotoPath();
    QPixmap pixmap = foto_path;

    container->functions->setIcon(pixmap, ui->fotoLabel, 250, 295);

    taken = true;
}

void UserSquad::put()
{
    num2 = ui->tableWidget->currentRow()+1;

    if(taken == true)
    {
        if(when_playing_match == true)
        {
            for(int i = 0; i < container->teams[id].getPlayer().size(); ++i)    // zabezpieczenie przed zmiana zmienionego zawodnika
            {
                if(i <= 10)
                {
                    if((container->teams[id].getPlayer()[num1-1].getFirstTeam() == 3) &&
                       (container->teams[id].getPlayer()[num2-1].getFirstTeam() == 1))
                             container->teams[id].getPlayer()[num2-1].setFirstTeam(4);

                    if((container->teams[id].getPlayer()[num1-1].getFirstTeam() == 1) &&
                       (container->teams[id].getPlayer()[num2-1].getFirstTeam() == 3))
                             container->teams[id].getPlayer()[num1-1].setFirstTeam(4);
                }

                if(i <= 10)
                {
                    if((container->teams[id].getPlayer()[num1-1].getFirstTeam() == 4) &&
                       (container->teams[id].getPlayer()[num2-1].getFirstTeam() == 1))
                             container->teams[id].getPlayer()[num2-1].setFirstTeam(5);

                    if((container->teams[id].getPlayer()[num1-1].getFirstTeam() == 1) &&
                       (container->teams[id].getPlayer()[num2-1].getFirstTeam() == 4))
                             container->teams[id].getPlayer()[num1-1].setFirstTeam(5);
                }
            }
        }

        if(substitutions > 0)
        {
            if(ui->tableWidget->currentItem())
            {
                if((container->teams[id].getPlayer()[num1-1].getFirstTeam() == 2 && num2 < 12) ||
                      (container->teams[id].getPlayer()[num2-1].getFirstTeam() == 2 && num1 < 12))
                {
                    ContextMenu contextmenu(0, "JUŻ GRAŁ");
                    contextmenu.exec();
                    //QMessageBox::information(this, "Info", "Ten zawodnik juz gral");
                    taken = false;
                }
                else
                   taken = true;
            }
            if(taken == true)
            {
                changePlayer();
                taken = false;
            }
        }
        if(substitutions == 0 && no_changes == true)
        {
            if((num1 >= 12 && num2 >= 12) || (num1 < 12 && num2 < 12))
            {
                changePlayer();
                taken = false;
            }
            if((num1 < 12 && num2 >= 12) || (num1 >= 12 && num2 < 12))
            {

                ContextMenu contextmenu(0, "NIE MASZ ZMIAN");
                contextmenu.exec();
                //QMessageBox::information(this, "Info", "Wykorzystales wszystkie zmiany");
                taken = false;

            }
        }
        if(substitutions == 0 && no_changes == false)
        {
            if((num1 >= 12 && num2 >= 12) || (num1 < 12 && num2 < 12))
            {
                changePlayer();
                taken = false;
            }
            if((num1 < 12 && num2 >= 12) || (num1 >= 12 && num2 < 12))
            {
                 if((container->teams[id].getPlayer()[num1-1].getFirstTeam() == 1) &&
                    (container->teams[id].getPlayer()[num2-1].getFirstTeam() == 1))
                 {
                        changePlayer();
                        taken = false;
                 }

                 else
                 {
                    // QMessageBox::information(this, "Info", "Wykorzystales wszystkie zmiany");
                     ContextMenu contextmenu(0, "NIE MASZ ZMIAN");
                     contextmenu.exec();
                     taken = false;
                 }

            }
        }
    }

}

void UserSquad::contextMenu()
{
    ContextMenu context_menu;
    context_menu.exec();
}


