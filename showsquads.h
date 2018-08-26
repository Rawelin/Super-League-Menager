#ifndef SHOWSQUADS_H
#define SHOWSQUADS_H

#include <QDialog>
#include <QFile>
#include "player.h"
#include "team.h"
#include "serialization.h"
#include "container.h"

class Player;
class Team;

namespace Ui {
class ShowSquads;
}

class ShowSquads : public QDialog
{
    Q_OBJECT

public:
    explicit ShowSquads(QWidget *parent = 0, const QString& name = "", int sqn = 0);
    ~ShowSquads();
    void setGraphic();
    void squad();
    void formationColor(int formation);
    void updateTeamStats();


private slots:
    void on_pushButton_clicked();
    void personalData();

private:
    Ui::ShowSquads *ui;
    QVector<Player> player;
    Team* team;
    QString team_name;
    QString default_player_path;
    enum Columna
    {
        NAME, SURNAME, POSITION, NATIONALITY, AGE,
        GK, DEF, MID, ATT, TACKLE, TECHNIK, SHOT,
        PASS, HEAD, SPEED, ENDURANCE, STAMINA, OVERALL, GOALS
    };
    int formation_color;
    int id;
    int index;

};

#endif // SHOWSQUADS_H
