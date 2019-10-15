#include "QuestMenager.h"
#include "Map.h"
#include "Funkcje.h"
#include "Hero.h"


#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

QuestMenager::QuestMenager()
{
    ;
}
void QuestMenager::get_rdy(int nr_quest, Mapa &mapa)
{
    only_once = true;
    aktualny_progres = 0;
    go_next= false;
    nr_questa = nr_quest;
    load_conditions();

    ifstream plik;

    switch(nr_questa)
    {
        case 1 : plik.open("../Gra/Content/Questy/101/path.txt");break;
        case 2 : plik.open("../Gra/Content/Questy/102/path.txt");break;
        case 3 : plik.open("../Gra/Content/Questy/103/path.txt");break;
    }
    if(plik.good() == false)
    {
        cout << "Error loading quest path !" << endl;
        exit(0);
    }

    string linia;
    path_lenght = 0;

    while(getline(plik,linia))path_lenght++;
    path = new string[path_lenght];

    int index=0;
    plik.clear();
    plik.seekg( 0, plik.beg);

    while(getline(plik,linia))
    {
        path[index] = linia;
        index++;
    }


}
void QuestMenager::change_map(Mapa &mapa)
{
    ifstream plik;
    string linia;

    switch(nr_questa)
    {
        case 1 : plik.open("../Gra/Content/Questy/101/map_change.txt");break;
        case 2 : plik.open("../Gra/Content/Questy/102/map_change.txt");break;
        case 3 : plik.open("../Gra/Content/Questy/103/map_change.txt");break;
        default : cout <<"Zly index questa !" << endl;
    }
    if(plik.good() == false)
    {
        cout << "Blad wczytywania pliku zmiany mapy quest !";
        exit(0);
    }

    int nr_lini=0;
    while(getline(plik,linia))
    {
        if(nr_lini%2 == 0)
        {
            istringstream str(linia);
            str >> x >> y >> action;
            x--;
            y--;
        }
        // Action
        // 1 - Spawn object
        // 2 - Change dialog

        if(nr_lini%2 == 1)
        {
            if(action == 1)
            {
                mapa.room[y+(x*5)].change_map(linia);
            }

            if(action == 2)
            {
                mapa.room[y+(x*5)].change_dialog(linia);
            }

        }
        nr_lini++;
    }
}
void QuestMenager::load_conditions()
{
    ifstream plik;
    switch(nr_questa)
    {
        case 1 : plik.open("../Gra/Content/Questy/101/conditions.txt"); break;
        case 2 : plik.open("../Gra/Content/Questy/102/conditions.txt"); break;
        case 3 : plik.open("../Gra/Content/Questy/103/conditions.txt"); break;
    }

    if(plik.good() == false )
    {
        cout << "Error wczytywanie warunkow questa : " << nr_questa << endl;
        exit(0);
    }

    string linia;
    ilosc=0;
    while(getline(plik,linia))ilosc++;

    conditions_tab = new string[ilosc];

    plik.clear();
    plik.seekg( 0, plik.beg);

    int idx_petli = 0;
    while(getline(plik,linia))
    {
        conditions_tab[idx_petli] = linia;
        idx_petli++;
    }
}
void QuestMenager::check_conditions(int index,int typ,Mapa &mapa,Hero &hero)
{
    int warunki=0;
    string linia;
    string s;
    for(int i=0;i<ilosc;i++)
    {
        if(conditions_tab[i] != "0")
        {
            linia = conditions_tab[i];

            istringstream str(linia);
            str >> type >> idx;

            switch(type)
            {
                case 1 : if(type== typ)
                {
                    exit(0);
                    if(index == idx) conditions_tab[i] = "0";
                    break;
                }
                case 2 :
                    {
                    if(type== typ)  if(index == idx) conditions_tab[i] = "0";
                    break;
                    }

            }
        }
        if(conditions_tab[i] == "0") warunki++;

        if(warunki == ilosc)
        {
            if(only_once == true)
            {
                clear_map(mapa);
                change_map(mapa);
                only_once = false;
            }

            else
                {
                    check_progress(index,typ,mapa,hero);
                }
        }
    }
}
void QuestMenager::clear_map(Mapa& mapa)
{
    ifstream plik;

    switch(nr_questa)
    {
        case 1: plik.open("../Gra/Content/Questy/101/map_clear.txt");break;
        case 2: plik.open("../Gra/Content/Questy/102/map_clear.txt");break;
    }

    if(plik.good() == false )
    {
        cout << "Error wczytywanie clear map questa : " << nr_questa << endl;
        exit(0);
    }

    int nr_lini =0;
    string linia;
    while(getline(plik,linia))
    {
        if(nr_lini%2 == 0)
        {
            istringstream str(linia);
            str >> x >> y;
            x--;
            y--;
        }

        if(nr_lini%2 == 1)
        {
            int id;
            id = stoi(linia);

            mapa.room[y+(x*5)].clear_object(id);

           // mapa.room[y+(x*5)].objects_to_clear = id;
          //  mapa.room[y+(x*5)].should_clear = true;

            cout << y+(x*5) << endl;
            cin >> id;
        }
        nr_lini++;
    }

}
void QuestMenager::check_progress(int index,int typ, Mapa& mapa, Hero &hero)
{
    string linia;
    int act , indeks ;

    cout << endl;

    for(int i =(aktualny_progres*4);i<path_lenght;i++)
    {
        //Path :
        // Condition
        //Location
        // Effect
        // Free lane
        linia = path[i];
        istringstream str(linia);

        if(i%4 == 0) // warunek
        {
            str >> type >> indeks;

            switch(type)
            {
                case 1 : if(type==typ ) if(indeks == index) //fight
                    {
                        aktualny_progres++;
                        go_next = true;
                        break;
                    }
                case 2 :if(type==typ ) if(indeks == index) //speak
                    {
                        go_next = true;
                        break;
                    }

            }
        }

        if(i % 4 == 1) // pobiera info
        {
            str >> x >> y >> act;
            x--;
            y--;
        }
        if(go_next == true)
        {
            //////////////////////////////////////////////////////////
            if(i% 4 == 2 && act == 1) // spawnuje obiekt
            {
                mapa.room[y+(x*5)].change_map(linia);
                go_next= false;
            }
            if(i% 4 == 2 && act == 2) // zmienia dialog
            {
                mapa.room[y+(x*5)].change_dialog(linia);
                go_next= false;
            }
            if(i% 4 == 2 && act == 3) // usun drzwi
            {
                mapa.room[y+(x*5)].open_doors();
                go_next= false;
            }

            if(i% 4 == 2 && act == 4) // clear
            {
                int do_czyszczenia = 0;
                str >> do_czyszczenia;
                mapa.room[y+(x*5)].clear_object(do_czyszczenia);
                go_next= false;
            }

            if(i% 4 == 2 && act == 5) // reward
            {
                int reward =0, number = 0;
                str >> reward >> number;
                hero.reward(reward,number);
                go_next = false;
            }
            if(i%4 == 3);

        }
    }

}
