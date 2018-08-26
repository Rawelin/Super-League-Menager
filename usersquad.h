#ifndef USERSQUAD_H
#define USERSQUAD_H

#include <QDialog>
#include "container.h"
#include "team.h"
#include "contextmenu.h"

class Team;

namespace Ui {
class UserSquad;
}

class UserSquad : public QDialog
{
    Q_OBJECT

public:

    explicit UserSquad(QWidget *parent = 0, bool wpm = false);
    ~UserSquad();
    void setGraphic();
    void squad();
    void formationPitch(int);
    void formationColor(int);
    void updateTeamStats();
    void changePlayer();
    void highlightPlayer(QTableWidget *, QLabel *, int);
    void pressingValue(int);
    void attackValue(int);

private slots:

    void formation442();
    void formation433();
    void formation352();
    void on_back_clicked();
    void take();
    void put();
    void contextMenu();
    void personalData();
    void pressingControler();
    void attackControler();

private:
    Ui::UserSquad *ui;
    Team* team;

    enum Columna
    {
        NAME, SURNAME, POSITION, NATIONALITY, AGE, STAMINA, OVERALL, GOALS
    };

    int num1, num2, index;
    int formation_number;
    int id;
    int row;
    int substitutions;
    int changed_player;
    int first_team_player;
    unsigned int maximum_size;
    bool taken;
    bool when_playing_match;
    bool no_changes;

    QStringList titles;
};

#endif // USERSQUAD_H
