#include "../Header/Stats.h"
#include <math.h>
#include <iostream>
Stats::Stats()
{
    Intelligence = 5;
    Constitution = 10;
    Vitality = 5;
    Endurance = 15;
}
int Stats::Find_New_Max_HP()
{
    int HP;
    if (Constitution >= 130)
    {
        HP = Constitution * 40 + Base_HP;
    }
    else
    {
        HP = Constitution * 20 + Base_HP;
    }

    return HP;
}
int Stats::Find_New_HP_Regen()
{
    int HP_Regen = 5;
    if (Vitality > 10)
        HP_Regen = HP_Regen + Vitality - 10;
    return HP_Regen;
}
int Stats::Find_New_Max_Mana()
{
    int Mana;
    if (Intelligence >= 140)
        Mana = Intelligence * 55 + Base_Mana;
    else
    {
        Mana = Intelligence * 25 + Base_Mana;
    }
    return Mana;
}
int Stats::Find_New_Mana_Regen()
{
    int Mana_Regen = Intelligence * 2;
    return Mana_Regen;
}
int Stats::Find_New_Defense()
{
    return pow(Endurance, (1 / 1.5));
}
void Stats::Levelup()
{
    Intelligence = Intelligence + 3;
    Constitution = Constitution + 3;
    Vitality = Vitality + 2;
    Endurance = Endurance + 3;
}
void Stats::show_stats()
{
    std::cout << "Intelligence: " << Intelligence << "\nConstitution: " << Constitution << "\nVitality: " << Vitality << "\nEndurance: " << Endurance << std::endl;
}