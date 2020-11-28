#include <string>
#include "../Header/Player.h"
Player::Player()
{
    cout << "Enter Player Name" << endl;
    cin >> Name;
    level = 1;
    HP_Regen = Find_New_HP_Regen();
    Mana_Regen = Find_New_Mana_Regen();
    Current_Mana = Max_Mana = Find_New_Max_Mana();
    Current_HP = Max_HP = Find_New_Max_HP();
    Defense = Find_New_Defense();
    Max_Exp_Needed = level * 100;
}
void Player::Damage_inflicted(int a)
{
    spell x = search_spell(a);
    cout<<x.damage<<' '<<x.DPS<<endl;
    for (int i = 0; i < 10; i++)
    {
        if (DPS_inflicted_with[i].DPS == 0){
            DPS_inflicted_with[i].DPS = x.DPS;
            DPS_inflicted_with[i].TurnRate = x.Turn;
            break;
        }
    }
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
    Current_HP = Current_HP - ((1 - Defense / 100) * x.damage);
    if (Current_HP <= 0)
        Current_HP = 0;
}
void Player::levelup()
{
    Levelup();
    level++;
    Current_HP = Max_HP = Find_New_Max_HP();
    Current_Mana = Max_Mana = Find_New_Max_Mana();
    Mana_Regen = Find_New_Mana_Regen();
    HP_Regen = Find_New_HP_Regen();
    Defense = Find_New_Defense();
    Max_Exp_Needed = level * 100;Current_Exp = 0;
}
spell Player::Use_spell(){
    spell x;int a;
    cout<<"Choose Spell To Cast and -1 to Skip Turn"<<endl;
    show_avaliable_spells();
    cin>>a;
    x=search_spell(a);
    if(a=-1) x.Tag=-1;                    //-1 one means no spell has been used
    //cout<<x.Name<<endl;
    return x;
}
int Player::get_current_hp()
{
    return Current_HP;
}
