#include "Game.h"
#include "Funkcje.h"
#include "Enemy.h"
#include "Ekwipunek.h"
#include "Questy.h"
#include "Dialogi.h"
#include "QuestMenager.h"
#include "Combat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;
void Game::get_rdy(Mapa& mapa)
{
    for(int c =0;c<7;c++) Q1[c].get_rdy(c+1,mapa);
}

void Game::show_options(Mapa &mapa,Hero &hero)
{
    //-----Sprawdza czy sa wrogowie i wyswietla opcje z tym zwiazane --------
    if (mapa.are_enemies == true)
    {
        Enemy enemy(mapa.index_moba);
        white_string("1. Fight with ");
        white_stringE(enemy.nazwa);
    }
    // --------Sprawdza czy w roomie znajduje sei kufer i wyswietla opcje----
    for(int c=0;c<mapa.ilosc_obiektow;c++)
    {
        if(mapa.object_type[c] == 3)
        {
            if(hero.lockpicks >0)white_stringE("Q. Open chest ");
                else cout <<"Q. Open chest " <<endl;
        }
        if(mapa.object_type[c] == 2)
        {
            white_string("Z. Speak with ");
            white_stringE(mapa.npc_tab[c].name);
            break;
        }

    }

    white_stringE("I. Show equipment");

    bool pick = false;

    while(pick != true)
    {
        odp = getch();

        for(int c=0;c<mapa.ilosc_obiektow;c++)
        {
            if(odp == 'z' &&mapa.object_type[c] == 2)
            {
                show_dialog(mapa.npc_tab[c].nr_dialogu);
                for(int d=0;d<3;d++) Q1[d].check_conditions(mapa.npc_tab[c].nr_dialogu,2,mapa,hero);
                pick=true;
                break;
            }
            if(odp == 'q' && mapa.object_type[c] ==3&& hero.lockpicks >0)
            {
                open_chest(hero,mapa.chest_difficulty,mapa);
                pick = true;
            }
        }

        if(mapa.przejscie(odp) == true)break;
        if(odp == '1' && mapa.are_enemies == true)
        {
        // -------------------Combat ---------------
            if (mapa.are_enemies == true && odp == '1')
            {
                combat.fightTest(hero,mapa);
                for(int d=0;d<3;d++) Q1[d].check_conditions(mapa.index_moba,1,mapa,hero);
                mapa.wczytaj();
                break;
            }
        }



        if(odp == 'i') {hero.show_eq();break;}
        //if(odp == '2') {view_quest(mapa.nr_mapy);}
    }
    system("cls");
}
