#pragma once
class Stats
{
protected:
    const int Base_HP = 150;
    const int Base_Mana = 150;
    int Intelligence;
    int Constitution;
    int Vitality;
    int Endurance;

public:
    Stats();
    int Find_New_Max_HP();
    void Levelup();
    int Find_New_Max_Mana();
    int Find_New_Mana_Regen();
    int Find_New_HP_Regen();
    int Find_New_Defense();
    void show_stats();
};