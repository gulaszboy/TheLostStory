#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <conio.h>

#include "Ekwipunek.h"
#include "Map.h"
#include "Funkcje.h"
#include "Hero.h"
#include "windows.h"

using namespace std;

void open_chest(Hero &hero,int difficulty,Mapa &mapa)
{
    system("cls");
    char odp;
    bool passed = false;

    int j=0;
    int chest_code[10];

    srand( time( NULL ) );

    while(true)
    {
        if(difficulty > 10)
        {
            switch(difficulty)
            {
                case 11 : hero.reward(4,2); break;
                case 12 : hero.reward(4,3); break;
            }

            cout << "Chest wasn't locked !" << endl;
            cout << "You found " << hero.new_item_name << endl;

            white_stringE("Press any key");
            odp = getch();
            break;
        }
        else
        {
            for(int i =0;i<10;i++) chest_code[i] = 0;
            for(int i =0;i<difficulty;i++) chest_code[i] = rand()%2+1;

            cout << "You have found a chest but it seem to be locked." << endl;
            cout << "Try to find right combination to unlock the chest with ";
            white_stringE("A/D");
            white_stringE("1. Abandon");

            cout << "You have " << hero.lockpicks << " lockpicks left. " << endl;

            while(true)
            {
                if(hero.lockpicks <=0)
                {
                    white_stringE("You're out of lockpicks !");
                    cout << endl;

                    white_stringE("Press any key.");
                    string od;
                    od=getch();

                    break;
                }

                odp = getch();

                if(odp == 'a' && chest_code[j] == 1)
                    {
                        red_char('A');
                        j++;
                        if(chest_code[j] == 0){passed=true;break;}
                    }
                    else if(odp == 'd' && chest_code[j] == 2)
                        {
                            red_char('D');
                        j++;
                        if(chest_code[j] == 0){passed=true;break;}
                        }
                    else if(odp == '1') break;
                        else
                        {
                            j=0;
                            system("cls");
                            white_stringE("Wrong ! You lost one lockpick !");

                            cout << "You have found a chest but it seem to be locked." << endl;
                            cout << "Try to find right combination to unlock the chest with ";
                            white_stringE("A/D");
                            white_stringE("1. Abandon");

                            hero.lockpicks--;
                            cout << "You have " << hero.lockpicks << " lockpicks left. " << endl;
                        }
            }
            if(passed == true)random_loot(hero,difficulty*2,mapa);
            break;
        }

    }

}
void random_loot(Hero &hero,int difficulty,Mapa &mapa)
{
    char odp;
    int drop[6];
    for(int i=0;i<6;i++) drop[i] = 0;

    srand( time( NULL ) );
    if(difficulty == 0) difficulty = 2;

    for(int i=0;i<difficulty;i++)
    {
        int number = rand()%7+1;
        switch(number)
        {
            case 1 :hero.strength_crystals++,drop[0]++   ;break;
            case 2 :hero.agility_crystals++,drop[1]++    ;break;
            case 3 :hero.inteligence_crystals++,drop[2]++;break;

            case 4 :hero.health_potions++,drop[3]++      ;break;
            case 5 :hero.mana_potions++, drop[4]++       ;break;
            case 6 :hero.lockpicks+=2,  drop[5]++         ;break;
            case 7 :;break;//Pusty traf
        }
    }
    //--------------Wyswietla loot -------------------------------------------
    cout <<endl << "You found :" << endl << endl;

    if(drop[0] >0)cout << drop[0] <<" Strength crystals " << endl;
    if(drop[1] >0)cout << drop[1] <<" Agility crystals "<< endl;
    if(drop[2] >0)cout << drop[2] <<" Inteligence crystals "<< endl;
    cout << endl;

    if(drop[3] >0)cout << drop[3] <<" Health potions"<< endl;
    if(drop[4] >0)cout << drop[4] <<" Mana potions"<< endl;
    if(drop[5] >0)cout << drop[5] <<" Lock picks"<< endl;
    odp = getch();
    mapa.clear_object(3);


    //------------------------------------------------------------------------
}

