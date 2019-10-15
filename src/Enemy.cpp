#include "Enemy.h"
#include  <fstream>
#include <cstdlib>
#include "Funkcje.h"
using namespace std;
Enemy::Enemy(int idx)
{
    is_dead = false;
    can_attack = true;

    index = idx;
    ifstream plik;

    switch (index)
    {
        case 1 : plik.open("../Gra/Content/Enemies/001.txt"); break;
        case 2 : plik.open("../Gra/Content/Enemies/002.txt"); break;
        case 3 : plik.open("../Gra/Content/Enemies/003.txt"); break;
        case 4 : plik.open("../Gra/Content/Enemies/004.txt"); break;
        case 5 : plik.open("../Gra/Content/Enemies/005.txt"); break;
        case 6 : plik.open("../Gra/Content/Enemies/006.txt"); break;
        case 7 : plik.open("../Gra/Content/Enemies/007.txt"); break;
        case 8 : plik.open("../Gra/Content/Enemies/008.txt"); break;
        case 9 : plik.open("../Gra/Content/Enemies/009.txt"); break;
        case 10 : plik.open("../Gra/Content/Enemies/010.txt"); break;
        case 11 : plik.open("../Gra/Content/Enemies/011.txt"); break;
        case 12 : plik.open("../Gra/Content/Enemies/012.txt"); break;
        case 13 : plik.open("../Gra/Content/Enemies/013.txt"); break;
        case 14 : plik.open("../Gra/Content/Enemies/014.txt"); break;

        case 101 :plik.open("../Gra/Content/Enemies/101.txt"); break;
        case 102 :plik.open("../Gra/Content/Enemies/102.txt"); break;
        case 103 :plik.open("../Gra/Content/Enemies/103.txt"); break;

        default : cout << "Zly index przeciwnika ! : " << index << endl;
    }

    if(plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku potwora ! Index : " << index;
        exit(0);
    }

    int nr_lini=1;
    string linia;

    while(getline(plik,linia))
    {
        switch(nr_lini)
        {
            case 1 : nazwa = linia; break;
            case 2 : health = stoi(linia); break;
            case 3 : damage = stoi(linia); break;
            case 4 : szansa_unik = stoi(linia); break;
            case 5 : szansa_crit = stoi(linia); break;
            case 6 : exp = stoi(linia); break;
        }
        nr_lini++;
    }
    plik.close();

}
