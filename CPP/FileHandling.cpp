#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "../Header/Elements/spell.h"
using namespace std;
spell File(string K){
    spell Temp;
    string line;
    char* str;
    int i =0;
    ifstream(file);
    file.open("Files/Spell List.txt");
    getline(file,line);
    while(file){
        getline(file,line);
        str = new char[line.length()];
        line.copy(str,line.length(),0);
        if(line.find(K)!=string::npos){
            Temp.rank[i]=str[0]-'0';
            line =line.substr(line.find(K)+K.length(),line.length());
            line.erase(remove(line.begin(), line.end(), ' '), line.end()); 
            Temp.Status[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            Temp.Mana_Cost[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            Temp.Turn[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            Temp.DPS[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            Temp.damage[i]=stoi(line.substr((line.length()-2),line.length()));
            line.pop_back();line.pop_back();
            Temp.Name[i]=line;
            //cout<<Temp.Name[i]<<endl;
            cout<<Temp.rank[i]<<' '<<Temp.Name[i]<<' '<<Temp.damage[i]<<' '<<Temp.DPS[i]<<' '<<Temp.Turn[i]<<' '<<Temp.Mana_Cost[i]<<endl;
            i++;
        }
    }
    file.close();
    return Temp;
}