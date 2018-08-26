#ifndef SHOWTEAM_H
#define SHOWTEAM_H

#include <QDialog>
#include "team.h"
#include "player.h"

namespace Ui {
class ShowTeam;
}

class ShowTeam : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTeam(QWidget *parent = 0);
    ~ShowTeam();

private:
    Ui::ShowTeam *ui;
};

#endif // SHOWTEAM_H
