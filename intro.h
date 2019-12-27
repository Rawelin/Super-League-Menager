#ifndef INTRO_H
#define INTRO_H

#include <QDialog>
#include "mainmenu.h"
#include "choseteam.h"

namespace Ui {
class Intro;
}

class Intro : public QDialog
{
    Q_OBJECT

public:
    explicit Intro(QWidget *parent = 0);
    ~Intro();

private slots:
    void on_go_clicked();

private:
    Ui::Intro *ui;
};

#endif // INTRO_H
