#include <algorithm>
#include <iterator>
#include <QDebug>
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "showsquads.h"
#include "match.h"

extern Container *container;

GameWindow::GameWindow(QWidget *parent, const QString &name, const QString &file, const QString &save, int sqn) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    team(new Team)
{
    squad_number = sqn;                             // numer skladu w vektorze 2d
    team_name = name;
    default_player_path = file;                     // dla rozpoczynajacych gre sklady defaultowe
    save_path = save;                               // dla juz grajacych sklady zapisane przez gracza
    formation_color = 1;                            // pozniej bedzie trzeba przypisac z vector<Team>
    num1 = 0;
    num2 = 0;

    container->loadDefaultData();                     // inicjalizacja wszystkich kontenerow

    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/t2.jpg")))));
    setPalette(*palette);

    ui->setupUi(this);
    this->showFullScreen();

    setWindowTitle("EKSTRAKLASA");
    ui->teamname->setText(team_name);

    ui->tabWidget->addTab(new Match(), QString("MECZ"));
    ui->tabWidget->addTab(new Fixture(), QString("TERMINARZ"));
    ui->tabWidget->addTab(new TablesAndStats(), QString("TABELE"));
    //ui->statusbar->addPermanentWidget();
   // QString path("/Programowanie/Qt C++/Qt Manager Project/ManagerPl/Data/teams.txt");

    //Serialization serializattion;
   // serializattion.loadSquad(default_player_path, player);

    //serializattion.loadTeam(path, team_list);

    maximum_size = container->player[squad_number].size();

    ui->spinBox->setMaximum(maximum_size);
    ui->spinBox_2->setMaximum(maximum_size);

    squad();

    formationColor(formation_color);

    connect(ui->form1, SIGNAL(clicked(bool)), this, SLOT(formation442()));
    connect(ui->form2, SIGNAL(clicked(bool)), this, SLOT(formation433()));
    connect(ui->form3, SIGNAL(clicked(bool)), this, SLOT(formation352()));

}

GameWindow::~GameWindow()
{
    delete ui;
    delete team;
    delete palette;
}

void GameWindow::on_actionMain_Menu_triggered()
{
    MainMenu *mainMenu = new MainMenu();
    mainMenu->show();

    GameWindow::close();
}

void GameWindow::squad()
{
    int fila;
    QStringList tytuly;

    ui->tableWidget->setColumnCount(16);
    ui->tableWidget->setColumnWidth(0,150);
    ui->tableWidget->setColumnWidth(1,150);
    ui->tableWidget->setColumnWidth(2,30);
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

    //setWindowTitle("Tabela");
    ui->tableWidget->setColumnCount(16);
    tytuly << "IMIE" << "NAZWISKO" << "POZ"  << "KRAJ" << "WIEK" << "GK" << "DEF" << "MID"
           << "ATT" << "ODB" << "TEC" << "STR" << "PRE" << "ENE" << "OVE" << "GOL";

    ui->tableWidget->setHorizontalHeaderLabels(tytuly);

    /*QString CustomStyle = QString("QTableWidget::item {" "background-color: rgba(162, 186, 60);" "}");

    QString yellow = QString("QTableWidget::item {" "background-color: yellow;" "}");
    QString darkgreen = QString("QTableWidget::item {" "background-color: darkgreen;" "}");
    QString darkblue = QString("QTableWidget::item {" "background-color: darkblue;" "}");
    QString red = QString("QTableWidget::item {" "background-color: red;" "}");
    QString darkcyan = QString("QTableWidget::item {" "background-color: adrkcyan;" "}");

    ui->tableWidget->item(8, 2)->setBackground(Qt::red);
    ui->tableWidget->setStyleSheet(yellow);*/

    for(int i = 0; i < container->player[squad_number].size(); ++i)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila = ui->tableWidget->rowCount() - 1;

        ui->tableWidget->setItem(fila, NAME, new QTableWidgetItem(container->player[squad_number][i].getFname()));
        ui->tableWidget->setItem(fila, SURNAME, new QTableWidgetItem(container->player[squad_number][i].getLname()));
        ui->tableWidget->setItem(fila, POSITION, new QTableWidgetItem(container->player[squad_number][i].getPosition()));
        ui->tableWidget->setItem(fila, NATIONALITY, new QTableWidgetItem(container->player[squad_number][i].getNationality()));
        ui->tableWidget->setItem(fila, AGE, new QTableWidgetItem(QString::number(container->player[squad_number][i].getAge())));
        ui->tableWidget->setItem(fila, GK, new QTableWidgetItem(QString::number(container->player[squad_number][i].getGkeeper())));
        ui->tableWidget->setItem(fila, DEF, new QTableWidgetItem(QString::number(container->player[squad_number][i].getDefence())));
        ui->tableWidget->setItem(fila, MID, new QTableWidgetItem(QString::number(container->player[squad_number][i].getMidfield())));
        ui->tableWidget->setItem(fila, ATT, new QTableWidgetItem(QString::number(container->player[squad_number][i].getAttack())));
        ui->tableWidget->setItem(fila, TACKLE, new QTableWidgetItem(QString::number(container->player[squad_number][i].getTackle())));
        ui->tableWidget->setItem(fila, TECHNIK, new QTableWidgetItem(QString::number(container->player[squad_number][i].getTechnik())));
        ui->tableWidget->setItem(fila, SHOT, new QTableWidgetItem(QString::number(container->player[squad_number][i].getShot())));
        ui->tableWidget->setItem(fila, SPEED, new QTableWidgetItem(QString::number(container->player[squad_number][i].getSpeed())));
        ui->tableWidget->setItem(fila, STAMINA, new QTableWidgetItem(QString::number(container->player[squad_number][i].getEndurance())));
        ui->tableWidget->setItem(fila, OVERALL, new QTableWidgetItem(QString::number(container->player[squad_number][i].getOverall(i, formation_color))));
        ui->tableWidget->setItem(fila, GOALS, new QTableWidgetItem(QString::number(container->player[squad_number][i].getGoals())));
    }
    updateTeamStats();
    formationColor(formation_color);
    updateTeams();
}

void GameWindow::formationColor(int formation)
{
    if(formation == 1)
    {
        for(int i = 0; i < 16; ++i)
            ui->tableWidget->item(0, i)->setBackground(Qt::yellow);
        for(int j = 1; j <= 4; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::green);
        for(int j = 5; j <= 8; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::blue);
        for(int j = 9; j <= 10; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::red);
      /*  for(int j = 11; j <= 16; ++j)
            for(int i = 0; i < 10; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
        ui->formation->setText("4-4-2");
    }

    if(formation == 2)
    {
        for(int i = 0; i < 16; ++i)
            ui->tableWidget->item(0, i)->setBackground(Qt::yellow);
        for(int j = 1; j <= 4; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::green);
        for(int j = 5; j <= 7; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::blue);
        for(int j = 8; j <= 10; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::red);
      /*  for(int j = 11; j <= 16; ++j)
            for(int i = 0; i < 10; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
        ui->formation->setText("4-4-3");
    }
    if(formation == 3)
    {
        for(int i = 0; i < 16; ++i)
            ui->tableWidget->item(0, i)->setBackground(Qt::yellow);
        for(int j = 1; j <= 3; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::green);
        for(int j = 4; j <= 8 ; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::blue);
        for(int j = 9; j <= 10; ++j)
            for(int i = 0; i < 16; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::red);
      /*  for(int j = 11; j <= 16; ++j)
            for(int i = 0; i < 10; ++i)
                ui->tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
        ui->formation->setText("3-5-2");
    }
}

void GameWindow::updateTeamStats()
{
    ui->str->setNum(team->teamStrength(container->player[squad_number], formation_color));
    ui->gk->setNum(team->teamGoalkeeper(container->player[squad_number]));
    ui->def->setNum(team->teamDefence(container->player[squad_number], formation_color));        // formation_color odpowiada rodzajowi formacji
    ui->mid->setNum(team->teamMidfield(container->player[squad_number], formation_color));
    ui->att->setNum(team->teamAttack(container->player[squad_number], formation_color));
    ui->spd->setNum(team->teamSpeed(container->player[squad_number]));
    ui->tech->setNum(team->teamTechnick(container->player[squad_number]));
    ui->defensive->setNum(team->teamDefensive(container->player[squad_number], formation_color));
    ui->offensive->setNum(team->teamOffensive(container->player[squad_number], formation_color));
    container->teams[squad_number].setFormation(formation_color);

    for(int i = 0; i < container->teams.size(); ++i)
    {
        container->teams[i].setStrength(team->teamStrength(container->player[i], container->teams[i].getFormation())) ;
    }

    //ui->tabWidget->removeTab(4);                                        // uaktualnienie tab - Stats
   // ui->tabWidget->addTab(new Stats(), QString("STATYSTYKI"));

}
void GameWindow::updateTeams()
{
    QString path("/Programowanie/Qt C++/Qt Manager Project/ManagerPl/Data/teams.txt");

    Serialization serialization;
    //serialization.saveTeam(path, container->team);
}

void GameWindow::on_actionExit_triggered()
{
    ui->tableWidget->setRowCount(0);
    GameWindow::close();
}
void GameWindow::on_jagielonia_clicked()
{
    ShowSquads squad(0,"JAGIELONIA BIALYSTOK", 0);
    squad.setModal(true);
    squad.exec();
   // GameWindow::close();
}

void GameWindow::on_legia_clicked()
{

    ShowSquads squad(0,"LEGIA WARSZAWA", 1);
    squad.setModal(true);
    squad.exec();
    //GameWindow::close();
}

void GameWindow::on_lech_clicked()
{

    ShowSquads squad(0,"LECH POZNAN", 2);
    squad.setModal(true);
    squad.exec();
   // GameWindow::close();
}

void GameWindow::on_wisla_clicked()
{
   // GameWindow::close();

    ShowSquads squad(0,"WISLA KRAKOW", 3);
    squad.setModal(true);
    squad.exec();
}

void GameWindow::on_change_clicked()
{
    num1 = ui->spinBox->value();
    num2 = ui->spinBox_2->value();

    QVector<Player> temp;

    temp.push_back(container->player[squad_number][num1 - 1]);

    container->player[squad_number][num1 - 1] = container->player[squad_number][num2 - 1];
    container->player[squad_number][num2 - 1] = temp[0];

    ui->tableWidget->setRowCount(0);
   // Serialization serializattion;
   // serializattion.saveSquad(save_path, container->player[squad_number]);
    squad();
}

void GameWindow::formation442()
{
    formationColor(1);
    formation_color = 1;
    updateTeamStats();
}

void GameWindow::formation433()
{
    formationColor(2);
    formation_color = 2;
    updateTeamStats();
}

void GameWindow::formation352()
{
    formationColor(3);
    formation_color = 3;
    updateTeamStats();
}

void GameWindow::on_actionNew_Menu_triggered()
{
      GameDialog gamedialog;
      gamedialog.exec();
}
