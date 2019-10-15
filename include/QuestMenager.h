#ifndef QUESTMENAGER_H
#define QUESTMENAGER_H

#include "Map.h"
#include "Hero.h"

using namespace std;

class QuestMenager
{
    public:
        QuestMenager();
        void change_map(Mapa&);
        void load_conditions();
        void check_conditions(int,int,Mapa&,Hero&);
        void check_progress(int,int,Mapa&,Hero& );
        void clear_map(Mapa&);
        void get_rdy(int , Mapa&);

    protected:

        int path_lenght;
        string *path;
        bool only_once;
        bool go_next;

        string *conditions_tab;
        int x;
        int y;
        int index;
        int type;
        int nr_roomu;
        int nr_questa;
        int idx;
        int action;

        int typ;
        int ilosc;
        int aktualny_progres;

    private:
};

#endif // QUESTMENAGER_H
