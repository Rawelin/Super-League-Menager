#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QEvent>
#include "table.h"
#include "container.h"
#include "usersquad.h"
#include "selectshowsquad.h"
#include "data.h"
#include "fixture.h"
#include "match.h"
//#include "mainmenu.h"
#include "container.h"
#include "tabmenu.h"
#include "Ui_MainMenu.h"


namespace Ui {
class GameDialog;
}

class MainMenu;

class GameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameDialog(QWidget *parent = 0);
    ~GameDialog();
    void setIco();
    void mouseTracking();

private slots:
    void on_table_clicked();
    void on_squad_clicked();
    void on_exit_clicked();
    void on_teams_clicked();
    void on_stats_clicked();
    void on_fixture_clicked();
    void on_nextday_clicked();
    void on_mainmenu_clicked();
    void start();
    void stop();
    void pause();
    void forward();
    void previous();
    void volumeUp();
    void volumeDown();
    void highLight();
    void on_save_clicked();
    void on_load_clicked();
    void on_tabMenu_clicked();

private:
    Ui::GameDialog *ui;

protected:
     void mouseMoveEvent(QMouseEvent *event);

public: Q_SIGNALS:
    void hovered();

signals:
    void dialogClicked();

};

#endif // GAMEDIALOG_H
