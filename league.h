#ifndef LEAGUE_H
#define LEAGUE_H

#include <QWidget>



class League
{
public:
    League() : day(1), month(8), year(2016), fixture(1), days(0), matchday(6) {}

    friend class Serialization;

    int getDay()const;
    int getMonth()const;
    int getYear()const;
    int getFixture()const;
    int getDays()const;
    int getMatchDay()const;

    void setDay(int d){day = d;}
    void setMonth(int m){month = m;}
    void setYear(int y){year = y;}
    void setFixture(int f){fixture = f;}
    void setDays(int d){days = d;}
    void setMatchDays(int md){matchday = md;}

    void nextDay();
    void calendar();
    void setFixture();
    void setDays();
    void setMatchDays();

private:
    QList<QPair<int, int> > list;
    int day;
    int month;
    int year;
    int fixture;
    int days;
    int matchday;
};

#endif // LEAGUE_H
