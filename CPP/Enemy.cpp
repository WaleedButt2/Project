#include "../Header/Enemy.h"
#include <ctime>
void Enemy::Take_Damage(spell a)
{
    if (a.Tag == -1)
        return;
    for (int i = 0; i < 10; i++)
    {
        if (DPS_inflicted_with[i].TurnRate == 0)
        {
            DPS_inflicted_with[i].DPS = a.DPS;
            DPS_inflicted_with[i].TurnRate = a.Turn;
            cout << endl;
            break;
        }
    }
    Current_HP = Current_HP - a.damage;
    if (Current_HP <= 0)
        Current_HP = 0;
}
void Enemy::compute_DPS()
{
    for (int i = 0; i < 10; i++)
    {
        if (DPS_inflicted_with[i].TurnRate != 0)
        {
            Current_HP = Current_HP - DPS_inflicted_with[i].DPS;
            DPS_inflicted_with[i].TurnRate--;
        }
        if (DPS_inflicted_with[i].TurnRate == 0)
            DPS_inflicted_with[i].DPS = 0;
    }
    if (Current_HP < 0)
        Current_HP = 0;
}
void Enemy::Tock()
{
    Current_HP = Current_HP + HP_Regen;
    compute_DPS();
    if (Current_HP > Max_HP)
        Current_HP = Max_HP;
    else if (Current_HP < 0)
        Current_HP = 0;
    Current_Mana = Current_Mana + Mana_Regen;
    if (Current_Mana > Max_Mana)
        Current_Mana = Max_Mana;
    else if (Current_Mana < 0)
        Current_Mana = 0;
}
spell Enemy::Use_spell()
{
    srand((unsigned)time(0));
    spell x;
    int randNum;
    int a = level / 5;
    int rd = (rand() % 5);
    x = Elements[rd][a];
    cout << Name << " used " << x.Name << endl;
    return x;
}
spell Enemy::Boss_Attack()
{
    spell x;
    srand((unsigned)time(0));
    int randnum = rand() % 10 + 1;
    if (randnum <= 5)
    {
        x.Tag = -1;
    }
    else
    {
        x = Use_spell();
    }
    return x;
}