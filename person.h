#ifndef PERSON_H
#define PERSON_H

#include <QtWidgets>
#include "showsquads.h"
#include "player.h"


class Person
{
private:
    QString fname;
    QString lname;
    QString nationality;
    int age;

public:
    Person();
    Person(const QString& fn,const QString& ln, QString& nat, int a) : fname(fn), lname(ln),nationality(nat), age(a) {}
    virtual ~Person(){}

    friend class GameWindow;
    friend class ShowSquads;
    QString getFname();
    QString getLname();
    int getSkils();
};

#endif // PERSON_H
