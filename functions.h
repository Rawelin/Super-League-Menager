#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QTime>
#include <QtWidgets>
#include "showteamstats.h"
#include "showplayerstats.h"

class ShowPlayerStats;

class Functions
{
public:
    Functions();
    int randInt(int min, int max);
    void delay(double);
    void setIcon(QPixmap, QLabel *, int x = 30, int y = 30);
    void setIcon(QPixmap , QPushButton *, QString);
    void setIcon(QPixmap , QLabel *, int, int, int);
    void setHighLight(QRect, QPushButton *, QString &, QString &);
    void showFrame(QTableWidget *, QRect);
    void showTeamStats(ShowTeamStats *, QRect, int);
    void showPlayerStats(ShowPlayerStats *, QRect, int);
    void setBackground(QMainWindow *, QPixmap);
    void setBackground(QDialog *, QPixmap);
    void setLabelTextColor(QLabel *, int);
    void setLabelTextColor(QLabel *, QString);
};

#endif // FUNCTIONS_H
