#ifndef SETMULTIMEDIA_H
#define SETMULTIMEDIA_H

#include <QtWidgets>
#include "container.h"
#include "team.h"
#include "stadium.h"

class SetMultimedia
{
private:
    QList<QPixmap> players_button;
    QList<QPixmap> logos;
    QStringList saved_players_list;
    QStringList saved_teams_leagues_users;
    QStringList default_players;
    QStringList default_data_teams;

public:
    SetMultimedia();
    void setRealFotos(QList<Team> &);
    void setTeamTshirt(QList<Team> &);
    void setTeamIcon(QList<Team> &);
    void setMusicPlayersButton();
    void setSavedTeamDataPath();
    void setDefaultTeamDataPath();
    void setStadiumData(QList<Team> &);

    QPixmap getButtons(int i){return players_button[i];}
    QPixmap getLogo(int i){return logos[i];}

    QString getSavedPlayersList(int i){return saved_players_list[i];}
    QString getSavedSLData(int i){return saved_teams_leagues_users[i];}
    QString getDefaultPlayers(int i){return default_players[i];}
    QString getDefaultDataTeams(int i){return default_data_teams[i];}
};

#endif // SETMULTIMEDIA_H
