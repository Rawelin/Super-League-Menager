#include "showsquads.h"
#include "ui_showsquads.h"
#include "gamewindow.h"
#include <QDebug>

extern Container *container;

ShowSquads::ShowSquads(QWidget *parent, const QString& name, int sqn) :
    QDialog(parent),
    ui(new Ui::ShowSquads),
    team(new Team)
{
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    id = sqn;
    team_name = name;

    ui->setupUi(this);
    this->showFullScreen();
    ui->frame->setVisible(false);

    connect(ui->tableWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(personalData()));

    setGraphic();

    ui->teamname->setText(team_name);
    formation_color = container->teams[id].getFormation();

    squad();
}

ShowSquads::~ShowSquads()
{
    delete ui;
}

void ShowSquads::setGraphic()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("/Programowanie/Qt C++/Qt Manager Project/ManagerPl/Background/back2.jpg")))));
    setPalette(palette);

    ui->tableWidget->setFrameShape(QFrame::NoFrame);
   // ui->tableWidget->setGridStyle(Qt::SolidLine);

    container->functions->setIcon(container->teams[id].getLogo(), ui->logo, 80, 80);
    container->functions->setIcon(container->teams[id].getLogo(), ui->logo2, 80, 80);

    setStyleSheet("QTableWidget {background-color: transparent;}"
                  "QTableWidget {selection-background-color: rgb(0, 0, 20,50);}"
                  "QTableWidget {selection-color: rgb(255, 255, 255);}"
                  "QHeaderView::section {background-color: transparent;}"
                  "QHeaderView {background-color: transparent;}"
                  "QTableCornerButton::section {background-color: transparent;}");

    ui->tableWidget->horizontalHeader()->setStyleSheet("color: blue");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: blue");

    ui->formation->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame2->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame3->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    ui->name->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->surname->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->position->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->skils->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->powerskils->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->goals->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->l1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->l5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
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
                                  "background-color: rgba(255, 255, 255, 10);"
                                  "}"
                                  );

}


void ShowSquads::squad()
{
        int fila;
        QStringList tytuly;

        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

        ui->tableWidget->setColumnCount(19);
        ui->tableWidget->setColumnWidth(0,150);
        ui->tableWidget->setColumnWidth(1,200);
        ui->tableWidget->setColumnWidth(2,40);
        ui->tableWidget->setColumnWidth(3,40);
        ui->tableWidget->setColumnWidth(4,40);
        ui->tableWidget->setColumnWidth(5,30);
        ui->tableWidget->setColumnWidth(6,30);
        ui->tableWidget->setColumnWidth(7,30);
        ui->tableWidget->setColumnWidth(8,35);
        ui->tableWidget->setColumnWidth(9,35);
        ui->tableWidget->setColumnWidth(10,35);
        ui->tableWidget->setColumnWidth(11,35);
        ui->tableWidget->setColumnWidth(12,35);
        ui->tableWidget->setColumnWidth(13,35);
        ui->tableWidget->setColumnWidth(14,35);
        ui->tableWidget->setColumnWidth(15,35);
        ui->tableWidget->setColumnWidth(16,35);
        ui->tableWidget->setColumnWidth(17,35);
        ui->tableWidget->setColumnWidth(18,35);

        //setWindowTitle("Tabela");
        ui->tableWidget->setColumnCount(19);
        tytuly << "IMIE" << "NAZWISKO" << "POZ"  << "KRAJ" << "WIEK" << "GK" << "DEF" << "MID"
                   << "ATT" << "ODB" << "TEC" << "STR" <<"PAS" << "HEA" << "PRE" << "END" << "STA"
                   << "OVE" << "GOL";


        ui->tableWidget->setHorizontalHeaderLabels(tytuly);

        ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
        ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);

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
            ui->tableWidget->setItem(fila, GK, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getGkeeper())));
            ui->tableWidget->setItem(fila, DEF, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getDefence())));
            ui->tableWidget->setItem(fila, MID, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getMidfield())));
            ui->tableWidget->setItem(fila, ATT, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getAttack())));
            ui->tableWidget->setItem(fila, TACKLE, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getTackle())));
            ui->tableWidget->setItem(fila, TECHNIK, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getTechnik())));
            ui->tableWidget->setItem(fila, SHOT, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getShot())));
            ui->tableWidget->setItem(fila, PASS, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getPass())));
            ui->tableWidget->setItem(fila, HEAD, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getHeader())));
            ui->tableWidget->setItem(fila, SPEED, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getSpeed())));
            ui->tableWidget->setItem(fila, ENDURANCE, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getEndurance())));
            ui->tableWidget->setItem(fila, STAMINA, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getStamina())));
            ui->tableWidget->setItem(fila, OVERALL, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getOverall(i, formation_color))));
            ui->tableWidget->setItem(fila, GOALS, new QTableWidgetItem(QString::number(container->teams[id].getPlayer()[i].getGoals())));

            for(int i = 2; i < 19; ++i)
            {
                ui->tableWidget->item(j, i)->setTextAlignment(Qt::AlignCenter);
            }
        }

    updateTeamStats();
    formationColor(formation_color);
}


void ShowSquads::formationColor(int formation)
{
    if(formation == 1)
    {
        for(int i = 0; i < 19; ++i)
            ui->tableWidget->item(0, i)->setBackground(QColor(255, 255, 0, 50));
        for(int j = 1; j <= 4; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(0, 255, 0, 50));
        for(int j = 5; j <= 8; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(0, 0, 255, 50));
        for(int j = 9; j <= 10; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(255, 0, 0, 50));
      /*  for(int j = 11; j <= 16; ++j)
            for(int i = 0; i < 10; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
        ui->formation->setText("4-4-2");
    }

    if(formation == 2)
    {
        for(int i = 0; i < 19; ++i)
            ui->tableWidget->item(0, i)->setBackground(QColor(255, 255, 0, 50));
        for(int j = 1; j <= 4; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(0, 255, 0, 50));
        for(int j = 5; j <= 7; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(0, 0, 255, 50));
        for(int j = 8; j <= 10; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(255, 0, 0, 50));
      /*  for(int j = 11; j <= 16; ++j)
            for(int i = 0; i < 10; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
        ui->formation->setText("4-4-3");
    }
    if(formation == 3)
    {
        for(int i = 0; i < 19; ++i)
            ui->tableWidget->item(0, i)->setBackground(QColor(255, 255, 0, 50));
        for(int j = 1; j <= 3; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(0, 255, 0, 50));
        for(int j = 4; j <= 8 ; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(0, 0, 255, 50));
        for(int j = 9; j <= 10; ++j)
            for(int i = 0; i < 19; ++i)
                ui->tableWidget->item(j, i)->setBackground(QColor(255, 0, 0, 50));
      /*  for(int j = 11; j <= 16; ++j)
            for(int i = 0; i < 10; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
        ui->formation->setText("3-5-2");
    }
}

void ShowSquads::updateTeamStats()
{
    ui->str->setNum(team->teamStrength(container->teams[id].getPlayer(), formation_color));
    ui->gk->setNum(team->teamGoalkeeper(container->teams[id].getPlayer()));
    ui->def->setNum(team->teamDefence(container->teams[id].getPlayer(), formation_color));        // formation_color odpowiada rodzajowi formacji
    ui->mid->setNum(team->teamMidfield(container->teams[id].getPlayer(), formation_color));
    ui->att->setNum(team->teamAttack(container->teams[id].getPlayer(), formation_color));
    ui->spd->setNum(team->teamSpeed(container->teams[id].getPlayer()));
    ui->tech->setNum(team->teamTechnick(container->teams[id].getPlayer()));
    ui->defensive->setNum(team->teamDefensive(container->teams[id].getPlayer(), formation_color));
    ui->offensive->setNum(team->teamOffensive(container->teams[id].getPlayer(), formation_color));
    container->teams[id].setFormation(formation_color);

    ui->str_2->setNum(team->teamStrengthEnergy(container->teams[id].getPlayer(), formation_color));
    ui->gk_2->setNum(team->teamGoalkeeperEnergy(container->teams[id].getPlayer()));
    ui->def_2->setNum(team->teamDefenceEnergy(container->teams[id].getPlayer(), formation_color));
    ui->mid_2->setNum(team->teamMidfieldEnergy(container->teams[id].getPlayer(), formation_color));
    ui->att_2->setNum(team->teamAttackEnergy(container->teams[id].getPlayer(), formation_color));
    ui->spd_2->setNum(team->teamSpeedEnergy(container->teams[id].getPlayer()));
    ui->tech_2->setNum(team->teamTechnickEnergy(container->teams[id].getPlayer()));
    ui->defensive_2->setNum(team->teamDefensiveEnergy(container->teams[id].getPlayer(), formation_color));
    ui->offensive_2->setNum(team->teamOffensiveEnergy(container->teams[id].getPlayer(), formation_color));

    container->teams[id].setFormation(formation_color);

    ui->teamenergy->setValue(team->teamEnergy(container->teams[id].getPlayer()));

    for(int i = 0; i < container->teams.size(); ++i)
    {
        container->teams[i].setStrength(team->teamStrength(container->teams[id].getPlayer(), container->teams[i].getFormation())) ;
    }
}

void ShowSquads::on_pushButton_clicked()
{
    //GameWindow* gamewindow = new GameWindow();
   // gamewindow->show();
    ShowSquads::close();
}

void ShowSquads::personalData()
{
    index = ui->tableWidget->currentRow();

    ui->frame->setVisible(true);
    ui->name->setText(container->teams[id].getPlayer()[index].getFname());
    ui->surname->setText(container->teams[id].getPlayer()[index].getLname());
    ui->position->setText(container->teams[id].getPlayer()[index].getPosition());
    ui->skils->setText(QString::number(container->teams[id].getPlayer()[index].getOverall(index, formation_color)));
    ui->powerskils->setText(QString::number(container->teams[id].getPlayer()[index].getEnergyOverall(index, formation_color)));
    ui->goals->setText(QString::number(container->teams[id].getPlayer()[index].getGoals()));
    ui->energy->setValue(container->teams[id].getPlayer()[index].getStamina());
}
