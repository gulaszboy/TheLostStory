#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>

#include "Room.h"
#include "Map.h"
#include "Funkcje.h"

using namespace std;

Mapa::Mapa(int idx,int nr_map){
    index = idx;
    index_moba = 0;
    nr_mapy =nr_map;
	int i=0;
    chest_difficulty = 0;
    enemies_killed = 0;

	// Wczytje pokoje z plikow tekstowych ----------------------------------------------------
	for(int x =1;x<7;x++)
    {
        for(int y=1;y<6;y++)
        {
            room[i].get_rdy(x,y);

            i++;
        }
    }
}
Mapa::~Mapa()
{
    delete [] object_type;
    delete [] npc_tab;
}

void Mapa::wczytaj(){

    system("cls");
    are_enemies = false;
	// Odpowiada za wczytanie aktualnego wygladu pomieszczenia i sprawdza czy sa tam przeciwnicy

	for(int i = 0 ; i < 30;i++)
    {
        if (i == index)
        {
            if(i == 25) game_end(2);

            if (room[i].show() == true)
            {
                are_enemies = true;
            }
            room[i].enemies_killed =enemies_killed ;

            object_type = new int[room[i].ilosc_obiektow];
            npc_tab = new NPC[room[i].ilosc_npc];

            for(int c=0;c<room[i].ilosc_npc;c++)
            {
                npc_tab[c].nr_dialogu = room[i].npc_tab[c].nr_dialogu;
                npc_tab[c].name = room[i].npc_tab[c].name;
            }

            ilosc_obiektow = room[i].ilosc_obiektow;
            if(ilosc_obiektow > 0)
            {
                for(int c=0;c<room[i].ilosc_obiektow;c++)
                {
                    object_type[c] = room[i].type_tab[c];
                }
            }

            for(int c=0;c<room[i].ilosc_obiektow;c++)
            {
                if(room[i].type_tab[c] == 0) c++;
                if(room[i].type_tab[c] == 1)index_moba = room[i].index_tab[c];
            }

            chest_difficulty = room[i].chest_difficulty ;


            // ---------------------Dane do testow -----------------------
            cout << endl;
            cout << "--------------------------------" << endl;
            cout << "Coordinates : " << endl;
            cout << "X : " << room[i].room_x << endl;
            cout << "Y : " << room[i].room_y << endl;

            for(int c=0;c<room[i].ilosc_obiektow;c++)
            {
                if(room[i].type_tab[c] == 0) c++;
                if(room[i].type_tab[c] == 2)
                {

                }

            }
            cout << "--------------------------------" << endl;

            // -------------Wyswietlanie opcji -------------------------------------
            if(room[index].can_go_down == true) white_stringE("S. Go down ");
            if(room[index].can_go_left == true) white_stringE("A. Go left" );
            if(room[index].can_go_right == true) white_stringE("D. Go right ");
            if(room[index].can_go_up == true) white_stringE("W. Go up ");
            // ----------------------------------------------------------------------
        }
   }
}

bool Mapa::przejscie(char odp)
{
        if(room[index].can_go_down == true && odp == 's')
        {
            index +=1;
            system("cls");
            return true;
        }
        if(room[index].can_go_left == true && odp == 'a')
        {
            index -=5;
            system("cls");
            return true;
        }
        if(room[index].can_go_right == true && odp == 'd')
        {
            index +=5;
            system("cls");
            return true;
        }
        if(room[index].can_go_up == true && odp == 'w')
        {
            index -=1;
            system("cls");
            return true;
        }
    return false;
}

void Mapa::clear_object(int type)
{
    room[index].clear_object(type);
}

