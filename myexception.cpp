#include "myexception.h"

MyException::MyException()
{

}

QString MyException::player_what()
{
    QString exception = "Nie odnaleziono pliku ";
    return exception;
}

QString MyException::team_what()
{
    QString exception = "Nie odnaleziono pliku teams.txt";
    return exception;
}
