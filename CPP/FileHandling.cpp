#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "../Header/spell.h"
using namespace std;
spell *File(string K,spell* Temp, int &z)
{
    string line;
    char *str;
    int i = 0;
    ifstream(file);
    file.open("Files/Spell List.txt");
    getline(file, line);
    while (file)
    {
        getline(file, line);
        str = new char[line.length()];
        line.copy(str, line.length(), 0);
        if (line.find(K) != string::npos)
        {
            Temp[i].rank = str[0] - '0';
            line = line.substr(line.find(K) + K.length(), line.length());
            line.erase(remove(line.begin(), line.end(), ' '), line.end());
            Temp[i].Status = stoi(line.substr((line.length() - 2), line.length()));
            line.pop_back();
            line.pop_back();
            Temp[i].Mana_Cost = stoi(line.substr((line.length() - 4), line.length()));
            line.pop_back();
            line.pop_back();
            line.pop_back();
            line.pop_back();
            Temp[i].Turn = stoi(line.substr((line.length() - 3), line.length()));
            line.pop_back();
            line.pop_back();
            line.pop_back();
            Temp[i].DPS = stoi(line.substr((line.length() - 3), line.length()));
            line.pop_back();
            line.pop_back();
            line.pop_back();
            Temp[i].damage = stoi(line.substr((line.length() - 4), line.length()));
            line.pop_back();
            line.pop_back();
            line.pop_back();
            line.pop_back();
            Temp[i].Name = line;
            Temp[i].avaliablility=false;
            Temp[i].Tag=z;
            //cout<<Temp.Name[i]<<endl;
            // cout << Temp[i].rank << ' ' << Temp[i].Name << ' ' << Temp[i].damage << ' ' << Temp[i].DPS << ' ' << Temp[i].Turn << ' ' << Temp[i].Mana_Cost << ' ' << Temp[i].Status << endl;
            z++;
            i++;
        }
    }
    file.close();
    return Temp;
}