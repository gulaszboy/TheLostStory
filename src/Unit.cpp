#include "Unit.h"
using namespace std;


void Unit::wyswietl_staty()
{
    cout << "Statystyki : " << nazwa << endl;
    cout << "Sila : " << sila << endl;
    cout << "Zrecznosc : " << zrecznosc << endl;
    cout << "Inteligencja : " << inteligencja << endl;
    cout << "Punkty zycia : " << health << endl;
}
void Unit::affect_health(int change)
{
    health -= change;
}
void Unit::check_is_dead()
{
    if (health <= 0) is_dead = true;
    else is_dead = false;
}
int Unit::show_health()
{
    return health;
}
