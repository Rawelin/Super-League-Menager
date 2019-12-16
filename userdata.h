#ifndef USERDATA_H
#define USERDATA_H

#include <QtWidgets>

class UserData
{
private:
    QString fname;
    QString lname;
    QString nationality;
    int age;
    int id;
public:
    UserData();

    friend class Serialization;
    QString getFname()const{return fname;}
    QString getLname()const{return lname;}
    QString getNationality()const{return nationality;}
    int getAge()const{return age;}
    int getId()const{return id;}

    void setFname(QString fn){fname = fn;}
    void setLname(QString ln){lname = ln;}
    void setNationality(QString nat){nationality = nat;}
    void setAge(int a){age = a;}
    void setId(int i){id = i;}
};

#endif // USERDATA_H
