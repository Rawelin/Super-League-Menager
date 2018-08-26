#ifndef ADDPLAYER_H
#define ADDPLAYER_H

#include <QDialog>
#include "editchooseteam.h"
#include "player.h"
#include "serialization.h"

namespace Ui {
class AddPlayer;
}

class AddPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayer(QWidget *parent = 0, int sqn = 0, const QString save = "");
    ~AddPlayer();
    void setGraphics();
    void squad();
    void setSpinBoxGraphics();

private slots:
    void on_editchooseteam_clicked();
    void on_add_clicked();

private:
    Ui::AddPlayer *ui;
    QString save_path;
    enum Columna
    {
        NAME, SURNAME, POSITION, NATIONALITY, AGE,
        GK, DEF, MID, ATT, TACKLE, TECHNIK, SHOT,
        PASS, HEAD, SPEED, ENDURANCE, STAMINA, OVERALL, GOALS
    };
    int squad_number;
    int formation_color;

};

#endif // ADDPLAYER_H
