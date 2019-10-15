#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include "Room.h"
using namespace std;

class Mapa{
	private:

	public:
	    Room room[30];
	    NPC *npc_tab;

	    int enemies_killed;

	    bool tablica_wczytana;
	    bool are_enemies;
	    int nr_mapy;

        bool can_go_right;
        bool can_go_left;
        bool can_go_up;
        bool can_go_down;

	    int index;
	    int index_moba;
	    int *object_type;
	    int chest_difficulty;
	    int ilosc_obiektow;

		Mapa(int,int);
		~Mapa();
		void wczytaj();
		bool przejscie(char);
		void clear_object(int);
};

#endif // MAPA_H
