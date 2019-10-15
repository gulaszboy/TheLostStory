#include "NPC.h"
#include <fstream>
#include <cstdlib>

using namespace std;

NPC::NPC()
{
    ;
}
NPC::NPC(int dialog)
{
    nr_dialogu = dialog;
}
void NPC::change_dialog(int dialog)
{
    nr_dialogu == dialog;
}
void NPC::load(int idx)
{
    index = idx;
    nr_dialogu = index;
    ifstream plik;

    switch(index)
    {
        case 1 : plik.open("../Gra/Content/NPC/101.txt"); break;
        case 2 : plik.open("../Gra/Content/NPC/102.txt"); break;
        case 3 : plik.open("../Gra/Content/NPC/103.txt"); break;
        case 4 : plik.open("../Gra/Content/NPC/104.txt"); break;
        case 5 : plik.open("../Gra/Content/NPC/105.txt"); break;
        case 6 : plik.open("../Gra/Content/NPC/106.txt"); break;

        default : cout << "Zly index przeciwnika !";
    }

    if(plik.good() == false)
    {
        cout << "Problem z odczytaniem pliku NPC !" << endl;
        exit(0);
    }

    int nr_lini=1;
    string linia;

    while(getline(plik,linia))
    {
        switch(nr_lini)
        {
            case 1 : name = linia; break;
        }
        nr_lini++;
    }
    plik.close();
}
