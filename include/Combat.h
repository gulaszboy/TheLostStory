#ifndef COMBAT_H
#define COMBAT_H
#include "Hero.h"
#include "Enemy.h"
#include "Funkcje.h"
#include "Map.h"

class Combat
{
protected :

//    Ecombat_turn current_turn;

public:
        Combat();
    void fight_won(Mapa&,Hero&);
    void fight_lost();
    void next_move();
    void fight(Hero&,Mapa&);
    void fightTest(Hero&,Mapa&);
};

#endif // COMBAT_H

