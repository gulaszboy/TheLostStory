#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <conio.h>

#include "Map.h"
#include "Funkcje.h"
#include "Hero.h"
#include "windows.h"
#include "Tutorial.h"

using namespace std;

void wysrodkuj(string n)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    int dlugosc = 100;
    dlugosc = 80 - n.length();
    for(int i=0;i<(dlugosc/2);i++) cout << " ";
    cout << n;
    for(int i=0;i<(dlugosc/2);i++) cout << " ";
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void menu(Hero &hero)
{
    char odpowiedz;

    wysrodkuj("The Lost Story ");
    cout << endl;
    cout << endl;

    wysrodkuj("1.Start");
    wysrodkuj("2.Exit");

    while(true)
    {
        odpowiedz = getch();
        if(odpowiedz == '1')
        {
            hero.create_new();
            break;
        }

        if(odpowiedz == '2')
        {
            exit(0);
            break;
        }

    }

}
int stoi(string s)
{
    int liczba;
    istringstream str(s);

    str >> liczba;
    return liczba;
}
void green_char(char text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void red_char(char ch)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout << ch;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void blue_char(char ch)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    cout << ch;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void grey_char(char ch)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    cout << ch;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void white_stringE(string text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout << text << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void white_string(string text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void white_char(char text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void green_string(string text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}

void game_end(int index)
{
    system("cls");

    cout << endl;
    if(index == 1)
    {
        white_stringE("You lost !");
        cout << "Better luck next time !" << endl;
    }
    if(index == 2)
    {
        white_stringE("You won !");
        cout << "You reached the end of Chapter 1 !"<< endl;
        cout << "For this time no more is ready " << endl;
    }
    cout << endl;
    cout << "Thank you for playing our game !" << endl;

    cout << endl;
    cout << "Please leave us some feedback at makeapp.club" << endl;

    cout << endl;
    cout << "Creators : " << endl;
    white_stringE("Kamil Adamczyk");
    white_stringE("Kacper Kupiszewski");
    white_stringE("Sebastian Banas");
    white_stringE("Aleksandra Chmiel");
    white_stringE("Karolina Targosz");
    white_stringE("Magdalena Branka");

    char odp;
    odp = getch();
    exit(0);
}
