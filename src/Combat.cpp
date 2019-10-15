#include "Combat.h"
#include "Room.h"
#include "Funkcje.h"

#include <time.h>
#include <cstdlib>
#include <math.h>
#include <windows.h>
#include <conio.h>


using namespace std;
Combat::Combat()
{
    ;
}

void Combat::fight_lost()
{
    game_end(1);
}

void Combat::fight_won(Mapa &mapa,Hero &hero)
{
    cout << "You won !" << endl;
    Enemy enemy(mapa.index_moba);
    hero.reward(1,enemy.exp);
    cout << "You earn " << enemy.exp << " exp for fight !" << endl;

    mapa.clear_object(1);
    mapa.enemies_killed++;

}

void Combat::fight(Hero &hero, Mapa &mapa)
{
    Enemy enemy(mapa.index_moba);
    hero.calculate_stats();
    srand( time( NULL ) );
    int tura = 0;

    system("cls");

    while (hero.is_dead ==false && enemy.is_dead == false)
    {
        if (tura == 0)
        {
            cout << "Hero turn !" << endl;




            if(rand()% 100 + 1 <= enemy.szansa_unik); // unik
                else if(rand()% 100 + 1 <= hero.szansa_crit) enemy.affect_health(hero.damage*2); // crit
                    else enemy.affect_health(hero.damage);

            enemy.check_is_dead();
        }

        if (tura == 1)
        {
            cout << "Enemy turn !" << endl;

            if(rand()% 100 + 1 <= hero.szansa_unik); // unik
                else if(rand()% 100 + 1 <= enemy.szansa_crit) hero.affect_health(enemy.damage*2);// crit
                    else hero.affect_health(enemy.damage);

            hero.check_is_dead();
        }
        tura++;
        tura %= 2;
    }
    if (enemy.is_dead) fight_won(mapa,hero);
    if (hero.is_dead) fight_lost();
}
void Combat::fightTest(Hero &hero, Mapa &mapa)
{
    srand( time( NULL ) );

    int tura = 0;
    char pick;
    string cokolwiek;
    bool moved;

    system("cls");

    Enemy enemy(mapa.index_moba);
    hero.calculate_stats();

    while (hero.is_dead ==false && enemy.is_dead == false)
    {
        if (tura == 0)
        {
            moved = false;

            cout << "Hero turn !" << endl;

            cout <<"Summary :" << endl;
            cout << "Your hp : " << hero.show_health() <<endl;
            cout << "Your energy : " << hero.energy << endl;

            hero.show_options();

            while(moved == false)
            {
                pick = getch();

                // ------------ Wait ----------------------------------------------------------------
                if(pick == '0')moved = true;

                // ------------ Normal Attack -------------------------------------------------------
                if(hero.can_action[0] == true && pick == '1')moved = true;

                //-------------Healing potion --------------------------------------------------------
                if(hero.can_action[1] == true && pick == '2') moved = true;

                //-------------Energy potion --------------------------------------------------------
                if(hero.can_action[2] == true && pick == '3') moved = true;
            }
                system("cls");

                // ------------ Wait ----------------------------------------------------------------
                if(pick == '0')
                {
                    hero.energy += 10;
                    if(hero.energy > hero.max_energy) hero.energy = hero.max_energy;
                    cout << "You wait to regenerate some energy" ;
                }
                // ------------ Normal Attack -------------------------------------------------------
                if(hero.can_action[0] == true && pick == '1')
                {
                    enemy.affect_health(hero.normal_attack(enemy));
                }

                //-------------Healing potion --------------------------------------------------------
                if(hero.can_action[1] == true && pick == '2')
                {
                    hero.health += 50;
                    if(hero.health > hero.max_hp) hero.health = hero.max_hp;
                    hero.health_potions--;
                    moved = true;
                }

                //-------------Energy potion --------------------------------------------------------
                if(hero.can_action[2] == true && pick == '3')
                {
                    hero.energy = 20;
                    if(hero.energy > hero.max_energy) hero.energy = hero.max_energy;
                    hero.mana_potions--;
                    moved = true;
                }

                // ------------- 1st Spell -----------------------------------------------------------
    //            if(hero.can_action[1]== true && pick == '2')
     //           {
    //                enemy.affect_health(hero.spell_1(enemy));
    //            }

            cout << endl << endl;
            enemy.check_is_dead();

        }

        if (tura == 1)
        {
            cout << "Enemy turn !" << endl;

            cout << "Summary : " << endl<< endl;

            cout << "Enemy name : " << enemy.nazwa << endl;
            cout << "Enemy health : " << enemy.show_health() << endl;
            cout << "Enemy damage : " << enemy.damage << endl;

            if(rand()% 100 + 1 <= hero.szansa_unik) cout << "You have dodged !"; // unik
                else if(rand()% 100 + 1 <= enemy.szansa_crit)// crit
                {
                    hero.affect_health(enemy.damage*2);
                    cout << "Enemy has dealed critical hit for :" << enemy.damage*2 <<" !";
                }
                    else
                    {
                        hero.affect_health(enemy.damage);
                        cout << "Enemy attacked you for :" << enemy.damage;
                    }

            cout << endl << endl;
            hero.check_is_dead();
        }
        tura++;
        tura %= 2;
    }
    if (enemy.is_dead) fight_won(mapa,hero);
    if (hero.is_dead) fight_lost();
    cokolwiek = getch();
}
