#ifndef STADIUM_H
#define STADIUM_H

#include <QtWidgets>

class Stadium
{
private:
    QString name;
    int capacity;
    QPixmap foto;

public:
    Stadium();
    Stadium(const QString &nam, int cap, QPixmap &fot) : name(nam), capacity(cap), foto(fot){}

    void setName(QString &n){name = n;}
    void setCapacity(int c){capacity = c;}
    void setFoto(QPixmap f){foto = f;}

    QString getName()const{return name;}
    int getCapacity()const{return capacity;}
    QPixmap getFoto()const{return foto;}
};

#endif // STADIUM_H
