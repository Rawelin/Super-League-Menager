#ifndef EDITCHOOSETEAM_H
#define EDITCHOOSETEAM_H

#include <QDialog>
#include <QMediaPlayer>
#include "addplayer.h"
#include "removeplayer.h"


namespace Ui {
class EditChooseTeam;
}

class EditChooseTeam : public QDialog
{
    Q_OBJECT

public:
    explicit EditChooseTeam(QWidget *parent = 0, int select_option = 0);
    ~EditChooseTeam();
    void setImages();
    void setSelect(int select, int team_number, const QString save);
    void setLabel(int select_option);

private slots:
    void on_real_clicked();
    void on_bayern_clicked();
    void on_barcelona_clicked();
    void on_atletico_clicked();
    void on_juventus_clicked();
    void on_psg_clicked();
    void on_borusia_clicked();
    void on_sevila_clicked();
    void on_benfica_clicked();
    void on_chelsea_clicked();
    void on_arsenal_clicked();
    void on_manchester_city_clicked();
    void on_porto_clicked();
    void on_schalke_clicked();
    void on_manu_clicked();
    void on_napoli_clicked();
    void on_edit_clicked();
    void bakToMainMenu();

private:
    Ui::EditChooseTeam *ui;
    QMediaPlayer* music;
    QPalette* palette;
    AddPlayer *addPlayer;
    RemovePlayer *removePlayer;
    EditPlayer *editPlayer;
    int select;

signals:
    void dialogClicked();
};

#endif // EDITCHOOSETEAM_H
