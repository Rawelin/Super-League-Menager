#ifndef ARTIFICIALINTELLIGENCE_H
#define ARTIFICIALINTELLIGENCE_H

#include "container.h"
#include "player.h"

class ArtificialIntelligence
{
public:
    ArtificialIntelligence();
    void setStrategy(int, int, int);
    void setId(int id_) {id = id_;}
    void setAway(bool aw){away = aw;}
    void setHome(bool ho){home = ho;}
    void setDefaultPressing(int pressing){default_pressing = pressing;}
    void changePlayer();
    void changePlayerSimulation(int, bool);
    void sortPlayers();
    void resetVariable();

private:
    int id, default_pressing;
    int home_sub, away_sub;
    int home_stamina_limit, away_stamina_limit;

    bool home,away;
};

#endif // ARTIFICIALINTELLIGENCE_H
