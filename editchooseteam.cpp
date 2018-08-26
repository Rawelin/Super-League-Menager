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
}

EditChooseTeam::~EditChooseTeam()
{
    delete ui;
    //delete music;
    delete palette;
}
void EditChooseTeam::setImages()
{
    palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Stadiony/slask.jpg")))));
    setPalette(*palette);

    ui->edit->setStyleSheet("background-color: rgba(255, 255, 255, 70);");

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
        container->functions->delay(100);
        AddPlayer addplayer(0, team_number, save);
        EditChooseTeam::close();
        addplayer.exec();
    }

    if(select == 2)
    {
        container->functions->delay(100);
        RemovePlayer removeplayer(0, team_number, save);
        EditChooseTeam::close();
        removeplayer.exec();  
    }
    if(select == 3)
    {
        container->functions->delay(100);
        EditPlayer editplayer(0, team_number, save);
        EditChooseTeam::close();
        editplayer.exec();  
    }
}


void EditChooseTeam::on_real_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/real.txt");
    setSelect(select, 0, save);
}

void EditChooseTeam::on_bayern_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/bayern.txt");
    setSelect(select, 1, save);
}

void EditChooseTeam::on_barcelona_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/barcelona.txt");
    setSelect(select, 2, save);
}

void EditChooseTeam::on_atletico_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/atletico.txt");
    setSelect(select, 3, save);
}

void EditChooseTeam::on_juventus_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/juventus.txt");
    setSelect(select, 4, save);
}

void EditChooseTeam::on_psg_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/psg.txt");
    setSelect(select, 5, save);
}

void EditChooseTeam::on_borusia_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/borussia.txt");
    setSelect(select, 6, save);
}

void EditChooseTeam::on_sevila_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/sevilla.txt");
    setSelect(select, 7, save);
}

void EditChooseTeam::on_benfica_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/benfica.txt");
    setSelect(select, 8, save);
}

void EditChooseTeam::on_chelsea_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/chelsea.txt");
    setSelect(select, 9, save);
}

void EditChooseTeam::on_arsenal_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/arsenal.txt");
    setSelect(select, 10, save);
}

void EditChooseTeam::on_manchester_city_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/manchester_c.txt");
    setSelect(select, 11, save);
}

void EditChooseTeam::on_porto_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/porto.txt");
    setSelect(select, 12, save);
}

void EditChooseTeam::on_schalke_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/schalke.txt");
    setSelect(select, 13, save);
}

void EditChooseTeam::on_manu_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/manu.txt");
    setSelect(select, 14, save);
}

void EditChooseTeam::on_napoli_clicked()
{
    QString save("/Programowanie/Qt C++/Qt Super League/Super League/Data/napoli.txt");
    setSelect(select, 15, save);
}

void EditChooseTeam::on_edit_clicked()
{
    Edit edit;
    EditChooseTeam::close();
    edit.exec();
}

