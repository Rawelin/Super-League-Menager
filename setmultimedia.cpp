#include "setmultimedia.h"
#include <QDebug>

extern Container *container;


SetMultimedia::SetMultimedia()
{
    setMusicPlayersButton();
}

void SetMultimedia::setRealFotos(QList<Team> &teams)
{
    QString path("Players/Real/");

    QString navas(path + "navas.png");
    QString marcelo(path +"marcelo.png");
    QString ramos(path +"ramos.png");
    QString varane(path +"varane.png");
    QString carvajal(path +"carvajal.png");
    QString kroos(path +"kroos.png");
    QString casemiro(path +"casemiro.png");
    QString modric(path +"modric.png");
    QString bale(path +"bale.png");
    QString ronaldo(path +"ronaldo.png");
    QString benzema(path +"benzema.png");
    QString casilla(path +"casilla.png");
    QString isco(path +"isco.png");
    QString vasquez(path +"vasquez.png");
    QString assensio(path +"assensio.png");
    QString danilo(path +"danilo.png");
    QString nacho(path +"nacho.png");

    QStringList players_fotos;
    players_fotos << navas << marcelo << ramos << varane << carvajal << kroos << casemiro << modric << bale << ronaldo
                  << benzema << casilla << isco << vasquez << assensio << danilo << nacho;

    for(int i = 0; i < players_fotos.size(); i++)
        teams[0].getPlayer()[i].setFotoPath(players_fotos[i]);
}

void SetMultimedia::setTeamTshirt(QList<Team> &teams)
{
    QPixmap real("Tshirts/real.png");
    QPixmap bayern("Tshirts/bayern.png");
    QPixmap barcelona("Tshirts/barcelona.png");
    QPixmap atletico("Tshirts/atletico.png");
    QPixmap juventus("Tshirts/juventus.png");
    QPixmap psg("Tshirts/psg.png");
    QPixmap borussia("Tshirts/borussia.png");
    QPixmap sevilla("Tshirts/sevilla.png");
    QPixmap benfica("Tshirts/benfica.png");
    QPixmap chelsea("Tshirts/chelsea.png");
    QPixmap arsenal("Tshirts/arsenal.png");
    QPixmap manchester_c("Tshirts/manchester city.png");
    QPixmap porto("Tshirts/porto.png");
    QPixmap schalke("Tshirts/schalke.png");
    QPixmap manu("Tshirts/manu.png");
    QPixmap napoli("Tshirts/napoli.png");

    QList<QPixmap> team_tshirt;

    team_tshirt << real << bayern << barcelona << atletico << juventus << psg << borussia << sevilla << benfica
                << chelsea << arsenal << manchester_c << porto << schalke << manu << napoli;

    for(int i = 0; i < team_tshirt.size(); ++i)
        teams[i].setTshirt(team_tshirt[i]);
}

void SetMultimedia::setTeamIcon(QList<Team> &teams)
{
    QPixmap real("Herby/real.png");
    QPixmap bayern("Herby/bayern.png");
    QPixmap barcelona("Herby/barcelona.png");
    QPixmap atletico("Herby/atletico.png");
    QPixmap juventus("Herby/juventus.png");
    QPixmap psg("Herby/psg.png");
    QPixmap borussia("Herby/borussia.png");
    QPixmap sevilla("Herby/sevilla.png");
    QPixmap benfica("Herby/benfica.png");
    QPixmap chelsea("Herby/chelsea.png");
    QPixmap arsenal("Herby/arsenal.png");
    QPixmap manchester_c("Herby/manchester city.png");
    QPixmap porto("Herby/porto.png");
    QPixmap schalke("Herby/schalke.png");
    QPixmap manu("Herby/manu.png");
    QPixmap napoli("Herby/napoli.png");

    logos << real << bayern << barcelona << atletico << juventus << psg << borussia << sevilla << benfica
           << chelsea << arsenal << manchester_c << porto << schalke << manu << napoli;

    for(int i = 0; i < teams.size(); ++i)
        teams[i].setLogo(logos[i]);
}

void SetMultimedia::setMusicPlayersButton()
{
    QPixmap forward("Ico/forward.png");
    QPixmap backward("Ico/rewind.png");
    QPixmap play_music("Ico/play.png");
    QPixmap stop_music("Ico/stop.png");
    QPixmap pause_music("Ico/pause.png");
    QPixmap down_volume("Ico/dawn.png");
    QPixmap up_volume("Ico/up.png");

    players_button << forward << backward << play_music << stop_music << pause_music << down_volume
                   << up_volume;
}

void SetMultimedia::setSavedTeamDataPath()
{
    QString team_path_save("Save/teams.txt");
    QString league_path_save("Save/league.txt");
    QString user_path_save("Save/user.txt");

    QString real("Save/real.txt");
    QString bayern("Save/bayern.txt");
    QString barcelona("Save/barcelona.txt");
    QString atletico("Save/atletico.txt");
    QString juventus("Save/juventus.txt");
    QString psg("Save/psg.txt");
    QString borussia("Save/borusia.txt");
    QString sevilla("Save/sevilla.txt");
    QString benfica("Save/benfica.txt");
    QString chelsea("Save/chelsea.txt");
    QString arsenal("Save/arsenal.txt");
    QString manchester_c("Save/manchester_c.txt");
    QString porto("Save/porto.txt");
    QString schalke("Save/schalke.txt");
    QString manu("Save/manu.txt");
    QString napoli("Save/napoli.txt");

    saved_players_list << real << bayern << barcelona << atletico << juventus << psg << borussia << sevilla << benfica
                     << chelsea << arsenal << manchester_c << porto << schalke << manu << napoli;

    saved_teams_leagues_users << team_path_save << league_path_save << user_path_save;
}

void SetMultimedia::setDefaultTeamDataPath()
{
    QString real("Data/real.txt");
    QString bayern("Data/bayern.txt");
    QString barcelona("Data/barcelona.txt");
    QString atletico("Data/atletico.txt");
    QString juventus("Data/juventus.txt");
    QString psg("Data/psg.txt");
    QString borussia("Data/borussia.txt");
    QString sevilla("Data/sevilla.txt");
    QString benfica("Data/benfica.txt");
    QString chelsea("Data/chelsea.txt");
    QString arsenal("Data/arsenal.txt");
    QString manchester_c("Data/manchester_c.txt");
    QString porto("Data/porto.txt");
    QString schalke("Data/schalke.txt");
    QString manu("Data/manu.txt");
    QString napoli("Data/napoli.txt");

    default_players << real << bayern << barcelona << atletico << juventus << psg << borussia << sevilla
                    << benfica << chelsea << arsenal << manchester_c << porto << schalke << manu << napoli;

    //QString team_path("/Programowanie/Qt C++/Qt Super League/Super League/Data/teams.txt");
    QString team_path("Data/teams.txt");   // wszystkie pliki tak przerobic dla Release

    default_data_teams << team_path;
}

void SetMultimedia::setStadiumData(QList<Team> &teams)
{
    QPixmap realt("Stadiony/realt.jpg");
    QPixmap bayernt("Stadiony/bayernt.jpg");
    QPixmap barcat("Stadiony/barcat.jpg");
    QPixmap atleticot("Stadiony/atleticot.jpg");
    QPixmap juventust("Stadiony/juventust.jpg");
    QPixmap psgt("Stadiony/psgt.jpg");
    QPixmap borusiat("Stadiony/borusiat.jpg");
    QPixmap sevillat("Stadiony/sevillat.jpg");


    Stadium real("Santiago Bernabéu", 81004, realt);
    Stadium bayern("Allianz Arena", 75024, bayernt);
    Stadium barca("Camp Nou", 99354, barcat);
    Stadium atletico("Wanda Metropolitano", 68000, atleticot);
    Stadium juventus("Allianz Stadium", 41254, juventust);
    Stadium psg("Parc des Princes", 47929, psgt);
    Stadium borusia("Signal Iduna Park", 81359, borusiat);
    Stadium sevilla("Estadio Ramón Sánchez Pizjuán", 45500, sevillat);


    QList<Stadium> stadium;

    stadium << real << bayern << barca << atletico << juventus << psg << borusia << sevilla;

    for(int i = 0; i < stadium.size(); i++)
        teams[i].setStadium(stadium[i]);

}
