#ifndef MATCH_H
#define MATCH_H

#include <QDialog>
#include "matchinterface.h"

namespace Ui {
class Match;
}

class Match : public QDialog
{
    Q_OBJECT

public:
    explicit Match(QDialog *parent = 0);
    ~Match();
    void setGraphic();
    void setting();

private slots:
    void on_nextday_clicked();
    void on_back_clicked();

private:
    QDialog *gameDialog;
    Ui::Match *ui;
    Player *player;
};

#endif // MATCH_H
