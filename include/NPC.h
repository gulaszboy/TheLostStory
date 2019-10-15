#ifndef NPC_H
#define NPC_H

#include <iostream>
using namespace std;

class NPC
{
    public:
        NPC();
        NPC(int);

        int nr_dialogu;
        int index;

        void load(int);
        void change_dialog(int);
        string name;


    protected:

    private:
};

#endif // NPC_H
