#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <QWidget>
#include <QMessageBox>
#include "player.h"
#include "team.h"
#include "myexception.h"
#include "league.h"
#include "userdata.h"

class Player;
class Team;
class League;
class UserData;

class Serialization
{
public:
    Serialization();

    void saveSquad(const QString &save_path, QVector<Player> &player);
    void loadSquad(const QString &load_path, QVector<Player> &player);
    void loadSquadGame(const QString &load_path, QVector<QVector<Player>> &player, QList<Team> &team);
    void saveSquadGame(const QString &save_path, QList<Team> &team);
    void saveTeam(const QString &save_path, QList<Team> &team);
    void loadTeam(const QString &load_path, QList<Team> &team);
    void saveLeague(const QString &save_path, League *league);
    void loadLeague(const QString &load_path, League *league);
    void saveUserData(const QString &save_path, UserData *userData);
    void loadUsetData(const QString &load_path, UserData *userData);

private:
   int counter;
   int id;
};

#endif // SERIALIZATION_H
