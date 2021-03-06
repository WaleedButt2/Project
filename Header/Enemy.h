#pragma once
#include "../Header/SpellBook.h"
struct Jo
{
    int DPS = 0;
    int TurnRate = 0;
};
class Enemy : public SpellBook
{
public:
    Jo DPS_inflicted_with[10];
    string Name = "\0";
    int level;      //The higher level the more powerfull something is(tied in with race to set everything else)
    int Max_HP;     //Max health points
    int Current_HP; //Current health points
    int HP_Regen;
    int turn_rate;    //Rate at which attack triggers deafult 1
    int Base_Attack;  //attack may be physical or magical and takes a select amount of hp and may also cause effects
    string race;      //all of the above may or may not change with changes in race
    int Max_Mana;     //Max Mana  Mana=used to cast spells
    int Current_Mana; //Current Mana Mana=used to cast spells
    int Mana_Regen;

public:
    friend void File_V2(Enemy *Temp);
    void Take_Damage(spell a);
    spell Use_spell();
    void compute_DPS();
    void Tock();
    spell Boss_Attack();
};