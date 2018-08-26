#ifndef CONTAINER_H
#define CONTAINER_H

#include "team.h"
#include "player.h"
#include "serialization.h"
#include "league.h"
#include "musicplayer.h"
#include "livematch.h"
#include "functions.h"
#include "matchsimulation.h"
#include "serialization.h"
#include "usersquad.h"
#include "versus.h"
#include "showteam.h"
#include "userdata.h"
#include "artificialintelligence.h"
#include "matchalgorithms.h"
#include "hovered.h"
#include "formations.h"
#include "setmultimedia.h"


class League;
class LiveMatch;
class MusicPlayer;
class MatchSimulation;
class Serialization;
class UserSquad;
class Versus;
class Functions;
class ShowTeamStats;
class UserData;
class ArtificialIntelligence;
class MatchAlgorithms;
class SetMultimedia;


class Container
{

public:
    Container();
    ~Container();
    QVector<QVector<Player>> player;
    QList<Team> teams;
    League *league;
    MusicPlayer *music_player;
    Functions *functions;
    MatchSimulation *matchsimulation;
    Serialization *serialization;
    Versus *versus;
    ShowTeamStats *showteamstats;
    UserData *userData;
    ArtificialIntelligence *artificial;
    MatchAlgorithms *matchAlgo;
    Hovered *hovered;
    Formations *formations;
    SetMultimedia *set_multimedia;

    void loadDefaultData();
    void saveData();
    void loadData();
    void memeoryHarvester();

};

#endif // CONTAINER_H
