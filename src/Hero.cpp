#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <sstream>

#include "Funkcje.h"
#include "Hero.h"

using namespace std;
Hero::Hero(int i, int s, int z , int h)
{
    lvlup = false;

     weapon_int =0;
     weapon_str=0;
     weapon_agl=0;

     armor_int =0;
     armor_str=0;
     armor_agl=0;
     armor_hp=0;

    is_dead = false;
    can_attack = true;

    level = 1;

    sila         = 5;
    inteligencja = 1;
    zrecznosc    = 2;
    exp          = 0;
    health       = 60;

    health_potions = 1;
    mana_potions = 1;

    klasa = "wojownik"; // na testy

    max_energy = 20;
    energy = max_energy;

    ifstream plik;
    for(int i = 0;i<2;i++)
    {
        int liczba = i;
        switch(liczba)
        {
            case 0 : plik.open("../Gra/Content/Items/WeaponList.txt");break;
            case 1 : plik.open("../Gra/Content/Items/ArmorList.txt");break;
        }

        string linia;
        if(plik.good() == false)
        {
            cout << "Blad przy otwieraniu pliku itemow ! " << i << endl;
            exit(0);
        }

        // -----------------WeaponList ---------------------------------------------
        if(i == 0) //WeaponList
        {
            dlugos_WeaponList =0;
            while(getline(plik,linia))dlugos_WeaponList++;

            WeaponList = new string[dlugos_WeaponList];

            int index=0;
            plik.clear();
            plik.seekg( 0, plik.beg);

            while(getline(plik,linia))
            {
                WeaponList[index] = linia;
                index++;
            }
        }
        // --------------------------ArmorList -----------------------------
        if(i == 1)
        {
            dlugos_ArmorList = 0;

            while(getline(plik,linia))dlugos_ArmorList++;

            ArmorList = new string[dlugos_ArmorList];

            int index=0;
            plik.clear();
            plik.seekg( 0, plik.beg);

            while(getline(plik,linia))
            {
                ArmorList[index] = linia;
                index++;
            }
        }
        plik.close();
    }
    calculate_stats();
    health = max_hp;
}
Hero::~Hero()
{
    delete [] ArmorList;
    delete [] WeaponList;
}
Hero::Hero(string n)
{
    nazwa = n;
}
void Hero::wybierz_imie()
{
    string odpowiedz;

    string linia;
    ifstream plik;
    plik.open("../Gra/Content/History/historia.txt");
    while(getline(plik,linia)) cout << linia << endl;


    cout << endl << endl;
    cout << "Choose your name : " ;

 //   cin.ignore();
    getline(cin,nazwa);
    cout << endl;
}
void Hero::wyswiel_wszystko()
{
    wyswietl_staty();
    cout << "Name  : " <<nazwa << endl;
    cout << "Class : " <<klasa << endl;
}
void Hero::show_eq()
{
    calculate_stats();
    system("cls");
    cout << "Your equipment : " << endl << endl;

    cout << "Weapon : " << WeaponList[(weapon*4)]  << endl;
    cout << "Armor  : " << ArmorList[(armor*4)] << endl<<endl;

    cout << "Strenght crystals    : " << strength_crystals << endl;
    cout << "Agility crystals     : " << agility_crystals << endl;
    cout << "Inteligence crystals : " << inteligence_crystals << endl << endl;

    cout << "Health potions       : " << health_potions << endl;
    cout << "Energy potions       : " << mana_potions << endl;
    cout << "Lock picks           : " << lockpicks << endl ;

    cout << "Gold                 : "  << gold << endl;

    show_heroinfo(); ///////////////////////////////////

    char odp;


    white_stringE("1. Leave");
    if(mana_potions > 0) white_stringE("2. Use energy potion ");
        else cout << "2. Use energy potion " << endl;

    if(health_potions > 0) white_stringE("3. Use health potion ");
        else cout << "3. Use health potion " << endl;


    while(true)
    {
        odp = getch();
        if(odp =='1') break;
        if(odp == '2' && mana_potions > 0)
        {
            energy = 20;
            if(energy > max_energy) energy = max_energy;
            mana_potions--;
            break;
        }
        if(odp == '3' && mana_potions > 0)
        {
            health += 50;
            if(health > max_hp) health = max_hp;
            health_potions--;
            break;
        }
    }
}
void Hero::show_heroinfo()
{
    cout << endl;
    cout << nazwa << " stats : " << endl << endl;

    cout << "Hero level :  " << level << endl;
    cout << "Exp :         " << exp << " / " << exp_tolvl << endl << endl;

    cout << "Health :      " << health << " / " << max_hp << endl;
    cout << "Energy :      " << energy << " / " << max_energy << endl << endl;

    cout << "Strength :    " << sila << " + " << armor_str << " + " << weapon_str << endl;
    cout << "Agility :     " << zrecznosc << " + " << armor_agl << " + " << weapon_agl << endl;
    cout << "Inteligence : " << inteligencja << " + " << armor_int << " + " << weapon_int << endl << endl;

    cout << "Damage :      " << damage << endl << endl;


}
void Hero::calculate_stats()
{
    string linia;

    linia = ArmorList[(armor*4)+1];
    istringstream str(linia);
    str >> armor_hp >> armor_str >> armor_int >> armor_agl;

    linia = WeaponList[(weapon*4)+1];
    istringstream stp(linia);
    stp >> weapon_str >> weapon_int >> weapon_agl;

    if(level <=5) exp_tolvl = 100 + (level*50);
    if(level >5 &&level <=10) exp_tolvl = 300 + ((level-5)*100);
    if(level >10 &&level <=15) exp_tolvl = 800 + ((level-10)*150);

    if(exp>=exp_tolvl)
    {
        exp -= exp_tolvl;
        lvlup = true;
    }
    if(lvlup == true)
    {
        green_string("Level up !");
        cout << endl;

        level++;

        sila = level*5;
        inteligencja = level;
        zrecznosc = level*2;

        health = max_hp;
        lvlup = false;
    }

    max_hp = 30 + (level*30) + armor_hp;
    if(klasa == "wojownik")
    {
        damage = sila + armor_str + weapon_str;

        szansa_crit = inteligencja + armor_int + weapon_int;
        if(inteligencja>40) szansa_crit = 40;
    }
    szansa_unik = 10; // nigdzie nie pisze ile maja poszczegulne klasy

}
void Hero::show_options()
{
    for(int i=0;i<5;i++) can_action[i] = false; // czysci tablice;

    white_stringE("0. Rest"); can_action[5] = true;

    if(energy >= 5){white_stringE("1. Normal attack"); can_action[0] = true;}
        else cout << "1. Normal attack" << endl;

    if(health_potions > 0)
    {
        white_stringE("2. Use healing potion ");
        can_action[1] = true;
    }
        else cout << "2. Use healing potion " << endl;

    if(mana_potions > 0)
    {
        white_stringE("3. Use energy potion ");
        can_action[2] = true;
    }
        else cout << "3. Use energy potion " << endl;

    // -------------1st Spell -------------------------------------------------------

}
int Hero::spell_1(Enemy &enemy)
{
    energy -=20;
    if(klasa == "mag")
    {
        if(enemy.type == "fire") return inteligencja;
        else return 60+3*inteligencja;
    }
    if(klasa == "lucznik");
    {
        return 60+3*zrecznosc;
    }
    if(klasa == "wojownik")
    {
        return 60+3*sila;
    }
}
int Hero::normal_attack(Enemy enemy)
{
    srand( time( NULL ) );
    energy -= 5;

        if(rand()% 100 + 1 <= enemy.szansa_unik) cout << "Enemy dodged !"; // unik
            else if(rand()% 100 + 1 <= szansa_crit) // crit
            {
                cout << "You have dealed critical hit for :" << damage*2 <<" !";
                return damage*2;
            }
            else
            {
                cout << "You attacked enemy for :" << damage;
                return damage;
            }
    return 0;
}
void Hero::create_new()
{
    system("cls");

    char odp;

    cout << endl << endl;
    wybierz_imie();

    white_stringE("Press any key to continue ");
    odp = getch();

}
void Hero::reward(int reward,int number)
{
    //reward
    //1 - exp
    //2 - gold
    //3 - armor
    //4 - weapon

    switch(reward)
    {
        case 1 : exp += number ; break;
        case 2 : gold += number ; break;
        case 3 : if(armor < number)
        {
            armor = number;
            new_item_name = ArmorList[(armor*4)];
            break;
        }
        case 4 : if(weapon < number)
        {
            weapon = number;
            new_item_name = WeaponList[(weapon*4)];
            break;
        }
    }
}
