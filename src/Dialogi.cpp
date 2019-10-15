#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <conio.h>

#include "Funkcje.h"
#include "Dialogi.h"

using namespace std;

void show_dialog(int nr)
{
    system("cls");

    ifstream plik;
    string linia;
    int dlugosc_dialogu=0;

    // ------Wczytuje dialog z pliku ---------------------------------------
    switch(nr)
    {
        case 1 : plik.open("../Gra/Content/Dialog/Dialog/001.txt"); break;
        case 2 : plik.open("../Gra/Content/Dialog/Dialog/002.txt"); break;
        case 3 : plik.open("../Gra/Content/Dialog/Dialog/003.txt"); break;
        case 4 : plik.open("../Gra/Content/Dialog/Dialog/004.txt"); break;
        case 5 : plik.open("../Gra/Content/Dialog/Dialog/005.txt"); break;
        case 6 : plik.open("../Gra/Content/Dialog/Dialog/006.txt"); break;

        case 101 : plik.open("../Gra/Content/Dialog/Dialog/101.txt"); break;
        case 102 : plik.open("../Gra/Content/Dialog/Dialog/102.txt"); break;
        case 103 : plik.open("../Gra/Content/Dialog/Dialog/103.txt"); break;
        case 104 : plik.open("../Gra/Content/Dialog/Dialog/104.txt"); break;
        case 105 : plik.open("../Gra/Content/Dialog/Dialog/105.txt"); break;
        case 106 : plik.open("../Gra/Content/Dialog/Dialog/106.txt"); break;
        case 107 : plik.open("../Gra/Content/Dialog/Dialog/107.txt"); break;
        case 108 : plik.open("../Gra/Content/Dialog/Dialog/108.txt"); break;
        case 109 : plik.open("../Gra/Content/Dialog/Dialog/109.txt"); break;
        case 110 : plik.open("../Gra/Content/Dialog/Dialog/110.txt"); break;
        case 111 : plik.open("../Gra/Content/Dialog/Dialog/111.txt"); break;
        case 112 : plik.open("../Gra/Content/Dialog/Dialog/112.txt"); break;
        case 113 : plik.open("../Gra/Content/Dialog/Dialog/113.txt"); break;

        case 115 : plik.open("../Gra/Content/Dialog/Dialog/115.txt"); break;
        case 116 : plik.open("../Gra/Content/Dialog/Dialog/116.txt"); break;

        default : cout << "Zly numer dialogu !";
    }
    if(plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku dialogow (show_dialog1) !";
        exit(0);
    }

    while(getline(plik,linia))dlugosc_dialogu++;
    string *dialogi;
    dialogi = new string[dlugosc_dialogu];

    int index=0;
    plik.clear();
    plik.seekg( 0, plik.beg);

    while(getline(plik,linia))
    {
        dialogi[index] = linia;
        index++;
    }

    char odp;
    char znak_odp='1';
    int index1=0;

    while(true)
    {
        int ilosc_odp=0;
        znak_odp='1';
        while(!dialogi[index1].empty())
        {
            cout << dialogi[index1] << endl;

            if(index1 == dlugosc_dialogu-1)break;
            index1++;
        }

        cout << endl;
        if(index1 == dlugosc_dialogu-1)break;
        index1++;

        while(!dialogi[index1].empty())
        {
            white_char(znak_odp);
            white_string(" . ");
            white_stringE(dialogi[index1]);
            if(index1 == dlugosc_dialogu-1)break;
            index1++;
            znak_odp++;
            ilosc_odp++;
        }

        cout << endl;
        if(index1 == dlugosc_dialogu-1)break;
        index1++;

        while(true)
        {
            odp = getch();
            if(odp=='1' && ilosc_odp>= 1) break;
            if(odp=='2' && ilosc_odp>= 2) break;
            if(odp=='3' && ilosc_odp>= 3) break;
            if(odp=='4' && ilosc_odp>= 4) break;
        }

       // if(index1 == dlugosc_dialogu-1)break;
    }
    cout << endl;
    white_stringE("Press any key");
    odp = getch();

    plik.close();
    delete [] dialogi;
}
