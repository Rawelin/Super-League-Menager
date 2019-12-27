#ifndef TOPSCORER_H
#define TOPSCORER_H

#include <QDialog>
#include "player.h"
#include "container.h"

namespace Ui {
class TopScorer;
}

class TopScorer : public QDialog
{
    Q_OBJECT

public:
    explicit TopScorer(QWidget *parent = 0);
    ~TopScorer();
    void setGraphic();
    void table();
    int matcher(const Player&);

private slots:
    void on_stats_clicked();

private:
    Ui::TopScorer *ui;
    enum Columna
    {
        POSITION, NAME, SURNAME, TEAM, GOALS
    };
};

int findeScorer(const Player &p);

#endif // TOPSCORER_H
