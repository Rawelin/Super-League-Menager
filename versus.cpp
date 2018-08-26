#include <QDebug>
#include "versus.h"

extern Container *container;

Versus::Versus(int fix)
{
    //fixture = container->league->getFixture();
    fixture = fix;
    pairList();
    pairProgress();
    setTeamsPairs();
}

void Versus::pairList()
{
    list.append(qMakePair(1, 16));      // kolejka 1 i 8 par
    list.append(qMakePair(2, 15));
    list.append(qMakePair(3, 14));
    list.append(qMakePair(4, 13));
    list.append(qMakePair(5, 12));
    list.append(qMakePair(6, 11));
    list.append(qMakePair(7, 10));
    list.append(qMakePair(8, 9));

    list.append(qMakePair(10, 8));      // kolejka 2 i 8 par
    list.append(qMakePair(16, 9));
    list.append(qMakePair(11, 7));
    list.append(qMakePair(12, 6));
    list.append(qMakePair(13, 5));
    list.append(qMakePair(14, 4));
    list.append(qMakePair(15, 3));
    list.append(qMakePair(1, 2));

    list.append(qMakePair(3, 1));       // kolejka 3 i 8 par
    list.append(qMakePair(4, 15));
    list.append(qMakePair(5, 14));
    list.append(qMakePair(2, 16));
    list.append(qMakePair(6, 13));
    list.append(qMakePair(7, 12));
    list.append(qMakePair(8, 11));
    list.append(qMakePair(9, 10));

    list.append(qMakePair(11, 9));      // kolejka 4 i 8 par
    list.append(qMakePair(12, 8));
    list.append(qMakePair(13, 7));
    list.append(qMakePair(16, 10));
    list.append(qMakePair(14, 6));
    list.append(qMakePair(15, 5));
    list.append(qMakePair(1, 4));
    list.append(qMakePair(2, 3));


    list.append(qMakePair(4, 2));      // kolejka 5 i 8 par
    list.append(qMakePair(5, 1));
    list.append(qMakePair(6, 15));
    list.append(qMakePair(7, 14));
    list.append(qMakePair(8, 13));
    list.append(qMakePair(3, 16));
    list.append(qMakePair(9, 12));
    list.append(qMakePair(10, 11));

    list.append(qMakePair(12, 10));     // kolejka 6 i 8 par
    list.append(qMakePair(13, 9));
    list.append(qMakePair(14, 8));
    list.append(qMakePair(15, 7));
    list.append(qMakePair(1, 6));
    list.append(qMakePair(2, 5));
    list.append(qMakePair(3, 4));
    list.append(qMakePair(16, 11));

    list.append(qMakePair(4, 16));      // kolejka 7 i 8 par
    list.append(qMakePair(5, 3));
    list.append(qMakePair(6, 2));
    list.append(qMakePair(7, 1));
    list.append(qMakePair(8, 15));
    list.append(qMakePair(9, 14));
    list.append(qMakePair(10, 13));
    list.append(qMakePair(11, 12));

    list.append(qMakePair(13, 11));     // kolejka 8 i 8 par
    list.append(qMakePair(14, 10));
    list.append(qMakePair(15, 9));
    list.append(qMakePair(16, 12));
    list.append(qMakePair(1, 8));
    list.append(qMakePair(2, 7));
    list.append(qMakePair(3, 6));
    list.append(qMakePair(4, 5));


    list.append(qMakePair(6, 4));       // kolejka 9 i 8 par
    list.append(qMakePair(5, 16));
    list.append(qMakePair(7, 3));
    list.append(qMakePair(8, 2));
    list.append(qMakePair(9, 1));
    list.append(qMakePair(10, 15));
    list.append(qMakePair(11, 14));
    list.append(qMakePair(12, 13));


    list.append(qMakePair(14, 12));     // kolejka 10 i 8 par
    list.append(qMakePair(15, 11));
    list.append(qMakePair(1, 10));
    list.append(qMakePair(2, 9));
    list.append(qMakePair(3, 8));
    list.append(qMakePair(16, 13));
    list.append(qMakePair(4, 7));
    list.append(qMakePair(5, 6));

    list.append(qMakePair(6, 16));      // kolejka 11 i 8 par
    list.append(qMakePair(7, 5));
    list.append(qMakePair(8, 4));
    list.append(qMakePair(9, 3));
    list.append(qMakePair(10, 2));
    list.append(qMakePair(11, 1));
    list.append(qMakePair(12, 15));
    list.append(qMakePair(13, 14));


    list.append(qMakePair(15, 13));     // kolejka 12 i 8 par
    list.append(qMakePair(1, 12));
    list.append(qMakePair(16, 14));
    list.append(qMakePair(2, 11));
    list.append(qMakePair(3, 10));
    list.append(qMakePair(4, 9));
    list.append(qMakePair(5, 8));
    list.append(qMakePair(6, 7));

    list.append(qMakePair(7, 16));      // kolejka 13 i 8 par
    list.append(qMakePair(8, 6));
    list.append(qMakePair(9, 5));
    list.append(qMakePair(10, 4));
    list.append(qMakePair(11, 3));
    list.append(qMakePair(12, 2));
    list.append(qMakePair(13, 1));
    list.append(qMakePair(14, 15));


    list.append(qMakePair(1, 14));     // kolejka 14 i 8 par
    list.append(qMakePair(2, 13));
    list.append(qMakePair(3, 12));
    list.append(qMakePair(4, 11));
    list.append(qMakePair(5, 10));
    list.append(qMakePair(6, 9));
    list.append(qMakePair(7, 8));
    list.append(qMakePair(16, 15));

    list.append(qMakePair(9, 7));       // kolejka 15 i 8 par
    list.append(qMakePair(10, 6));
    list.append(qMakePair(11, 5));
    list.append(qMakePair(12, 4));
    list.append(qMakePair(8, 16));
    list.append(qMakePair(13, 3));
    list.append(qMakePair(14, 2));
    list.append(qMakePair(15, 1));
                                        // ruda rewanzowa
    list.append(qMakePair(16, 1));      // kolejka 16 i 8 par
    list.append(qMakePair(15, 2));
    list.append(qMakePair(14, 3));
    list.append(qMakePair(13, 4));
    list.append(qMakePair(12, 5));
    list.append(qMakePair(11, 6));
    list.append(qMakePair(10, 7));
    list.append(qMakePair(9, 8));

    list.append(qMakePair(8, 10));      // kolejka 17 i 8 par
    list.append(qMakePair(9, 16));
    list.append(qMakePair(7, 11));
    list.append(qMakePair(6, 12));
    list.append(qMakePair(5, 13));
    list.append(qMakePair(4, 14));
    list.append(qMakePair(3, 15));
    list.append(qMakePair(2, 1));

    list.append(qMakePair(1, 3));       // kolejka 18 i 8 par
    list.append(qMakePair(15, 4));
    list.append(qMakePair(14, 5));
    list.append(qMakePair(16, 2));
    list.append(qMakePair(13, 6));
    list.append(qMakePair(12, 7));
    list.append(qMakePair(11, 8));
    list.append(qMakePair(10, 9));

    list.append(qMakePair(9, 11));      // kolejka 19 i 8 par
    list.append(qMakePair(8, 12));
    list.append(qMakePair(7, 13));
    list.append(qMakePair(10, 16));
    list.append(qMakePair(6, 14));
    list.append(qMakePair(5, 15));
    list.append(qMakePair(4, 1));
    list.append(qMakePair(3, 2));


    list.append(qMakePair(2, 4));      // kolejka 20 i 8 par
    list.append(qMakePair(1, 5));
    list.append(qMakePair(15, 6));
    list.append(qMakePair(14, 7));
    list.append(qMakePair(13, 8));
    list.append(qMakePair(16, 3));
    list.append(qMakePair(12, 9));
    list.append(qMakePair(11, 10));

    list.append(qMakePair(10, 12));     // kolejka 21 i 8 par
    list.append(qMakePair(9, 13));
    list.append(qMakePair(8, 14));
    list.append(qMakePair(7, 15));
    list.append(qMakePair(6, 1));
    list.append(qMakePair(5, 2));
    list.append(qMakePair(4, 3));
    list.append(qMakePair(11, 16));

    list.append(qMakePair(16, 4));      // kolejka 22 i 8 par
    list.append(qMakePair(3, 5));
    list.append(qMakePair(2, 6));
    list.append(qMakePair(1, 7));
    list.append(qMakePair(15, 8));
    list.append(qMakePair(14, 9));
    list.append(qMakePair(13, 10));
    list.append(qMakePair(12, 11));

    list.append(qMakePair(11, 13));     // kolejka 23 i 8 par
    list.append(qMakePair(10, 14));
    list.append(qMakePair(9, 15));
    list.append(qMakePair(12, 16));
    list.append(qMakePair(8, 1));
    list.append(qMakePair(7, 2));
    list.append(qMakePair(6, 3));
    list.append(qMakePair(5, 4));


    list.append(qMakePair(4, 6));       // kolejka 24 i 8 par
    list.append(qMakePair(16, 5));
    list.append(qMakePair(3, 7));
    list.append(qMakePair(2, 8));
    list.append(qMakePair(1, 9));
    list.append(qMakePair(15, 10));
    list.append(qMakePair(14, 11));
    list.append(qMakePair(13, 12));


    list.append(qMakePair(12, 14));     // kolejka 25 i 8 par
    list.append(qMakePair(11, 15));
    list.append(qMakePair(10, 1));
    list.append(qMakePair(9, 2));
    list.append(qMakePair(8, 3));
    list.append(qMakePair(13, 16));
    list.append(qMakePair(7, 4));
    list.append(qMakePair(6, 5));

    list.append(qMakePair(16, 6));      // kolejka 26 i 8 par
    list.append(qMakePair(5, 7));
    list.append(qMakePair(4, 8));
    list.append(qMakePair(3, 9));
    list.append(qMakePair(2, 10));
    list.append(qMakePair(1, 11));
    list.append(qMakePair(15, 12));
    list.append(qMakePair(14, 13));

    list.append(qMakePair(13, 15));     // kolejka 27 i 8 par
    list.append(qMakePair(12, 1));
    list.append(qMakePair(14, 16));
    list.append(qMakePair(11, 2));
    list.append(qMakePair(10, 3));
    list.append(qMakePair(9, 4));
    list.append(qMakePair(8, 5));
    list.append(qMakePair(7, 6));

    list.append(qMakePair(16, 7));      // kolejka 28 i 8 par
    list.append(qMakePair(6, 8));
    list.append(qMakePair(5, 9));
    list.append(qMakePair(4, 10));
    list.append(qMakePair(3, 11));
    list.append(qMakePair(2, 12));
    list.append(qMakePair(1, 13));
    list.append(qMakePair(15, 14));


    list.append(qMakePair(14, 1));     // kolejka 29 i 8 par
    list.append(qMakePair(13, 2));
    list.append(qMakePair(12, 3));
    list.append(qMakePair(11, 4));
    list.append(qMakePair(10, 5));
    list.append(qMakePair(9, 6));
    list.append(qMakePair(8, 7));
    list.append(qMakePair(15, 16));

    list.append(qMakePair(7, 9));       // kolejka 30 i 8 par
    list.append(qMakePair(6, 10));
    list.append(qMakePair(5, 11));
    list.append(qMakePair(4, 12));
    list.append(qMakePair(16, 8));
    list.append(qMakePair(3, 13));
    list.append(qMakePair(2, 14));
    list.append(qMakePair(1, 15));


}

void Versus::pairProgress()
{
    int add = 0;

    if(fixture == 1)
        add = 0;
    if(fixture == 2)
        add = 8;
    if(fixture > 2 && fixture < 31)
        add = 8*(fixture - 1);

    pair[0] = 0 + add;                      // mozna w petli for
    pair[1] = 1 + add;
    pair[2] = 2 + add;
    pair[3] = 3 + add;
    pair[4] = 4 + add;
    pair[5] = 5 + add;
    pair[6] = 6 + add;
    pair[7] = 7 + add;
}

void Versus::setTeamsPairs()
{
    teams[0] = list[pair[0]].first - 1;
    teams[1] = list[pair[0]].second - 1;

    teams[2] = list[pair[1]].first - 1;
    teams[3] = list[pair[1]].second - 1;

    teams[4] = list[pair[2]].first - 1;
    teams[5] = list[pair[2]].second - 1;

    teams[6] = list[pair[3]].first - 1;
    teams[7] = list[pair[3]].second - 1;

    teams[8] = list[pair[4]].first - 1;
    teams[9] = list[pair[4]].second - 1;

    teams[10] = list[pair[5]].first - 1;
    teams[11] = list[pair[5]].second - 1;

    teams[12] = list[pair[6]].first - 1;
    teams[13] = list[pair[6]].second - 1;

    teams[14] = list[pair[7]].first - 1;
    teams[15] = list[pair[7]].second -1;
}


