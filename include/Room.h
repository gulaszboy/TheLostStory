#ifndef ROOM_H
#define ROOM_H

#include "NPC.h"
#include <iostream>
using namespace std;
class Room
{
    public:

        ~Room();
        Room();

        NPC npc_tab[6];

        string tablica[6];
        int x_tab[6];
        int y_tab[6];
        int index_tab[6];
        int type_tab[6];

        int ilosc_obiektow;
        int iloscobiektow;

        string linia;

        bool are_enemies;
        bool show();

        bool can_go_right;
        bool can_go_left;
        bool can_go_up;
        bool can_go_down;

        int nr;
        int position_y;
        int position_x;
        int index;
        int type;
        int chest_difficulty;
        int ilosc_pokoi;
        int ilosc_npc;
        int enemies_killed;

        int objects_to_clear;
        bool should_clear;
        bool do_once;

        int room_x;
        int room_y;

        char maptab[11][35];

        void refresh_objects();
        void change_dialog(string);
        void get_rdy(int, int);
        void clear_object(int);
        void change_map(string);
        void open_doors();

    private:

        bool tablica_wczytana;
        void load();
        void edit();
};

#endif // ROOM_H
