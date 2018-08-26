#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "container.h"
#include "mainmenu.h"
#include "table.h"
#include "player.h"
#include "team.h"
#include "serialization.h"
#include "stats.h"
#include "fixture.h"
#include "tablesandstats.h"
#include "gamedialog.h"

class Player;

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0, const QString& name = "", const QString& file = "", const QString& save = "", int sqn = 0);
    ~GameWindow();

    friend class ChoseTeam;
    void squad();
    void formationColor(int formation);
    void updateTeamStats();
    void updateTeams();

private slots:
    void on_actionMain_Menu_triggered();
    void on_actionExit_triggered();
    void on_legia_clicked();
    void on_wisla_clicked();
    void on_lech_clicked();
    void on_jagielonia_clicked();
    void on_change_clicked();
    void formation442();
    void formation433();
    void formation352();
    void on_actionNew_Menu_triggered();

private:
    Ui::GameWindow *ui;
    Team* team;
    QPalette *palette;
    QString team_name;
    QString default_player_path;
    QString save_path;
    enum Columna
    {
        NAME, SURNAME, POSITION, NATIONALITY, AGE,
        GK, DEF, MID, ATT, TACKLE, TECHNIK, SHOT,
        SPEED, STAMINA, OVERALL, GOALS
    };

    int num1, num2;
    int formation_color;
    int squad_number;
    unsigned int maximum_size;
};

#endif // GAMEWINDOW_H
