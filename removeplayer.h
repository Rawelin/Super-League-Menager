#ifndef REMOVEPLAYER_H
#define REMOVEPLAYER_H

#include <QDialog>
#include "editchooseteam.h"
#include "serialization.h"
#include "player.h"

class Player;

namespace Ui {
class RemovePlayer;
}

class RemovePlayer : public QDialog
{
    Q_OBJECT

public:
    explicit RemovePlayer(QWidget *parent = 0, int sqn = 0, const QString save = "");
    ~RemovePlayer();
    void setGraphics();
    void squad();

private slots:
    void on_editchooseteam_clicked();
    void on_pushButton_clicked();

private:
    Ui::RemovePlayer *ui;
    QString save_path;
    enum Columna
    {
        NAME, SURNAME, POSITION, NATIONALITY, AGE,
        GK, DEF, MID, ATT, TACKLE, TECHNIK, SHOT,
        SPEED, STAMINA, OVERALL, GOALS
    };
    unsigned int maximum_size;
    int squad_number;
    int formation_color;
};

#endif // REMOVEPLAYER_H
