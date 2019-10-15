#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Hero.h"
#include "QuestMenager.h"
#include "Combat.h"

#include <fstream>
#include <string>
using namespace std;
class Game
{
    protected:

    QuestMenager Q1[2];
    Combat combat;
    string historia[100];
    public:

    char odp;

    void show_options(Mapa&,Hero&);
    void get_rdy(Mapa&);
};

#endif // GAME_H
