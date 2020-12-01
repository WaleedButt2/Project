#include "../Header/Enemies.h"
#include "../Header/Player.h"
#include <random>
int randint(int Min, int Max)
{
    return rand() % (Max + 1 - Min) + Min;
}
Player battle(Player x)
{
    srand((unsigned)time(0));
    spell ab;
    Enemies a;
    int expected_level;
    int turn;
    int random = 999;
    x.level = 7;
    if (x.level < 5)
        expected_level = x.level;
    else
    {
        while (!a.search_level(random))
            random = randint(x.level - 3, x.level + 3);
        expected_level = random;
    }
    int i;
    x.Elements[0][3].avaliablility = true;
    x.Elements[2][3].avaliablility = true;
    for (i = 0; i < 27; i++)
        if (expected_level == a.enemies[i].level)
            break;
    Enemy Monster = a.enemies[i];
    cout << Monster.race << endl;
    turn = Monster.turn_rate;
    while (x.Current_HP != 0 && Monster.Current_HP != 0)
    {
        if (Monster.Name == "\0")
        {
            //cout<<Current_HP;
            cout << "Player " << x.Current_HP << "/" << x.Max_HP << endl;
            cout << "Monster " << Monster.Current_HP << "/" << Monster.Max_HP << endl;
            if (--turn == 0)
            {
                cout << Monster.race << " attacked you \n";
                x.Current_HP = x.Current_HP - ((1 - x.Defense / 100) * Monster.Base_Attack);
                turn = Monster.turn_rate;
            }
            else
            {
                cout << Monster.race << " will attack in " << turn << " turns" << endl;
            }
            //           cout<<Current_HP;
            //cout<<"Player "<<Max_HP<<"/"<<Current_HP<<endl;
            Monster.Take_Damage(x.Use_spell());
            //cout<<"Monster "<<Monster.Max_HP<<"/"<<Monster.Current_HP<<endl;
            Monster.Tock();
            x.Tick();
        }
        else
        {
            cout << Monster.Name << endl;
            cout << "Monster " << Monster.Current_HP << "/" << Monster.Max_HP << endl;
            cout << "Player " << x.Current_HP << "/" << x.Max_HP << endl
                 << endl;
            if (--turn == 0)
            {
                cout << Monster.Name << " attacked you \n";
                ab = Monster.Boss_Attack();
                if (ab.Tag != -1)
                    x.Take_Damage(ab);
                else
                {
                    x.Current_HP = x.Current_HP - ((1 - x.Defense / 100) * Monster.Base_Attack);
                }
                turn = Monster.turn_rate;
            }
            else
            {
                cout << Monster.Name << " will attack in " << turn << " turns" << endl;
            }
            Monster.Take_Damage(x.Use_spell());
            Monster.Tock();
            x.Tick();
        }
    }
    if (x.Current_HP == 0)
        cout << "You Lose " << endl;
    else
        cout << "You win" << endl;
    return x;
}
void Story()
{
    
}