#include <QDebug>
#include "choseteam.h"
#include "ui_choseteam.h"

extern Container *container;

ChoseTeam::ChoseTeam(QDialog *parent) :QDialog(parent),
    ui(new Ui::ChoseTeam)
{
     setWindowFlags(Qt::WindowTitleHint);
   //  setAttribute(Qt::WA_DeleteOnClose);

     ui->setupUi(this);
     this->showFullScreen();

     mouseTracking();
     setImages();

     // container->music_player->stop();
     // container->music_player->setPlayer();
     // container->music_player->setTrack(5);
    //  container->music_player->start();

     showteamstats = new ShowTeamStats(this);
     showplayerstats = new ShowPlayerStats(this);

     connect(this, SIGNAL(hovered()), this, SLOT(highLight()));

}
ChoseTeam::~ChoseTeam()
{
    delete ui;
    delete showteamstats;
    delete showplayerstats;
}

void ChoseTeam::setImages()
{

   // music.setMedia(QUrl("/ManagerPl/Sound/kalimba.mp3"));
   // music.setMedia(QUrl("/Programowanie/Qt C++/Qt Manager Project/ManagerPl/Sound/kalimba.mp3"));

   // music.play();

    QPixmap bkgnd("Stadiony/realfuture.jpg");

    container->functions->setBackground(this, bkgnd);

    //setStyleSheet("background-image: url(/Programowanie/Qt C++/Qt Manager Project/ManagerPl/Stadiony/lech2.jpg)");

     QList<QPair<QPushButton*, int> > teamLabels;

     teamLabels.append(qMakePair(ui->real, 0));
     teamLabels.append(qMakePair(ui->lech, 1));
     teamLabels.append(qMakePair(ui->legia, 2));
     teamLabels.append(qMakePair(ui->wisla, 3));
     teamLabels.append(qMakePair(ui->ruch, 4));
     teamLabels.append(qMakePair(ui->slask, 5));
     teamLabels.append(qMakePair(ui->lechia, 6));
     teamLabels.append(qMakePair(ui->termalica, 7));
     teamLabels.append(qMakePair(ui->piast, 8));
     teamLabels.append(qMakePair(ui->arka, 9));
     teamLabels.append(qMakePair(ui->cracovia, 10));
     teamLabels.append(qMakePair(ui->gornik_leczna, 11));
     teamLabels.append(qMakePair(ui->korona, 12));
     teamLabels.append(qMakePair(ui->pogon, 13));
     teamLabels.append(qMakePair(ui->wisla_plock, 14));
     teamLabels.append(qMakePair(ui->zaglebie, 15));

     for(int i = 0; i < teamLabels.size(); i++)
     {
         container->functions->setIcon(container->teams[container->teams[i].getTeamId()].getLogo(),
                                       teamLabels[container->teams[i].getTeamId()].first,
                                       container->teams[container->teams[i].getTeamId()].getName() + " " +
                                       container->teams[container->teams[i].getTeamId()].getCity());
     }


    //container->functions->setIcon(container->teams[1].getLogo(), ui->lech, container->teams[1].getName() + " " + container->teams[1].getCity());
   // container->functions->setIcon(container->teams[2].getLogo(), ui->legia, container->teams[2].getName() + " " + container->teams[2].getCity());
    //container->functions->setIcon(container->teams[3].getLogo(), ui->wisla, container->teams[3].getName() + " " + container->teams[3].getCity());
    //container->functions->setIcon(container->teams[4].getLogo(), ui->ruch, container->teams[4].getName() + " " + container->teams[4].getCity());
   // container->functions->setIcon(container->teams[5].getLogo(), ui->slask, container->teams[5].getName() + " " + container->teams[5].getCity());
   // container->functions->setIcon(container->teams[6].getLogo(), ui->lechia, container->teams[6].getName() + " " + container->teams[6].getCity());
   // container->functions->setIcon(container->teams[7].getLogo(), ui->termalica, container->teams[7].getName() + " " + container->teams[7].getCity());
   // container->functions->setIcon(container->teams[8].getLogo(), ui->piast, container->teams[8].getName() + " " + container->teams[8].getCity());
   // container->functions->setIcon(container->teams[9].getLogo(), ui->arka, container->teams[9].getName() + " " + container->teams[9].getCity());
   // container->functions->setIcon(container->teams[10].getLogo(), ui->cracovia, container->teams[10].getName() + " " + container->teams[10].getCity());
   // container->functions->setIcon(container->teams[11].getLogo(), ui->gornik_leczna, container->teams[11].getName() + " " + container->teams[11].getCity());
    //container->functions->setIcon(container->teams[12].getLogo(), ui->korona, container->teams[12].getName() + " " + container->teams[12].getCity());
  //  container->functions->setIcon(container->teams[13].getLogo(), ui->pogon, container->teams[13].getName() + " " + container->teams[13].getCity());
  //  container->functions->setIcon(container->teams[14].getLogo(), ui->wisla_plock, container->teams[14].getName() + " " + container->teams[14].getCity());
   // container->functions->setIcon(container->teams[15].getLogo(), ui->zaglebie, container->teams[15].getName() + " " + container->teams[15].getCity());
}

void ChoseTeam::mouseTracking()
{
    setMouseTracking(true);

    ui->real->setMouseTracking(true);
    ui->lech->setMouseTracking(true);
    ui->legia->setMouseTracking(true);
    ui->wisla->setMouseTracking(true);
    ui->ruch->setMouseTracking(true);
    ui->slask->setMouseTracking(true);
    ui->lechia->setMouseTracking(true);
    ui->termalica->setMouseTracking(true);
    ui->piast->setMouseTracking(true);
    ui->arka->setMouseTracking(true);
    ui->cracovia->setMouseTracking(true);
    ui->gornik_leczna->setMouseTracking(true);
    ui->korona->setMouseTracking(true);
    ui->pogon->setMouseTracking(true);
    ui->wisla_plock->setMouseTracking(true);
    ui->zaglebie->setMouseTracking(true);
}

void ChoseTeam::setAnimation()
{
    x = ui->wisla->pos().x() + 140;
    y = ui->wisla->pos().y() - 860;
    v = ui->real->pos().x() - 1350;
    z = ui->real->pos().y() - 120;


    showteamstats->move(x , y + 700);
    showplayerstats->move(v+ 700, z);
    container->functions->delay(1);


   // for(i = 0; i <= 700; i+= 3)
   // {
   //      showteamstats->move(x , y + i);
   //     showplayerstats->move(v+ i, z);
   //      container->functions->delay(1);
   // }
}

void ChoseTeam::getStats(QRect teamRect, int id)
{
//    if(teamRect.contains(QCursor::pos()))
//    {
//        container->functions->showTeamStats(showteamstats, teamRect, id);
//        container->functions->showPlayerStats(showplayerstats, teamRect, id);
//    }
//    else
//    {
//        showteamstats->setVisible(false);
//        showplayerstats->setVisible(false);
//        setAnimation();
//    }
}

void ChoseTeam::setUserData(int id)
{

    container->userData->setId(id);
    //container->music_player->stop();

    //UserDataDialog userdatadialog(this);
   // ChoseTeam::close();
   // userdatadialog.exec();

     emit dialogClickedGo();
}


void ChoseTeam::mouseMoveEvent(QMouseEvent *event)
{
    Q_EMIT hovered();
    QWidget::enterEvent(event);
}

void ChoseTeam::highLight()
{
    QRect jagieloniaIco = ui->real->geometry();
    QRect lechico = ui->lech->geometry();
    QRect legiaIco = ui->legia->geometry();
    QRect wislaIco = ui->wisla->geometry();
    QRect ruchIco = ui->ruch->geometry();
    QRect slaskIco = ui->slask->geometry();
    QRect lechiaIco = ui->lechia->geometry();
    QRect termalicaIco = ui->termalica->geometry();
    QRect piastIco = ui->piast->geometry();
    QRect arkaIco = ui->arka->geometry();
    QRect cracovaiIco = ui->cracovia->geometry();
    QRect gornik_lecznaIco = ui->gornik_leczna->geometry();
    QRect koronaIco = ui->korona->geometry();
    QRect pogonIco = ui->pogon->geometry();
    QRect wisla_plockIco = ui->wisla_plock->geometry();
    QRect zaglebie_ico = ui->zaglebie->geometry();

    QString highlight = "background-color: rgba(255, 255, 255, 100);";
    QString normal = "background-color: rgba(255, 255, 255, 10);";
    QString normal2 = "background-color: rgba(255, 255, 255, 30);";

    container->functions->setHighLight(jagieloniaIco, ui->real, highlight, normal);
    container->functions->setHighLight(lechico, ui->lech, highlight, normal);
    container->functions->setHighLight(legiaIco, ui->legia, highlight, normal);
    container->functions->setHighLight(wislaIco, ui->wisla, highlight, normal);
    container->functions->setHighLight(ruchIco, ui->ruch, highlight, normal);
    container->functions->setHighLight(slaskIco, ui->slask, highlight, normal);
    container->functions->setHighLight(lechiaIco, ui->lechia, highlight, normal);
    container->functions->setHighLight(termalicaIco, ui->termalica, highlight, normal);
    container->functions->setHighLight(piastIco, ui->piast, highlight, normal);
    container->functions->setHighLight(arkaIco, ui->arka, highlight, normal);
    container->functions->setHighLight(cracovaiIco, ui->cracovia, highlight, normal);
    container->functions->setHighLight(gornik_lecznaIco, ui->gornik_leczna, highlight, normal);
    container->functions->setHighLight(koronaIco, ui->korona, highlight, normal);
    container->functions->setHighLight(pogonIco, ui->pogon, highlight, normal);
    container->functions->setHighLight(wisla_plockIco, ui->wisla_plock, highlight, normal);
    container->functions->setHighLight(zaglebie_ico, ui->zaglebie, highlight, normal);

    /*getStats(jagieloniaIco, 0);
    getStats(lechiaIco, 1);
    getStats(legiaIco, 2);
    getStats(wislaIco, 3);
    getStats(ruchIco, 4);
    getStats(slaskIco, 5);
    getStats(lechiaIco, 6);
    getStats(termalicaIco, 7);
    getStats(piastIco, 8);
    getStats(arkaIco, 9);
    getStats(cracovaiIco, 10);
    getStats(gornik_lecznaIco, 11);
    getStats(koronaIco, 12);
    getStats(pogonIco, 13);
    getStats(jagieloniaIco, 14);
    getStats(wisla_plockIco, 15);
    getStats(zaglebie_ico, 16);*/

    if(jagieloniaIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, jagieloniaIco, 0);
        container->functions->showPlayerStats(showplayerstats, jagieloniaIco, container->teams[0].getTeamId());
        qDebug() << "tram" << container->teams[0].getTeamId();
    }

    else if(lechico.contains(QCursor::pos()))
    {

        container->functions->showTeamStats(showteamstats, lechico, 1);
        container->functions->showPlayerStats(showplayerstats, lechico, container->teams[1].getTeamId());
    }
    else if(legiaIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, legiaIco, 2);
        container->functions->showPlayerStats(showplayerstats, legiaIco, container->teams[2].getTeamId());
    }
    else if(wislaIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, wislaIco, 3);
        container->functions->showPlayerStats(showplayerstats, wislaIco, container->teams[3].getTeamId());
    }
    else if(ruchIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, ruchIco, 4);
        container->functions->showPlayerStats(showplayerstats, ruchIco, container->teams[4].getTeamId());
    }
    else if(slaskIco.contains(QCursor::pos()))
    {
         container->functions->showTeamStats(showteamstats, slaskIco, 5);
         container->functions->showPlayerStats(showplayerstats, slaskIco, container->teams[5].getTeamId());
    }
    else if(lechiaIco.contains(QCursor::pos()))
    {
          container->functions->showTeamStats(showteamstats, lechiaIco, 6);
          container->functions->showPlayerStats(showplayerstats, lechiaIco, container->teams[6].getTeamId());
    }
    else if(termalicaIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, termalicaIco, 7);
        container->functions->showPlayerStats(showplayerstats, termalicaIco, container->teams[7].getTeamId());
    }
    else if(piastIco.contains(QCursor::pos()))
    {
         container->functions->showTeamStats(showteamstats, piastIco, 8);
         container->functions->showPlayerStats(showplayerstats, piastIco, container->teams[8].getTeamId());
    }
    else if(arkaIco.contains(QCursor::pos()))
    {
         container->functions->showTeamStats(showteamstats, arkaIco, 9);
         container->functions->showPlayerStats(showplayerstats, arkaIco, container->teams[9].getTeamId());
    }
    else if(cracovaiIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, cracovaiIco, 10);
        container->functions->showPlayerStats(showplayerstats, cracovaiIco, container->teams[10].getTeamId());
    }
    else if(gornik_lecznaIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, gornik_lecznaIco, 11);
        container->functions->showPlayerStats(showplayerstats, gornik_lecznaIco, container->teams[11].getTeamId());
    }
    else if(koronaIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, koronaIco, 12);
        container->functions->showPlayerStats(showplayerstats, koronaIco, container->teams[12].getTeamId());
    }
    else if(pogonIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, pogonIco, 13);
        container->functions->showPlayerStats(showplayerstats, pogonIco, container->teams[13].getTeamId());
    }
    else if(wisla_plockIco.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, wisla_plockIco, 14);
        container->functions->showPlayerStats(showplayerstats, wisla_plockIco, container->teams[14].getTeamId());
    }
    else if(zaglebie_ico.contains(QCursor::pos()))
    {
        container->functions->showTeamStats(showteamstats, zaglebie_ico, 15);
        container->functions->showPlayerStats(showplayerstats, zaglebie_ico, container->teams[15].getTeamId());
    }
    else
    {
        showteamstats->setVisible(false);
        showplayerstats->setVisible(false);
        setAnimation();
    }
}

void ChoseTeam::on_real_clicked()
{
    setUserData(container->teams[0].getTeamId());
}
void ChoseTeam::on_lech_clicked()
{
    setUserData(container->teams[1].getTeamId());
}

void ChoseTeam::on_legia_clicked()
{
    setUserData(container->teams[2].getTeamId());
}

void ChoseTeam::on_wisla_clicked()
{
    setUserData(container->teams[3].getTeamId());
}

void ChoseTeam::on_ruch_clicked()
{
     setUserData(container->teams[4].getTeamId());
}

void ChoseTeam::on_slask_clicked()
{
     setUserData(container->teams[5].getTeamId());
}

void ChoseTeam::on_lechia_clicked()
{
     setUserData(container->teams[6].getTeamId());
}

void ChoseTeam::on_termalica_clicked()
{
    setUserData(container->teams[7].getTeamId());
}

void ChoseTeam::on_piast_clicked()
{
     setUserData(container->teams[8].getTeamId());
}

void ChoseTeam::on_arka_clicked()
{
     setUserData(container->teams[9].getTeamId());
}

void ChoseTeam::on_cracovia_clicked()
{
     setUserData(container->teams[10].getTeamId());
}

void ChoseTeam::on_gornik_leczna_clicked()
{
     setUserData(container->teams[11].getTeamId());
}

void ChoseTeam::on_korona_clicked()
{
     setUserData(container->teams[12].getTeamId());
}

void ChoseTeam::on_pogon_clicked()
{
     setUserData(container->teams[13].getTeamId());
}

void ChoseTeam::on_wisla_plock_clicked()
{
     setUserData(container->teams[14].getTeamId());
}

void ChoseTeam::on_zaglebie_clicked()
{
    setUserData(container->teams[15].getTeamId());
}




