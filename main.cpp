#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

#include "Map.h"
#include "Unit.h"
#include "Hero.h"
#include "Enemy.h"
#include "Combat.h"
#include "Game.h"
#include "Funkcje.h"
#include "Room.h"
#include "Ekwipunek.h"
#include "QuestMenager.h"

using namespace std;

int main()
{
    Hero hero(5,5,5,100);

    Game game;

    hero.lockpicks = 3; // na testy

    Mapa mapa(28,1);
    game.get_rdy(mapa);

    menu(hero);

    while(true)
    {
        hero.calculate_stats();
        mapa.wczytaj();

        game.show_options(mapa,hero);
    }

    return 0;
}
