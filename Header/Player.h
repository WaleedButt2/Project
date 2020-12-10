#pragma once
#include "../Header/SpellBook.h"
#include "Stats.h"
#include "Inventory.h"
#include "../Header/Enemy.h"
struct Use
{
    unsigned int DPS = 0;
    unsigned int TurnRate = 0;
};
class Player : public Stats, public SpellBook, public Inventory
{
protected:
    Use DPS_inflicted_with[10];
    string Name;
    int level;
    int Max_HP;     //Max health points
    int Current_HP; //Current health points
    int HP_Regen;
    int Max_Mana;     //Max Mana  Mana=used to cast spells
    int Current_Mana; //Current Mana Mana=used to cast spells
    int Mana_Regen;
    int Defense;
    int Max_Exp_Needed;
    int Current_Exp;
    spell Spell_Inflicted_With;

public:
    Player();
    void Take_Damage(spell a); //pass tag of spell to inflict damage
    spell Use_spell();
    int get_current_hp();
    void levelup(int x);
    void Compute_DPS();
    void Tick();
    void Set_Item(string x);
    void Show_Items();
    void Use_Items();
    void operator=(Player const &x);
    friend class Dungeon_Floor;
    friend void File_za_wardo(Enemy Monster,Player x,bool flag);
};