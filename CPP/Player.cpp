#include "../Header/Player.h"
Player::Player()
{
    Name = "Merlin";
    level = 0;
    HP_Regen = Find_New_HP_Regen();
    Mana_Regen = Find_New_Mana_Regen();
    Current_Mana = Max_Mana = Find_New_Max_Mana();
    Current_HP = Max_HP = Find_New_Max_HP();
    Defense = Find_New_Defense();
    Max_Exp_Needed = level * 100;
    Current_Exp = 0;
}
void Player::Compute_DPS()
{
    for (int i = 0; i < 10; i++)
    {
        if (DPS_inflicted_with[i].TurnRate != 0)
        {
            if (Defense >= 90)
                Defense = 90;
            Current_HP = Current_HP - ((1 - Defense / 100) * DPS_inflicted_with[i].DPS);
            DPS_inflicted_with[i].TurnRate--;
        }
    }
}
void Player::Take_Damage(spell a)
{
    spell x = search_spell(a.Tag);
    for (int i = 0; i < 10; i++)
    {
        if (DPS_inflicted_with[i].DPS == 0)
        {
            DPS_inflicted_with[i].DPS = x.DPS;
            DPS_inflicted_with[i].TurnRate = x.Turn;
            cout << endl;
            break;
        }
    }
    Current_HP = Current_HP - ((1 - Defense / 100) * x.damage);
    if (Current_HP <= 0)
        Current_HP = 0;
}
void Player::levelup(int x)
{
    int Excess_Exp;
    Current_Exp = x;
    if (Current_Exp >= Max_Exp_Needed)
    {
        while (Current_Exp >= Max_Exp_Needed)
        {
            Levelup();
            level++;
            Excess_Exp = Current_Exp - Max_Exp_Needed;
            Current_Exp = 0;
            Max_Exp_Needed = level * 100;
            Current_Exp = Current_Exp + Excess_Exp;
        }
        Current_HP = Max_HP = Find_New_Max_HP();
        Current_Mana = Max_Mana = Find_New_Max_Mana();
        Mana_Regen = Find_New_Mana_Regen();
        HP_Regen = Find_New_HP_Regen();
        Defense = Find_New_Defense();
        Max_Exp_Needed = level * 100;
        Current_Exp = 0;
    }
    else
    {
        cout << "Not Enough Exp" << endl;
    }
}
spell Player::Use_spell()
{
    spell x;
    int a;
    cout << "Choose Spell To Cast and -1 to Skip Turn" << endl;
    show_learned_spells();
    cin >> a;
    x = search_spell(a);
    if (a == -1)
        x.Tag = -1; //-1 one means no spell has been used
    //cout<<x.Name<<endl;
    //cout<<x.Name;
    return x;
}
void Player::Tick()
{
    Compute_DPS();
    Current_HP = Current_HP + HP_Regen;
    if(Current_HP>Max_HP)  Current_HP=Max_HP;
    else if (Current_HP<0)  Current_HP=0;
    Current_Mana = Current_Mana + Mana_Regen;
    if(Current_Mana>Max_Mana)  Current_Mana=Max_Mana;
    else if (Current_Mana<0)  Current_Mana=0;
}
int Player::get_current_hp()
{
    return Current_HP;
}