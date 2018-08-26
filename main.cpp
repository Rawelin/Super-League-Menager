#include "mainmenu.h"
#include "intro.h"
#include "container.h"
#include <QApplication>
#include <QSharedPointer>

QSharedPointer<Container>container(new Container());

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath(".");

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QApplication a(argc, argv);
    container->loadDefaultData();                     // inicjalizacja wszystkich kontenerow

    a.setWindowIcon(QIcon("Button/ball.png"));
    Intro w;
    w.show();
    return a.exec();
}
