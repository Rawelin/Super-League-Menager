#include "container.h"

Container::Container()
{

}

Container::~Container()
{
    delete league;
    delete musicPlayer;
    delete matchAlgoritm;
    delete userData;
    delete versus;
    delete artificialInteligence;
    delete setMultimedia;
}

void Container::loadDefaultData()
{
    league = new League();
    musicPlayer = new MusicPlayer();
    versus = new Versus(1);
    userData = new UserData();
    artificialInteligence = new ArtificialIntelligence();
    matchAlgoritm = new MatchAlgorithms();
    setMultimedia = new SetMultimedia();

    teams.clear();

    setMultimedia->setDefaultTeamDataPath();

    Serialization serialization;

    serialization.loadTeam(setMultimedia->getDefaultDataTeams(0), teams);


    for(int i = 0; i < teams.size(); i++)
        serialization.loadSquadGame(setMultimedia->getDefaultPlayers(i), player, teams);

    setMultimedia->setRealFotos(teams);
    setMultimedia->setTeamTshirt(teams);
    setMultimedia->setTeamIcon(teams);
    setMultimedia->setSavedTeamDataPath();
    setMultimedia->setStadiumData(teams);

   //qSort(teams.begin(), teams.end(), [](const Team &t1, const Team &t2)->bool{
   //                                     return ((t1.getName() > t2.getName()) );});

   //std::random_shuffle(teams.begin(), teams.end());

}



void Container::saveData()
{
    Serialization serialization;

    for(int i = 0; i < teams.size(); i++)
        serialization.saveSquadGame(setMultimedia->getSavedPlayersList(i), teams);

    serialization.saveTeam(setMultimedia->getSavedSLData(0), teams);
    serialization.saveLeague(setMultimedia->getSavedSLData(1), league);
    serialization.saveUserData(setMultimedia->getSavedSLData(2), userData);
}

void Container::loadData()
{
    teams.clear();

    setMultimedia->setSavedTeamDataPath();

    Serialization serialization;

    serialization.loadTeam(setMultimedia->getSavedSLData(0), teams);

    for(int i = 0; i < teams.size(); i++)
        serialization.loadSquadGame(setMultimedia->getSavedPlayersList(i), player, teams);

    serialization.loadLeague(setMultimedia->getSavedSLData(1), league);
    serialization.loadUsetData(setMultimedia->getSavedSLData(2), userData);

  //  set_multimedia->setRealFotos(teams);
    setMultimedia->setTeamTshirt(teams);
    setMultimedia->setTeamIcon(teams);
    setMultimedia->setStadiumData(teams);
}

void Container::memeoryHarvester()
{
    delete league;
    delete musicPlayer;
    delete matchAlgoritm;
    delete userData;
    delete versus;
    delete artificialInteligence;
    delete setMultimedia;
}





