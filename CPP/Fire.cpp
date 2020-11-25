#include "../Header/Fire.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm> 
using namespace std;
string removeSpaces(string str){ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 
Fire::Fire(){
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
        if(line.find("Fire")!=string::npos){
            rank[i]=str[0]-'0';
            line =line.substr(line.find("Fire")+9,line.length());
            line=removeSpaces(line);
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
    file.close();
}