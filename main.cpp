#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm> 
#include "Header/Player.h"
using namespace std;
int main(){
    string s="HydroBullets";
    Player x;
    x.learn_spell(s);
    x.Use_spell();
    //cout<<x.get_current_hp()<<endl;
    //x.Damage_inflicted(s);
    //cout<<x.get_current_hp()<<endl;
    //for(int i=0;i<50;i++) x.Levelup();
    //cout<<x.Find_New_Max_Mana()<<endl;
}