#ifndef HERO_H
#define HERO_H

#include <Unit.h>
#include "Enemy.h"

class Hero : public Unit
{
protected:
    string klasa;
    int level;
    bool lvlup;



    public:
        int exp_tolvl;
        int max_energy;
        int max_hp;

        Hero( int , int , int, int );
        Hero(string );
        ~Hero();

        bool can_action[6];

        void calculate_stats();
        void wybierz_imie();
        void wyswiel_wszystko();
        void show_options();
        void show_heroinfo();
        void create_new();
        void reward(int,int);

        int normal_attack(Enemy);
        int spell_1(Enemy&);


        //-----------Ekwipunek ------------------------
        void show_eq();

        string *ItemList;
        string *WeaponList;
        string *ArmorList;

        int weapon;
        int armor;

        string new_item_name;

        int dlugos_WeaponList;
        int dlugos_ArmorList;

        int strength_crystals;
        int agility_crystals;
        int inteligence_crystals;

        int health_potions;
        int mana_potions;

        int lockpicks;

        int weapon_int;
        int weapon_str;
        int weapon_agl;

        int armor_int;
        int armor_str;
        int armor_agl;
        int armor_hp;
        //---------------------------------------------
};

#endif // HERO_H
