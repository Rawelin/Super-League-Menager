#include "editchooseteam.h"
#include "ui_editchooseteam.h"

extern Container *container;

EditChooseTeam::EditChooseTeam(QWidget *parent, int select_option) :
    QDialog(parent),
    ui(new Ui::EditChooseTeam)
{
    select = select_option;
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint);
    this->showFullScreen();
    setImages();
    setLabel(select_option);

}

EditChooseTeam::~EditChooseTeam()
{
    delete ui;
    delete music;
    delete palette;
    delete addPlayer;
    delete removePlayer;
    delete editPlayer;
}
void EditChooseTeam::setImages()
{
    palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Stadiony/slask.jpg")))));
    setPalette(*palette);

    ui->edit->setStyleSheet("background-color: rgba(0, 127, 255, 30);");



    container->functions->setIcon(container->teams[0].getLogo(), ui->real, "Real Madryt");
    container->functions->setIcon(container->teams[1].getLogo(), ui->bayern, "Bayern Monachium");
    container->functions->setIcon(container->teams[2].getLogo(), ui->barcelona, "FC Barcelona");
    container->functions->setIcon(container->teams[3].getLogo(), ui->atletico, "Atletico Madryt");
    container->functions->setIcon(container->teams[4].getLogo(), ui->juventus, "Juventus Turyn");
    container->functions->setIcon(container->teams[5].getLogo(), ui->psg, "PSG");
    container->functions->setIcon(container->teams[6].getLogo(), ui->borusia, "Borussia Dortmund");
    container->functions->setIcon(container->teams[7].getLogo(), ui->sevila, "FC Sevilla");
    container->functions->setIcon(container->teams[8].getLogo(), ui->benfica, "Benfica Lisbona");
    container->functions->setIcon(container->teams[9].getLogo(), ui->chelsea, "Chelsea London");
    container->functions->setIcon(container->teams[10].getLogo(), ui->arsenal, "FC Arsenal");
    container->functions->setIcon(container->teams[11].getLogo(), ui->manchester_city, "Manchester City");
    container->functions->setIcon(container->teams[12].getLogo(), ui->porto, "FC Porto");
    container->functions->setIcon(container->teams[13].getLogo(), ui->schalke, "Schalke 04");
    container->functions->setIcon(container->teams[14].getLogo(), ui->manu, "Manchester United");
    container->functions->setIcon(container->teams[15].getLogo(), ui->napoli, "FC Napoli");
}

void EditChooseTeam::setSelect(int select, int team_number, const QString save)
{

    if(select == 1)
    {
        //container->functions->delay(100);
       // AddPlayer addplayer(0, team_number, save);
       // EditChooseTeam::close();
       // addplayer.exec();

        addPlayer = new AddPlayer(0, team_number, save);
        ui->stackedWidget->insertWidget(1, addPlayer);
        ui->stackedWidget->setCurrentIndex(1);

        connect(addPlayer, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));
    }

    if(select == 2)
    {
        //container->functions->delay(100);
        //RemovePlayer removeplayer(0, team_number, save);
        //EditChooseTeam::close();
        //removeplayer.exec();

        removePlayer = new RemovePlayer(0, team_number, save);
        ui->stackedWidget->insertWidget(2, removePlayer);
        ui->stackedWidget->setCurrentIndex(2);

        connect(removePlayer, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));
    }
    if(select == 3)
    {
       // container->functions->delay(100);
       // EditPlayer editplayer(0, team_number, save);
       // EditChooseTeam::close();
       // editplayer.exec();

        editPlayer = new EditPlayer(0, team_number, save);
        ui->stackedWidget->insertWidget(3, editPlayer);
        ui->stackedWidget->setCurrentIndex(3);

        connect(editPlayer, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));
    }
}

void EditChooseTeam::setLabel(int select_option)
{
    if(select_option == 1)
    {
        ui->label->setText("DODAJ ZAWODNIKA");
    }
    else if(select_option == 2)
    {
          ui->label->setText("USUŃ ZAWODNIKA");
    }
    else if(select_option == 3)
    {
        ui->label->setText("EDYTUJ ZAWODNIKA");
    }
}


void EditChooseTeam::on_real_clicked()
{
    QString save("Data/real.txt");
    setSelect(select, 0, save);
}

void EditChooseTeam::on_bayern_clicked()
{
    QString save("Data/bayern.txt");
    setSelect(select, 1, save);
}

void EditChooseTeam::on_barcelona_clicked()
{
    QString save("Data/barcelona.txt");
    setSelect(select, 2, save);
}

void EditChooseTeam::on_atletico_clicked()
{
    QString save("Data/atletico.txt");
    setSelect(select, 3, save);
}

void EditChooseTeam::on_juventus_clicked()
{
    QString save("Data/juventus.txt");
    setSelect(select, 4, save);
}

void EditChooseTeam::on_psg_clicked()
{
    QString save("Data/psg.txt");
    setSelect(select, 5, save);
}

void EditChooseTeam::on_borusia_clicked()
{
    QString save("Data/borussia.txt");
    setSelect(select, 6, save);
}

void EditChooseTeam::on_sevila_clicked()
{
    QString save("Data/sevilla.txt");
    setSelect(select, 7, save);
}

void EditChooseTeam::on_benfica_clicked()
{
    QString save("Data/benfica.txt");
    setSelect(select, 8, save);
}

void EditChooseTeam::on_chelsea_clicked()
{
    QString save("Data/chelsea.txt");
    setSelect(select, 9, save);
}

void EditChooseTeam::on_arsenal_clicked()
{
    QString save("Data/arsenal.txt");
    setSelect(select, 10, save);
}

void EditChooseTeam::on_manchester_city_clicked()
{
    QString save("Data/manchester_c.txt");
    setSelect(select, 11, save);
}

void EditChooseTeam::on_porto_clicked()
{
    QString save("Data/porto.txt");
    setSelect(select, 12, save);
}

void EditChooseTeam::on_schalke_clicked()
{
    QString save("Data/schalke.txt");
    setSelect(select, 13, save);
}

void EditChooseTeam::on_manu_clicked()
{
    QString save("Data/manu.txt");
    setSelect(select, 14, save);
}

void EditChooseTeam::on_napoli_clicked()
{
    QString save("Data/napoli.txt");
    setSelect(select, 15, save);
}

void EditChooseTeam::on_edit_clicked()
{
    emit dialogClicked();

    // Edit edit;
   // EditChooseTeam::close();
    // edit.exec();
}

void EditChooseTeam::bakToMainMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
}

