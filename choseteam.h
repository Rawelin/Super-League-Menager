#ifndef CHOSETEAM_H
#define CHOSETEAM_H

#include <QDialog>
#include <QMediaPlayer>
#include <QMouseEvent>
#include <QEvent>
#include "usersquad.h"
#include "container.h"
#include "showteamstats.h"
#include "showplayerstats.h"
#include "userdatadialog.h"
//#include "mainmenu.h"


class ShowTeamStats;
class ShowPlayerStats;

namespace Ui {
class ChoseTeam;
}

class ChoseTeam : public QDialog
{
    Q_OBJECT

public:
    explicit ChoseTeam(QDialog *parent = 0);
    ~ChoseTeam();
    void setImages();
    void mouseTracking();
    void setAnimation();
    void getStats(QRect, int);
    void setUserData(int);

protected:
    void mouseMoveEvent(QMouseEvent *event);

public: Q_SIGNALS:
    void hovered();

private slots:
    void highLight();
    void on_real_clicked();
    void on_legia_clicked();
    void on_lech_clicked();
    void on_wisla_clicked();
    void on_ruch_clicked();
    void on_slask_clicked();
    void on_lechia_clicked();
    void on_termalica_clicked();
    void on_piast_clicked();
    void on_arka_clicked();
    void on_cracovia_clicked();
    void on_gornik_leczna_clicked();
    void on_korona_clicked();
    void on_pogon_clicked();
    void on_wisla_plock_clicked();
    void on_zaglebie_clicked();

signals:
    void dialogClickedGo();


private:
    Ui::ChoseTeam *ui;
    ShowTeamStats *showteamstats;
    ShowPlayerStats *showplayerstats;
    QDialog *mainmenu;
    QMediaPlayer music;
    int x,y,z,v,i,j;
};

#endif // CHOSETEAM_H
