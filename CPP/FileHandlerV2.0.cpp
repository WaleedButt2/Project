#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "../Header/Enemy.h"
using namespace std;
void File_V2(Enemy *Temp)
{
    string line;
    ifstream(file);
    file.open("Files/Enemies.txt");
    getline(file, line);
    int i = 0;
    while (file)
    {
        getline(file, line);
        if (line == "-1")
            break;
        line.erase(remove(line.begin(), line.end(), ' '), line.end()); //cout<<line<<endl;
        Temp[i].turn_rate = stoi(line.substr((line.length() - 2), line.length()));
        line.pop_back();
        line.pop_back();
        Temp[i].Mana_Regen = stoi(line.substr((line.length() - 4), line.length()));
        line.pop_back();
        line.pop_back();
        line.pop_back();
        line.pop_back();
        Temp[i].HP_Regen = stoi(line.substr((line.length() - 4), line.length()));
        line.pop_back();
        line.pop_back();
        line.pop_back();
        line.pop_back();
        Temp[i].Max_Mana = stoi(line.substr((line.length() - 5), line.length()));
        Temp[i].Current_Mana = Temp[i].Max_Mana;
        line.pop_back();
        line.pop_back();
        line.pop_back();
        line.pop_back();
        line.pop_back();
        Temp[i].Max_HP = stoi(line.substr((line.length() - 5), line.length()));
        Temp[i].Current_HP = Temp[i].Max_HP;
        line.pop_back();
        line.pop_back();
        line.pop_back();
        line.pop_back();
        line.pop_back();
        Temp[i].Base_Attack = stoi(line.substr((line.length() - 5), line.length()));
        line.pop_back();
        line.pop_back();
        line.pop_back();
        line.pop_back();
        line.pop_back();
        Temp[i].level = stoi(line.substr((line.length() - 3), line.length()));
        line.pop_back();
        line.pop_back();
        line.pop_back();
        if (line.find("NULL") != string::npos)
        {
            Temp[i].race = line.substr(line.find("NULL") + 5, line.length());
        }
        else
        {
            size_t found = line.find(":");
            Temp[i].Name = line.substr(0, found);
            Temp[i].race = line.substr(found + 1, line.length());
        }
        i++;
    }
}