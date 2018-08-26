#include "serialization.h"
#include <QDebug>
#include <QException>
#include <QMessageBox>

Serialization::Serialization()
{
    counter = 0;
    id = 0;
}

void Serialization::saveSquad(const QString &save_path, QVector<Player> &player)
{
     // QFile file("/Data/a.txt");                                            // dziala dla Debug
    QFile file(save_path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
         return;
    }
    else
    {
        QTextStream out(&file);

        for(int i = 0; i < player.size(); ++i)
        {
            out << player[i].getId() << "\n";
            out << player[i].getFname() << "\n";
            out << player[i].getLname() << "\n";
            out << player[i].getNationality() << "\n";
            out << player[i].getAge() << "\n";
            out << player[i].getPosition() << "\n";
            out << player[i].getGkeeper() << "\n";
            out << player[i].getDefence() << "\n";
            out << player[i].getMidfield() << "\n";
            out << player[i].getAttack() << "\n";
            out << player[i].getTackle() << "\n";
            out << player[i].getTechnik() << "\n";
            out << player[i].getShot() << "\n";
            out << player[i].getPass() << "\n";
            out << player[i].getHeader() << "\n";
            out << player[i].getSpeed() << "\n";
            out << player[i].getEndurance() << "\n";
            out << player[i].getGoals() << "\n";
            out << player[i].getStamina() << "\n";
            out << player[i].getFotoPath() << "\n";
        }

        file.flush();
        file.close();
    }


}

void Serialization::loadSquad(const QString &load_path, QVector<Player> &player)
{
    try
    {
        Player tmp;
         // QFile file("/Data/a.txt");                                            // dziala dla Debug
        QFile file(load_path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
              throw  MyException();
        }
        else
        {
            QTextStream in(&file);

            while (!in.atEnd())
            {
                  QString line1 = in.readLine();
                  QString line2 = in.readLine();
                  QString line3 = in.readLine();
                  QString line4 = in.readLine();
                  QString line5 = in.readLine();
                  QString line6 = in.readLine();
                  QString line7 = in.readLine();
                  QString line8 = in.readLine();
                  QString line9 = in.readLine();
                  QString line10 = in.readLine();
                  QString line11 = in.readLine();
                  QString line12 = in.readLine();
                  QString line13 = in.readLine();
                  QString line14 = in.readLine();
                  QString line15 = in.readLine();
                  QString line16 = in.readLine();
                  QString line17 = in.readLine();
                  QString line18 = in.readLine();
                  QString line19 = in.readLine();
                  QString line20 = in.readLine();

                  tmp.setId(line1.toInt());
                  tmp.setFname(line2);
                  tmp.setLname(line3);
                  tmp.setNationality(line4);
                  tmp.setAge(line5.toInt());
                  tmp.setPosition(line6);
                  tmp.setGkeeper(line7.toDouble());
                  tmp.setDefence(line8.toDouble());
                  tmp.setMidfield(line9.toDouble());
                  tmp.setAttack(line10.toDouble());
                  tmp.setTackle(line11.toDouble());
                  tmp.setTechnik(line12.toDouble());
                  tmp.setShot(line13.toDouble());
                  tmp.setPass(line14.toDouble());
                  tmp.setHeader(line15.toDouble());
                  tmp.setSpeed(line16.toDouble());
                  tmp.setEndurance(line17.toDouble());
                  tmp.setGoals2(line18.toInt());
                  tmp.setStamina(line19.toDouble());
                  tmp.setFotoPath(line20);

                  player.push_back(tmp);
            }
        }
        file.close();
    }
    catch(MyException &e)
    {
        qDebug() << "Nie odnalezono pliku " << load_path;
        QMessageBox::critical(0, "Błąd krytyczny", e.player_what() + load_path);
        exit(0);
    }
    catch(QException &e)
    {
        qDebug() << "Wyjatek " << e.what();
    }
}

void Serialization::loadSquadGame(const QString &load_path, QVector<QVector<Player> > &player, QList<Team> &team)
{

    try
    {
        Player tmp;
        QVector <Player> vectmp;
         // QFile file("/Data/a.txt");                                            // dziala dla Debug
        QFile file(load_path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
               throw  MyException();
        }
        else
        {
            QTextStream in(&file);

            while (!in.atEnd())
            {
                QString line1 = in.readLine();
                QString line2 = in.readLine();
                QString line3 = in.readLine();
                QString line4 = in.readLine();
                QString line5 = in.readLine();
                QString line6 = in.readLine();
                QString line7 = in.readLine();
                QString line8 = in.readLine();
                QString line9 = in.readLine();
                QString line10 = in.readLine();
                QString line11 = in.readLine();
                QString line12 = in.readLine();
                QString line13 = in.readLine();
                QString line14 = in.readLine();
                QString line15 = in.readLine();
                QString line16 = in.readLine();
                QString line17 = in.readLine();
                QString line18 = in.readLine();
                QString line19 = in.readLine();
                QString line20 = in.readLine();

                tmp.setId(line1.toInt());
                tmp.setFname(line2);
                tmp.setLname(line3);
                tmp.setNationality(line4);
                tmp.setAge(line5.toInt());
                tmp.setPosition(line6);
                tmp.setGkeeper(line7.toDouble());
                tmp.setDefence(line8.toDouble());
                tmp.setMidfield(line9.toDouble());
                tmp.setAttack(line10.toDouble());
                tmp.setTackle(line11.toDouble());
                tmp.setTechnik(line12.toDouble());
                tmp.setShot(line13.toDouble());
                tmp.setPass(line14.toDouble());
                tmp.setHeader(line15.toDouble());
                tmp.setSpeed(line16.toDouble());
                tmp.setEndurance(line17.toDouble());
                tmp.setGoals2(line18.toInt());
                tmp.setStamina(line19.toDouble());
                tmp.setFotoPath(line20);

                vectmp.push_back(tmp);
                team[counter].setPlayer(tmp);     // wersja team-player
            }

            player.push_back(vectmp);             // wersja player-player
            file.close();

            counter++;
        }


    }

    catch(MyException &e)
    {
        qDebug() << "Nie odnalezono pliku " << load_path;
        QMessageBox::critical(0, "Błąd krytyczny", e.player_what() + load_path);
        exit(0);
    }
    catch(QException &e)
    {
        qDebug() << "Wyjatek " << e.what();
    }

}

void Serialization::saveSquadGame(const QString &save_path, QList<Team> &team)
{

    // QFile file("/Data/a.txt");                                            // dziala dla Debug
    QFile file(save_path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
          return;
    }
    else
    {
        QTextStream out(&file);

        for(int i = 0; i < team[id].player.size(); ++i)
        {
            out << team[id].getPlayer()[i].getId() << "\n";
            out << team[id].getPlayer()[i].getFname() << "\n";
            out << team[id].getPlayer()[i].getLname() << "\n";
            out << team[id].getPlayer()[i].getNationality() << "\n";
            out << team[id].getPlayer()[i].getAge() << "\n";
            out << team[id].getPlayer()[i].getPosition() << "\n";
            out << team[id].getPlayer()[i].getGkeeper() << "\n";
            out << team[id].getPlayer()[i].getDefence() << "\n";
            out << team[id].getPlayer()[i].getMidfield() << "\n";
            out << team[id].getPlayer()[i].getAttack() << "\n";
            out << team[id].getPlayer()[i].getTackle() << "\n";
            out << team[id].getPlayer()[i].getTechnik() << "\n";
            out << team[id].getPlayer()[i].getShot() << "\n";
            out << team[id].getPlayer()[i].getPass() << "\n";
            out << team[id].getPlayer()[i].getHeader() << "\n";
            out << team[id].getPlayer()[i].getSpeed() << "\n";
            out << team[id].getPlayer()[i].getEndurance() << "\n";
            out << team[id].getPlayer()[i].getGoals() << "\n";
            out << team[id].getPlayer()[i].getStamina() << "\n";
            out << team[id].getPlayer()[i].getFotoPath() << "\n";
        }

        file.flush();
        file.close();

        id++;;
    }
}

void Serialization::saveTeam(const QString &save_path, QList<Team> &team)
{
    // QFile file("/Data/a.txt");                                            // dziala dla Debug
    QFile file(save_path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
          return;
    }
    else
    {

        QTextStream out(&file);

        for(int i = 0; i < team.size(); ++i)
        {
            out << team[i].getName() << "\n";
            out << team[i].getCity() << "\n";
            out << team[i].getShortName() << "\n";
            out << team[i].getRound() << "\n";
            out << team[i].getWin() << "\n";
            out << team[i].getDraw() << "\n";
            out << team[i].getLost() << "\n";
            out << team[i].getGoalScored() << "\n";
            out << team[i].getSeparator() << "\n";
            out << team[i].getGoalLost() << "\n";
            out << team[i].getDiffer() << "\n";
            out << team[i].getPoint() << "\n";
            out << team[i].getFormation() << "\n";
            out << team[i].getStrength() << "\n";
            out << team[i].getTeamId() << "\n";
            out << team[i].getPressing() << "\n";
            out << team[i].getAttackLevel() << "\n";
        }

        file.flush();
        file.close();
    }

}

void Serialization::loadTeam(const QString &load_path, QList<Team> &team)
{
    try
    {
        Team temp_team;

        // QFile file("/Data/teams.txt");                  // dziala dla Debug
        QFile file(load_path);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            throw MyException();
        }
        else
        {
            QTextStream in(&file);

            while (!in.atEnd())
            {
                 QString line1 = in.readLine();
                 QString line2 = in.readLine();
                 QString line3 = in.readLine();
                 QString line4 = in.readLine();
                 QString line5 = in.readLine();
                 QString line6 = in.readLine();
                 QString line7 = in.readLine();
                 QString line8 = in.readLine();
                 QString line9 = in.readLine();
                 QString line10 = in.readLine();
                 QString line11 = in.readLine();
                 QString line12 = in.readLine();
                 QString line13 = in.readLine();
                 QString line14 = in.readLine();
                 QString line15 = in.readLine();
                 QString line16 = in.readLine();
                 QString line17 = in.readLine();

                 temp_team.name = line1;
                 temp_team.city = line2;
                 temp_team.short_name = line3;
                 temp_team.round = line4.toInt();
                 temp_team.win = line5.toInt();
                 temp_team.draw = line6.toInt();
                 temp_team.lost = line7.toInt();
                 temp_team.goal_scored = line8.toInt();
                 temp_team.separator = line9;
                 temp_team.goal_lost = line10.toInt();
                 temp_team.difference = line11.toInt();
                 temp_team.points = line12.toInt();
                 temp_team.formation = line13.toInt();
                 temp_team.strength = line14.toInt();
                 temp_team.team_id = line15.toInt();
                 temp_team.pressing = line16.toInt();
                 temp_team.attack_level = line17.toInt();

                 team.push_back(temp_team);
            }
            file.close();
        }      
    }
    catch(MyException &e)
    {
        qDebug() << "Nie odnalezono pliku teams.txt";
        QMessageBox::critical(0, "Błąd krytyczny", e.team_what());
        exit(0);
    }
    catch(QException &e)
    {
        qDebug() << "Wyjatek " << e.what();
    }

}

void Serialization::saveLeague(const QString &save_path, League *league)
{
    QString sp = " ";
    QFile file(save_path);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

    }
    else
    {
        QTextStream out(&file);

        out << league->getDay() << sp << league->getMonth() << sp << league->getYear() << sp
            << league->getFixture() << sp <<  league->getDays() << sp << league->getMatchDay();
    }

   file.flush();
   file.close();
}

void Serialization::loadLeague(const QString &load_path, League *league)
{
    try
    {
        QFile file(load_path);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
             throw MyException();
        }
        else
        {
            QTextStream in(&file);
            while(!in.atEnd())
            {
               /* QString line1 = in.readLine();
                QString line2 = in.readLine();
                QString line3 = in.readLine();
                QString line4 = in.readLine();
                QString line5 = in.readLine();
                QString line6 = in.readLine();

                league->setDay(line1.toInt());
                league->setMonth(line2.toInt());
                league->setYear(line3.toInt());
                league->setFixture(line4.toInt());
                league->setDays(line5.toInt());
                league->setMatchDays(line6.toInt());*/

                in >> league->day >> league->month >> league->year >> league->fixture
                   >> league->days >> league->matchday;
            }
        }
    }
    catch(MyException &e)
    {
        qDebug() << "Nie odnalezono pliku " << load_path;
        QMessageBox::critical(0, "Błąd krytyczny", e.player_what() + load_path);
        exit(0);
    }
    catch(QException &e)
    {
        qDebug() << "Wyjatek " << e.what();
    }
}

void Serialization::saveUserData(const QString &save_path, UserData *userData)
{
    QFile file(save_path);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

    }
    else
    {
        QTextStream out(&file);

        out << userData->getFname() << "\n";
        out << userData->getLname() << "\n";
        out << userData->getAge() << "\n";
        out << userData->getNationality() << "\n";
        out << userData->getId() <<  "\n";
    }

    file.flush();
    file.close();
}

void Serialization::loadUsetData(const QString &load_path, UserData *userData)
{
    try
    {
        QFile file(load_path);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            throw MyException();

        }
        else
        {
            QTextStream in(&file);
            while(!in.atEnd())
            {
                QString line1 = in.readLine();
                QString line2 = in.readLine();
                QString line3 = in.readLine();
                QString line4 = in.readLine();
                QString line5 = in.readLine();

                userData->setFname(line1);
                userData->setLname(line2);
                userData->setAge(line3.toInt());
                userData->setNationality(line4);
                userData->setId(line5.toInt());
            }
        }

    }
    catch(MyException &e)
    {
        qDebug() << "Nie odnalezono pliku " << load_path;
        QMessageBox::critical(0, "Błąd krytyczny", e.player_what() + load_path);
        exit(0);
    }
    catch(QException &e)
    {
        qDebug() << "Wyjatek " << e.what();
    }

}
