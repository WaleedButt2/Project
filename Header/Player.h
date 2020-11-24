#pragma once
#include "SpellBook.h"
#include <strings.h>
#include "Stats.h"
class Player{
    char* Name;
    int level;
    int Max_HP;    //Max health points
    int Current_HP;   //Current health points
    int HP_Regen;
    int Max_Mana;   //Max Mana  Mana=used to cast spells
    int Current_Mana;   //Current Mana Mana=used to cast spells
    int Mana_Regen;
    int base_attack;      //attack may be physical or magical and takes a select amount of hp and may also cause effects
    SpellBook Avaliable_Spells;
    int Defense;
    Stats stat;
};