#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <string>

using namespace std;
class Unit
{
    protected:

    int mana;
    int gold;



    int sila;
    int inteligencja;
    int zrecznosc;


    public:
        string nazwa;

        bool can_attack;
        bool is_dead;

        float szansa_unik;
        float szansa_crit;
        int damage;
        int energy;
        int exp;
        int health;

        int show_health();
        void wyswietl_staty();
        void affect_health(int);
        void check_is_dead();
};

#endif // UNIT_H
