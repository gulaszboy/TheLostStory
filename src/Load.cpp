#include "Load.h"
#include "Funkcje.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

string* load_room(int room_x,int room_y)
{
    ifstream plik;
    int x,y;

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

    int ilosc_obiektow=0;
    string linia;

    while(getline(plik,linia))ilosc_obiektow++;
    string *tablica;
    tablica = new string[ilosc_obiektow];

    int index=0;
    plik.clear();
    plik.seekg( 0, plik.beg);

    int index_petli=0;
    while(getline(plik,linia))
    {
        tablica[index_petli] = linia;

        index_petli++;
    }
    plik.close();
    return tablica;
}
