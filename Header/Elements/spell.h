#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;
class spell{
    protected:
    string Name[9];
    int rank[9];
    int damage[9];
    int DPS[9];
    int Mana_Cost[9];
    int Turn[9];
    int Status[9];
};