#ifndef VERSUS_H
#define VERSUS_H

#include <QList>
#include "container.h"

class Versus
{

public:

    Versus(int fix);
    ~Versus() {}

    void pairList();
    void pairProgress();
    void setTeamsPairs();
    int getPair(int i){return pair[i];}
    int getTeamsPaired(int i){return teams[i];}

private:

    QList<QPair<int, int> > list;
    int fixture;
    int pair[8];
    int teams[16];
};

#endif // VERSUS_H
