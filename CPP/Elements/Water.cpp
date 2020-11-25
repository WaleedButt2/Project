#include "../../Header/Elements/Water.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm> 
using namespace std;
Water::Water(){
    string line;
    char *str;
    int i =0;
    ifstream(file);
    file.open("Files/Spell List.txt");
    getline(file,line);
    while(file){
        getline(file,line);
        str = new char[line.length()];
        line.copy(str,line.length(),0);
        if(line.find("Water")!=string::npos){
            rank[i]=str[0]-'0';
            line =line.substr(line.find("Water")+5,line.length());
            line.erase(remove(line.begin(), line.end(), ' '), line.end()); 
            Status[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            Mana_Cost[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            Turn[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            DPS[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            damage[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            Name[i]=line;
            //cout<<rank[i]<<' '<<Name[i]<<' '<<damage[i]<<' '<<DPS[i]<<' '<<Turn[i]<<' '<<Mana_Cost[i]<<endl;
            i++;
        }
        delete str;
    }
    //cout<<rank[2]<<' '<<Name[2]<<' '<<damage[2]<<' '<<DPS[2]<<' '<<Turn[2]<<' '<<Mana_Cost[2]<<endl;
    file.close();
}