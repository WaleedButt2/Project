#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "../Header/Enemy.h"
#include "../Header/Player.h"
using namespace std;
void File_za_wardo(Enemy Monster,Player x,bool flag){
    string line,word;
    ofstream(file);
    bool OverWrite=false;
    file.open("Files/Battle Records.txt",ios::app);
    if(flag==false)   word="NO";else word="YES";
    if(Monster.race.length()<4) file<<Monster.race<<"\t\t\t\t";
    else if(Monster.race.length()<8) file<<Monster.race<<"\t\t\t";
    else if(Monster.race.length()<12) file<<Monster.race<<"\t\t";
    else file<<Monster.race<<"\t";
    file<<Monster.Max_HP<<"\t\t\t"<<Monster.level<<"\t\t"<<x.Max_HP<<"\t\t\t\t"<<x.level<<"\t\t\t\t"<<word<<endl;
}