#include "Room.h"
#include "Funkcje.h"
#include "NPC.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

Room ::Room()
{
    type = 0;
    index = 0;
    chest_difficulty = 0;
    tablica_wczytana = false;
    ilosc_obiektow=0;
    enemies_killed = 0;
    objects_to_clear =0;
    should_clear = false;
    do_once = true;
}

void Room::load()
{
    ifstream plik;
    string linia;

    if (room_x == 1 && room_y == 1) plik.open("../Gra/Content/Maps/001/Map/map_1_1.txt");
    if (room_x == 1 && room_y == 2) plik.open("../Gra/Content/Maps/001/Map/map_1_2.txt");
    if (room_x == 1 && room_y == 4) plik.open("../Gra/Content/Maps/001/Map/map_1_4.txt");
    if (room_x == 1 && room_y == 5) plik.open("../Gra/Content/Maps/001/Map/map_1_5.txt");

    if (room_x == 2 && room_y == 1) plik.open("../Gra/Content/Maps/001/Map/map_2_1.txt");
    if (room_x == 2 && room_y == 2) plik.open("../Gra/Content/Maps/001/Map/map_2_2.txt");
    if (room_x == 2 && room_y == 3) plik.open("../Gra/Content/Maps/001/Map/map_2_3.txt");
    if (room_x == 2 && room_y == 4) plik.open("../Gra/Content/Maps/001/Map/map_2_4.txt");
    if (room_x == 2 && room_y == 5) plik.open("../Gra/Content/Maps/001/Map/map_2_5.txt");

    if (room_x == 3 && room_y == 1) plik.open("../Gra/Content/Maps/001/Map/map_3_1.txt");
    if (room_x == 3 && room_y == 4) plik.open("../Gra/Content/Maps/001/Map/map_3_4.txt");
    if (room_x == 3 && room_y == 5) plik.open("../Gra/Content/Maps/001/Map/map_3_5.txt");

    if (room_x == 4 && room_y == 1) plik.open("../Gra/Content/Maps/001/Map/map_4_1.txt");
    if (room_x == 4 && room_y == 2) plik.open("../Gra/Content/Maps/001/Map/map_4_2.txt");
    if (room_x == 4 && room_y == 3) plik.open("../Gra/Content/Maps/001/Map/map_4_3.txt");
    if (room_x == 4 && room_y == 5) plik.open("../Gra/Content/Maps/001/Map/map_4_5.txt");

    if (room_x == 5 && room_y == 2) plik.open("../Gra/Content/Maps/001/Map/map_5_2.txt");
    if (room_x == 5 && room_y == 3) plik.open("../Gra/Content/Maps/001/Map/map_5_3.txt");
    if (room_x == 5 && room_y == 4) plik.open("../Gra/Content/Maps/001/Map/map_5_4.txt");
    if (room_x == 5 && room_y == 5) plik.open("../Gra/Content/Maps/001/Map/map_5_5.txt");

    if (room_x == 6 && room_y == 1) plik.open("../Gra/Content/Maps/001/Map/map_6_1.txt");
    if (room_x == 6 && room_y == 2) plik.open("../Gra/Content/Maps/001/Map/map_6_2.txt");
    if (room_x == 6 && room_y == 4) plik.open("../Gra/Content/Maps/001/Map/map_6_4.txt");
    if (room_x == 6 && room_y == 5) plik.open("../Gra/Content/Maps/001/Map/map_6_5.txt");

    if(plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku mapy !";
        exit(0);
    }

    for(int i=0;i<11;i++)
    {
        getline(plik,linia);

        for(int j=0;j<35;j++)
        {
            maptab[i][j] = linia[j];
        }
    }
    plik.close();
}
void Room::edit()
{
    ifstream plik;

        if (room_x == 1 && room_y == 1) plik.open("../Gra/Content/Maps/001/Addons/A_1_1.txt");
        if (room_x == 1 && room_y == 2) plik.open("../Gra/Content/Maps/001/Addons/A_1_2.txt");
        if (room_x == 1 && room_y == 4) plik.open("../Gra/Content/Maps/001/Addons/A_1_4.txt");
        if (room_x == 1 && room_y == 5) plik.open("../Gra/Content/Maps/001/Addons/A_1_5.txt");

        if (room_x == 2 && room_y == 1) plik.open("../Gra/Content/Maps/001/Addons/A_2_1.txt");
        if (room_x == 2 && room_y == 2) plik.open("../Gra/Content/Maps/001/Addons/A_2_2.txt");
        if (room_x == 2 && room_y == 3) plik.open("../Gra/Content/Maps/001/Addons/A_2_3.txt");
        if (room_x == 2 && room_y == 4) plik.open("../Gra/Content/Maps/001/Addons/A_2_4.txt");
        if (room_x == 2 && room_y == 5) plik.open("../Gra/Content/Maps/001/Addons/A_2_5.txt");

        if (room_x == 3 && room_y == 1) plik.open("../Gra/Content/Maps/001/Addons/A_3_1.txt");
        if (room_x == 3 && room_y == 4) plik.open("../Gra/Content/Maps/001/Addons/A_3_4.txt");
        if (room_x == 3 && room_y == 5) plik.open("../Gra/Content/Maps/001/Addons/A_3_5.txt");

        if (room_x == 4 && room_y == 1) plik.open("../Gra/Content/Maps/001/Addons/A_4_1.txt");
        if (room_x == 4 && room_y == 2) plik.open("../Gra/Content/Maps/001/Addons/A_4_2.txt");
        if (room_x == 4 && room_y == 3) plik.open("../Gra/Content/Maps/001/Addons/A_4_3.txt");
        if (room_x == 4 && room_y == 5) plik.open("../Gra/Content/Maps/001/Addons/A_4_5.txt");

        if (room_x == 5 && room_y == 2) plik.open("../Gra/Content/Maps/001/Addons/A_5_2.txt");
        if (room_x == 5 && room_y == 3) plik.open("../Gra/Content/Maps/001/Addons/A_5_3.txt");
        if (room_x == 5 && room_y == 4) plik.open("../Gra/Content/Maps/001/Addons/A_5_4.txt");
        if (room_x == 5 && room_y == 5) plik.open("../Gra/Content/Maps/001/Addons/A_5_5.txt");

        if (room_x == 6 && room_y == 1) plik.open("../Gra/Content/Maps/001/Addons/A_6_1.txt");
        if (room_x == 6 && room_y == 2) plik.open("../Gra/Content/Maps/001/Addons/A_6_2.txt");
        if (room_x == 6 && room_y == 4) plik.open("../Gra/Content/Maps/001/Addons/A_6_4.txt");
        if (room_x == 6 && room_y == 5) plik.open("../Gra/Content/Maps/001/Addons/A_6_5.txt");

    if(plik.good() == false)
    {
        cout << "Nie udalo sie wczytac dodatkowego pliku mapy !";
        exit(0);
    }

    for(int c=0;c<4;c++)
    {
        tablica[c] = "0";
        x_tab[c] = 0;
        y_tab[c]=0;
        index_tab[c] =0;
        type_tab[c] =0;
    }

    ilosc_obiektow = 0;


    plik.clear();
    plik.seekg( 0, plik.beg);

    int index_petli=0;
    while(getline(plik,linia))
    {
        tablica[index_petli] = linia;
        index_petli++;
        ilosc_obiektow++;
    }
    iloscobiektow = ilosc_obiektow;
    plik.close();
}
void Room::get_rdy(int x,int y)
{
    room_x = x;
    room_y = y;

    load();
    edit();
}

void Room::refresh_objects()
{
    for(int i=0;i<ilosc_obiektow;i++)
    {
        linia = tablica[i];
        istringstream str(linia);
        str >> x_tab[i] >>y_tab[i] >> index_tab[i]>> type_tab[i];

        switch (type_tab[i])
        {
            case 1 :
                {
                    maptab[y_tab[i]][x_tab[i]] = '1'; break;
                }
            case 2 :
                {
                    maptab[y_tab[i]][x_tab[i]] = 'a';
                    ilosc_npc++;
                    break;
                }
            case 3 :
                {
                    maptab[y_tab[i]][x_tab[i]] = 'Ü';
                    chest_difficulty = index_tab[i];
                    break;
                }
        }
    }

    if(do_once == true)
    {
        for(int d=0;d<ilosc_obiektow;d++) if(type_tab[d] == 2) npc_tab[d].load(index_tab[d]);
        do_once = false;
    }

    if(objects_to_clear !=0 && should_clear == true)
    {
        clear_object(objects_to_clear);
        should_clear = false;
    }
}

bool Room::show()
{
    // --------Reset zmiennych ---------------------------------
    can_go_down = false;
    can_go_up = false;
    can_go_left = false;
    can_go_right = false;

    are_enemies = false;
    ilosc_npc=0;
    // ----------------------------------------------------------

    // wyciac to do osobnej funkcji ktore bedzie uzywac tez change dialog !

    refresh_objects();
    // -----------------Petla drukujaca mape -------------------------------
    for(int y=0;y<11;y++)
    {
        int spawned =0;
        for(int x=0;x<35;x++)
        {
            if (maptab[y][x] == '1' && ilosc_obiektow >0&& spawned<=ilosc_obiektow )
             {
                 red_char('\14');
                 are_enemies = true;
                 position_x = x; position_y = y;
                 type = 1;
                 spawned++;
             }

            else if(maptab[y][x] == '1' && ilosc_obiektow <=0)
            {
                maptab[y][x] == ' ';
                cout << " " ;
            }

            else if (maptab[y][x] == 'a'&& ilosc_obiektow >0&& spawned<ilosc_obiektow)
            {
                green_char('Y');
                type = 2;
                spawned++;
            }
            else if (maptab[y][x] == 'Ü')
            {
                blue_char('Ü');
                type = 3;
            }
            else if (maptab[y][x] == 'D')
            {
                cout << "#";
            }

             // ---------------Edycja mapy --------------------------
            else if (maptab[y][x] == 'x' ) grey_char('\÷');
            else if (maptab[y][x] == '0' ) grey_char('\°');
            else if (maptab[y][x] == '|' ) grey_char('\:');
            else if (maptab[y][x] == '_' ) grey_char('\_');

            else cout << maptab[y][x];

            //-------------------------------------------------------

            // --------------Sprawdza czy da sie ics ----------------
            if(maptab[y ][0] == ' ')can_go_left = true;
            if(maptab[0 ][x] == ' ')can_go_up = true;
            if(maptab[y][34] == ' ')can_go_right = true;
            if(maptab[10][x] == ' ')can_go_down = true;
            //-------------------------------------------------------
        }
        cout << endl;
    }
    // --------------------------------------------------------------
    return are_enemies;
}

void Room::clear_object(int type)
{
    iloscobiektow = ilosc_obiektow;
    for(int i=0;i<iloscobiektow;i++)
    {
        if(type_tab[i] == type)
        {
            tablica[i] = "0";

            maptab[y_tab[i]][x_tab[i]] = ' ';
          //  if(index_tab[i] == 102) maptab[y_tab[i]][x_tab[i]] = 'B';
            x_tab[i]=0;
            y_tab[i]=0;
            type_tab[i] = 0;
            index_tab[i] = 0;
            ilosc_obiektow--;
       }
    }
}
Room::~Room()
{

}
void Room::change_map(string lin)
{
    ilosc_obiektow++;

    cout << endl;

    for(int c=0;c<4;c++)
    {
        if(tablica[c] == "0")
        {
            tablica[c] =lin; ////////////////////////////////////////
            for(int d=0;d<ilosc_obiektow;d++)
            {
            }
            cout << endl;
            break;
        }
    }
}

void Room::change_dialog(string lin)
{
    refresh_objects();
    int index_stary,index_nowy;
    istringstream str(lin);
    str >> index_stary >> index_nowy;

    for(int d=0;d<ilosc_npc;d++)
    {
        cout << endl;
        if(npc_tab[d].nr_dialogu == index_stary)
        {
            npc_tab[d].nr_dialogu = index_nowy;
        }

    }
}

void Room::open_doors()
{
    for(int y=0;y<11;y++)
    {
        for(int x=0;x<35;x++)
        {
            if (maptab[y][x] == 'D')
            {
                maptab[y][x] = ' ';
            }
        }
    }
}
