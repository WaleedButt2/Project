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
void Player::operator=(Player const &x)
{
    Name = x.Name;
    level = x.level;
    Max_HP = x.Max_HP;
    Current_HP = x.Current_HP;
    Max_Mana = x.Max_Mana;
    Current_Mana = x.Current_Mana;
    HP_Regen = x.HP_Regen;
    Mana_Regen = x.Mana_Regen;
    Defense = x.Defense;
    Max_Exp_Needed = x.Max_Exp_Needed;
    Current_Exp = x.Current_Exp;
    Constitution = x.Constitution;
    Intelligence = x.Intelligence;
    Vitality = x.Vitality;
    Endurance = x.Endurance;
    for (int i = 0; i++; i < 10)
    {
        Potions[i] = x.Potions[i];
        Value[i] = x.Value[i];
    }
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
    Current_Exp = Current_Exp + x;
    if (Current_Exp >= Max_Exp_Needed)
    {
        while (Current_Exp >= Max_Exp_Needed)
        {
            cout << "You Have Levelled Up\n";
            Levelup();
            level++;
            Current_Exp = Current_Exp - Max_Exp_Needed;
            Max_Exp_Needed = level * 100;
        }
        Current_HP = Max_HP = Find_New_Max_HP();
        Current_Mana = Max_Mana = Find_New_Max_Mana();
        Mana_Regen = Find_New_Mana_Regen();
        HP_Regen = Find_New_HP_Regen();
        Defense = Find_New_Defense();
        Max_Exp_Needed = level * 100;
        Current_Exp = 0;
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
    if (x.avaliablility != true)
    {
        cout << "\nEnter valid Tag\n";
        a = -1;
    }
    if (a == -1)
        x.Tag = -1; //-1 one means no spell has been used
    //cout<<x.Name;
    return x;
}
void Player::Tick()
{
    Current_HP = Current_HP + HP_Regen;
    Compute_DPS();
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
int Player::get_current_hp()
{
    return Current_HP;
}
void Player::Set_Item(string x)
{
    char a = x[2];
    int val = stoi(x.substr(0, x.length()-1));
    //cout<<x[2]<<' '<<val<<endl;
    for (int i = 0; i < 10; i++)
    {
        if (Value[i] == 0)
        {
            Value[i] = val;
            Potions[i] = a;
            //cout<<Potions[i]<<' '<<Value[i]<<endl;
            break;
        }
        if (i == 9)
        {
            cout << "Inventory is full\nWould you like to replace an item\n";
            Use_Items();
            Set_Item(x);
            break;
        }
    }
    cout << "Items have been put into Inventory\n";
}
void Player::Show_Items()
{
    int P = 0, H = 0, M = 0, E = 0;
    for (int i = 0; i < 10; i++)
    {
        if (Potions[i] == 'P' && Value[i] == 99)
            E++;
        else if (Potions[i] == 'P')
            P++;
        else if (Potions[i] == 'H')
            H++;
        else if (Potions[i] == 'M')
            M++;
    }
    cout << "You have These Potions Avaliable Select One\n";
    cout << H << " Health potions\n";
    cout << M << " Mana potions\n";
    cout << P << " Perfect potions\n";
    cout << E << " Elixers of life\n";
}
void Player::Use_Items()
{
    Show_Items();
    char x;
    cout << "Enter H M P or E to use potion.\n";
    cin >> x;
    while (x != 'H' && x != 'M' && x != 'P' && x != 'E')
    {
        cout << "Enter H M P or E to use potion.\n";
        cin >> x;
    }
    for (int i = 0; i < 10; i++)
    {
        if (x == 'M' && Potions[i] == 'M')
        {
            if (Current_Mana == Max_Mana)
            {
                cout << "You have Max Mana\n";
                break;
            }
            Current_Mana = Current_Mana + Max_Mana * Value[i] / 100;
            if (Current_Mana > Max_Mana)
                Current_Mana = Max_Mana;
            cout << "Your Mana is restored\n";
        }
        else if (x == 'H' && Potions[i] == 'H')
        {
            if (Current_HP == Max_HP)
            {
                cout << "You have Max HP\n";
                break;
            }
            Current_HP = Current_HP + Max_HP * Value[i] / 100;
            if (Current_HP > Max_HP)
                Current_HP = Max_HP;
        }
        else if ((x == 'P' || x == 'E') && Potions[i] == 'P')
        {
            if (Current_Mana == Max_Mana && Current_HP == Max_HP)
            {
                cout << "You have Full Mana and HP\n";
                break;
            }
            Current_HP = Current_HP + Max_HP * Value[i] / 100;
            if (Current_HP > Max_HP)
                Current_HP = Max_HP;
            Current_Mana = Current_Mana + Max_Mana * Value[i] / 100;
            if (Current_Mana > Max_Mana)
                Current_Mana = Max_Mana;
        }
    }
}