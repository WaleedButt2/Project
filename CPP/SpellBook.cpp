#include "FileHandling.cpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "../Header/SpellBook.h"
using namespace std;
SpellBook::SpellBook()
{
    int z=0;
    File("Fire", Elements[0],z);
    File("Water", Elements[1],z);
    File("Ice", Elements[2],z);
    File("Wind", Elements[3],z);
    File("Earth", Elements[4],z);
    File("Lightning", Elements[5],z);
}
void SpellBook::show_avaliable_spells()
{
    cout<<"Tag\tName\t\tMana Cost"<<endl;
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (Elements[j][i].avaliablility==true)
            {
                cout << Elements[j][i].Tag << "    " << Elements[j][i].Name << "\t" << Elements[j][i].Mana_Cost << endl;
            }
        }
    }
}
void SpellBook::show_learnable_spells(int x)
{
    x = x / 5;
    //cout<<x<<endl;
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if ((Elements[j][i].rank <= x) && !Elements[j][i].avaliablility)
                cout << Elements[j][i].rank << "  " << Elements[j][i].Name << "  " << Elements[j][i].Mana_Cost << endl;
        }
    }
}
void SpellBook::learn_spell(string x)
{
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (x.compare(Elements[j][i].Name) == 0)
            {
                Elements[j][i].avaliablility = true;
                break;
            }
        }
    }
}
spell SpellBook::search_spell(int s)
{
    spell x;
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 10; i++)
            if (s==Elements[j][i].Tag){
                x = Elements[j][i];
            }
    }
    //cout<<x.Name;
    return x;
}