#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;
class spell
{
public:
    string Name;
    int rank;
    int damage;
    int DPS;
    int Mana_Cost;
    int Turn;
    int Status;
    bool avaliablility = false;
    int Tag;
    bool Taken = false;
    friend spell *File(string K, spell *Temp, int &z);
};