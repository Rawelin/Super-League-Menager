#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QMouseEvent>
#include <QEvent>
#include "choseteam.h"
#include "options.h"
#include "gamedialog.h"
#include "choseteam.h"

class ChoseTeam;


namespace Ui {
class MainMenu;
}


class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    void setGraphics();
    void mouseTracking();


private slots:

    void on_newGame_clicked();
    void on_abaut_clicked();
    void on_option_clicked();
    void on_load_clicked();
    void highLight();

    void on_quit_clicked();

private:
    Ui::MainMenu *ui;
    //ChoseTeam choseTeam;
    QMediaPlayer music;


protected:
    void mouseMoveEvent(QMouseEvent *event);

public: Q_SIGNALS:
     void hovered();

};

#endif // MAINMENU_H
