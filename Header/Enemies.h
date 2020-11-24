#pragma once
class Enemeies{
    int *Name;
    int level;   //The higher level the more powerfull something is(tied in with race to set everything else)
    int Max_HP;    //Max health points    
    int Current_HP;   //Current health points
    int HP_Regen;    
    int turn_rate;    //Rate at which attack triggers deafult 1
    int attack;      //attack may be physical or magical and takes a select amount of hp and may also cause effects
    char *race;    //all of the above may or may not change with changes in race
    int Max_Mana;     //Max Mana  Mana=used to cast spells
    int Current_Mana;   //Current Mana Mana=used to cast spells
    int Mana_Regen;

};