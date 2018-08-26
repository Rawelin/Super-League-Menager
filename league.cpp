#include "league.h"

int League::getDay() const
{
    return day;
}

int League::getMonth() const
{
    return month;
}

int League::getYear() const
{
    return year;
}

int League::getFixture() const
{
    return fixture;
}

int League::getDays() const
{
    return days;
}

int League::getMatchDay() const
{
    return matchday;
}

void League::nextDay()
{
    day++;
}

void League::calendar()
{
     if((month == 1 and day == 31) or (month == 3 and day == 31) or (month == 5 and day == 31) or (month == 7 and day == 31) or (month == 8 and day == 31) or (month == 10 and day == 31))
     {
         month += 1;
         day = 0;
     }
     if(month == 2 and day == 28)
     {
         month += 1;
         day = 0;
     }
     if((month == 4 and day == 30) or (month == 6  and day == 30) or (month == 9  and day == 30) or (month == 11  and day == 30))
     {
         month += 1;
         day = 0;
     }
     if(month == 12 and day == 31)
     {
           month -= 11;
           day = 0;
           year++;
     }
}

void League::setFixture()
{
    fixture++;
}

void League::setDays()
{
    days++;
}

void League::setMatchDays()
{
    matchday +=7;
}
