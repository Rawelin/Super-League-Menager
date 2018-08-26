#include "selectshowsquad.h"
#include "ui_selectshowsquad.h"

extern Container *container;

SelectShowSquad::SelectShowSquad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectShowSquad)
{
    ui->setupUi(this);
    this->showFullScreen();

    setImages();
}

SelectShowSquad::~SelectShowSquad()
{
    delete ui;
}

void SelectShowSquad::setImages()
{

    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    ui->back->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    buttons << ui->jagielonia << ui->lech << ui->legia << ui->wisla << ui->ruch << ui->slask << ui->lechia << ui->gornik_leczna
            << ui->piast << ui->arka << ui->cracovia << ui->termalica << ui->korona << ui->pogon << ui->wisla_plock << ui->zaglebie;

    for(int i = 0; i < buttons.size(); i++)
        container->functions->setIcon(container->teams[i].getLogo(), buttons[i], container->teams[i].getName() + " " +
                                      container->teams[i].getCity());
}

void SelectShowSquad::on_jagielonia_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[0].getName()+ " " +
                        container->teams[0].getCity(), 0);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_lech_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[1].getName()+ " " +
                        container->teams[1].getCity(), 1);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_legia_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[2].getName()+ " " +
                        container->teams[2].getCity(), 2);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_wisla_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[3].getName()+ " " +
                        container->teams[3].getCity(), 3);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_ruch_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[4].getName()+ " " +
                        container->teams[4].getCity(), 4);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_slask_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[5].getName()+ " " +
                        container->teams[5].getCity(), 5);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_lechia_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[6].getName()+ " " +
                        container->teams[6].getCity(), 6);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_gornik_leczna_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[7].getName()+ " " +
                        container->teams[7].getCity(), 7);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_piast_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[8].getName()+ " " +
                        container->teams[8].getCity(), 8);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_arka_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[9].getName()+ " " +
                        container->teams[9].getCity(), 9);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_cracovia_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[10].getName()+ " " +
                        container->teams[10].getCity(), 10);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_termalica_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[11].getName()+ " " +
                        container->teams[11].getCity(), 11);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_korona_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[12].getName()+ " " +
                        container->teams[12].getCity(), 12);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_pogon_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[13].getName()+ " " +
                        container->teams[13].getCity(), 13);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_wisla_plock_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[14].getName()+ " " +
                        container->teams[14].getCity(), 14);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_zaglebie_clicked()
{
    container->functions->delay(100);
    ShowSquads squad(0, container->teams[15].getName()+ " " +
                        container->teams[15].getCity(), 15);
    squad.setModal(true);
    squad.exec();
}

void SelectShowSquad::on_back_clicked()
{
    SelectShowSquad::close();
}

