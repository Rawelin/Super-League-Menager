#ifndef EDITPLAYER_H
#define EDITPLAYER_H

#include <QDialog>
#include "serialization.h"

namespace Ui {
class EditPlayer;
}

class EditPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit EditPlayer(QWidget *parent = 0, int sqn = 0, const QString &save = "");
    ~EditPlayer();
    void SetGraphics();
    void squad();
    void changePlayer();

private slots:
    void on_editchooseteam_clicked();
    void on_add_clicked();
    void edit();
    void setSpinBoxGraphics();
    void take();
    void put();

private:
    Ui::EditPlayer *ui;
    QVector<Player> player;
    QString save_path;
    enum Columna
    {
        NAME, SURNAME, POSITION, NATIONALITY, AGE,
        GK, DEF, MID, ATT, TACKLE, TECHNIK, SHOT,
        PASS, HEAD, SPEED, ENDURANCE, STAMINA, OVERALL, GOALS
    };
    unsigned int maximum_size;
    int squad_number;
    int number;
    int formation_color;
    int num1, num2, index;
    bool taken;

signals:
    void dialogClicked();
};

#endif // EDITPLAYER_H
