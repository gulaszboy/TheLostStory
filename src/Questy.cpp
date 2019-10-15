#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Questy.h"

void view_quest(int nr_mapy)
{
    system("cls");

    ifstream plik;
    // ---------------Wyswietla tresc questa ----------------
    switch(nr_mapy)
    {
        case 1 : plik.open("../Gra/Content/Questy/101/text.txt");
    }
    if(plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku questa (view_quest) !";
        exit(0);
    }
    string linia;

    while(getline(plik,linia)) cout << linia ;
    cout << endl << endl;
    plik.close();
    // -----Wyswietla odpowiedzi-----------------------------

    switch(nr_mapy)
    {
        case 1 : plik.open("../Gra/Content/Questy/101/odpowiedzi.txt");
    }
    if(plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku questa (view_quest) !";
        exit(0);
    }
    while(getline(plik,linia)) cout << linia << endl;
    plik.close();
}

