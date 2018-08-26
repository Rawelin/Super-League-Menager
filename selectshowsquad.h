#ifndef SELECTSHOWSQUAD_H
#define SELECTSHOWSQUAD_H

#include <QDialog>
#include "showsquads.h"

namespace Ui {
class SelectShowSquad;
}

class SelectShowSquad : public QDialog
{
    Q_OBJECT

public:
    explicit SelectShowSquad(QWidget *parent = 0);
    ~SelectShowSquad();
    void setImages();

private slots:
    void on_jagielonia_clicked();
    void on_lech_clicked();
    void on_legia_clicked();
    void on_wisla_clicked();
    void on_ruch_clicked();
    void on_slask_clicked();
    void on_lechia_clicked();
    void on_gornik_leczna_clicked();
    void on_piast_clicked();
    void on_arka_clicked();
    void on_cracovia_clicked();
    void on_termalica_clicked();
    void on_korona_clicked();
    void on_wisla_plock_clicked();
    void on_pogon_clicked();
    void on_zaglebie_clicked();
    void on_back_clicked();

private:
    Ui::SelectShowSquad *ui;
    QPalette* palette;
    QVector<QPushButton*>buttons;
};

#endif // SELECTSHOWSQUAD_H
