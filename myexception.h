#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <QException>

class MyException : public QException
{
public:
    MyException();
    QString player_what();
    QString team_what();
};

#endif // MYEXCEPTION_H
