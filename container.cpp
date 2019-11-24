#include "container.h"

Container::Container()
{

}

Container::~Container()
{
    delete league;
    delete music_player;
    delete matchAlgo;
    delete userData;
    delete versus;
    delete artificial;
    delete set_multimedia;
}

void Container::loadDefaultData()
{
    league = new League();
    music_player = new MusicPlayer();
    versus = new Versus(1);
    userData = new UserData();
    artificial = new ArtificialIntelligence();
    matchAlgo = new MatchAlgorithms();
    set_multimedia = new SetMultimedia();

    teams.clear();

    set_multimedia->setDefaultTeamDataPath();

    Serialization serialization;

    serialization.loadTeam(set_multimedia->getDefaultDataTeams(0), teams);


    for(int i = 0; i < teams.size(); i++)
        serialization.loadSquadGame(set_multimedia->getDefaultPlayers(i), player, teams);

    set_multimedia->setRealFotos(teams);
    set_multimedia->setTeamTshirt(teams);
    set_multimedia->setTeamIcon(teams);
    set_multimedia->setSavedTeamDataPath();
    set_multimedia->setStadiumData(teams);

   //qSort(teams.begin(), teams.end(), [](const Team &t1, const Team &t2)->bool{
   //                                     return ((t1.getName() > t2.getName()) );});

}



void Container::saveData()
{
    Serialization serialization;

    for(int i = 0; i < teams.size(); i++)
        serialization.saveSquadGame(set_multimedia->getSavedPlayersList(i), teams);

    serialization.saveTeam(set_multimedia->getSavedSLData(0), teams);
    serialization.saveLeague(set_multimedia->getSavedSLData(1), league);
    serialization.saveUserData(set_multimedia->getSavedSLData(2), userData);
}

void Container::loadData()
{
    teams.clear();

    set_multimedia->setSavedTeamDataPath();

    Serialization serialization;

    serialization.loadTeam(set_multimedia->getSavedSLData(0), teams);

    for(int i = 0; i < teams.size(); i++)
        serialization.loadSquadGame(set_multimedia->getSavedPlayersList(i), player, teams);

    serialization.loadLeague(set_multimedia->getSavedSLData(1), league);
    serialization.loadUsetData(set_multimedia->getSavedSLData(2), userData);

  //  set_multimedia->setRealFotos(teams);
    set_multimedia->setTeamTshirt(teams);
    set_multimedia->setTeamIcon(teams);
    set_multimedia->setStadiumData(teams);
}

void Container::memeoryHarvester()
{
    delete league;
    delete music_player;
    delete matchAlgo;
    delete userData;
    delete versus;
    delete artificial;
    delete set_multimedia;
}





