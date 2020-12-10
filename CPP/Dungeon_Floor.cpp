#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>
#include "../Header/Dungeon_Floor.h"
#include "FileHandleZaWardo.cpp"
#include <iostream>
Dungeon_Floor::Dungeon_Floor() {}
int randint(int Min, int Max)
{
    return rand() % (Max + 1 - Min) + Min;
}
int Dungeon_Floor::Dungeon_Floor_Assiging_enemies(Enemies a, int i, int Max_level, int count)
{
    int z = i;
    while (a.enemies[i++].level < Max_level)
    {
        count++;
        this->Max_level = a.enemies[i].level;
    }
    Avaliable_enemies = new Enemy[count];
    // cout<<Avaliable_enemies[0].race<<endl;
    Size = count;
    for (int x = 0; x < count; x++)
        Avaliable_enemies[x] = a.enemies[z++];
    Boss = a.enemies[i - 1];
    return i;
}
int Dungeon_Floor::Dungeon_Room_Creator(Enemies a, int uwu, int Max_level, int count, SpellBook b, int x)
{
    uwu = Dungeon_Floor_Assiging_enemies(a, uwu, Max_level, count);
    Dungeon_Floor_Assigning_Blessings(b, x);
    int randMonster = randint(10, 40);
    int randSpell = randint(0, 6);
    int randItem = randint(2, 8);
    total_Room = randMonster + randSpell + randItem;
    Rooms = new Room *[total_Room];
    count = 0;
    Rooms[0] = new EntranceRoom;
    Rooms[0]->Room_No = 1;
    *Rooms[0] = Entrance;
    int check = rand() % 3;
    if (Avaliable_Spells[0].Name == "CandleFlame")
    {
        Avaliable_Spells[0].Taken = true;
    }
    int i = 1;
    while (i < total_Room)
    {
        if (i == total_Room - 1)
        {
            Rooms[i] = new BossRoom(Boss, i + 1);
            break;
        }
        if (check == 0 && No_of_MonsterRooms < randMonster)
        {
            Rooms[i] = new MonsterRoom(Avaliable_enemies, Size, i + 1);
            No_of_MonsterRooms++;
            i++;
            Rooms[i - 1]->Get_Monster();
        }
        else if (check == 1 && No_of_ItemRooms < randItem)
        {
            Rooms[i] = new ItemRoom(i + 1);
            No_of_ItemRooms++;
            i++;
        }
        else if (check == 2 && No_of_SpellRooms < randSpell)
        {
            Rooms[i] = new BlessingRoom(Avaliable_Spells, i + 1);
            No_of_SpellRooms++;
            i++;
        }
        check = rand() % 3;
    }
    //cout<<Rooms[0]->Room_No<<endl;
    RoomShuffle();
    //cout<<Rooms[total_Room-1]->Get_Monster().race<<endl;
    //cout<<total_Room<<endl;
    // for(int i=0;i<total_Room;i++)
    //if(Rooms[i]->ID==2)     { cout<<Rooms[i]->Room_No<<' '<<Rooms[i]->Get_Monster().race<<endl;}
    //print();
    return uwu;
}
Player Dungeon_Floor::Traverse_Rooms(Player x)
{
    Room *Current_Room;
    string line;
    int i = 0;
    Current_Room = Rooms[0];
    string Item;
    Enemy Monster;
    spell Blessing;
    int Path_to_tread;
    Avaliable_Spells[0].Taken = true;
    x.learn_spell(Avaliable_Spells[0].Tag);
    sleep(1);
    while (true)
    {
        if (Current_Room->ID == 0)
        {
            cout << "ENTRANCE ROOM\n";
            x.Current_HP = x.Max_HP;
            x.Current_Mana = x.Max_Mana;
            Path_to_tread = Paths(Current_Room);
            Current_Room = Return_Room(Path_to_tread);
        }
        else if (Current_Room->ID == 1)
        { //item room
            cout << "ITEM ROOM\n";
            if (Current_Room->called == true)
                cout << "The Room is empty\n";
            else
            {
                Item = Current_Room->Get_Item();
                x.Set_Item(Item);
                Rooms[Current_Room->Room_No - 1]->called = true;
            }
            if(x.Current_HP!=x.Max_HP&&x.Empty==false){
            cout<<"Would you like to use an item?\nCurrent HP "<<x.Current_HP<<"/"<<x.Max_HP<<"\nYes or No\n";cin>>Item;
            if(Item=="Yes"||Item=="yes"||Item=="YES")     x.Use_Items();}
            Path_to_tread = Paths(Current_Room);
            Current_Room = Return_Room(Path_to_tread);
        }
        else if (Current_Room->ID == 2)
        {
            if (Current_Room->called == true)
                cout << "The Room is empty\n";
            else
            {
                Monster = Current_Room->Get_Monster();
                x = Battle(x, Monster);
                if(x.Current_HP==0) return x;
                Rooms[Current_Room->Room_No - 1]->called = true;
            }
            if(x.Current_HP!=x.Max_HP&&x.Empty==false){
            cout<<"Would you like to use an item?\nCurrent HP "<<x.Current_HP<<"/"<<x.Max_HP<<"\nYes or No\n";cin>>Item;
            if(Item=="Yes"||Item=="yes"||Item=="YES")     x.Use_Items();}            
            Path_to_tread = Paths(Current_Room);
            Current_Room = Return_Room(Path_to_tread);
        }
        else if (Current_Room->ID == 3)
        {
            Blessing = Current_Room->Get_spell();
            if (Current_Room->called == true)
            {
                cout << "The Room is empty\n";
            }
            else
            {
                cout << "You feel it magic rippling through you\nYou grow stronger\nYou have learnt " << Blessing.Name << endl;
                x.learn_spell(Blessing.Tag);
                Rooms[Current_Room->Room_No - 1]->called = true;
            }
            if(x.Current_HP!=x.Max_HP&&x.Empty==false){
            cout<<"Would you like to use an item?\nCurrent HP "<<x.Current_HP<<"/"<<x.Max_HP<<"\nYes or No\n";cin>>Item;
            if(Item=="Yes"||Item=="yes"||Item=="YES")     x.Use_Items();}
            Path_to_tread = Paths(Current_Room);
            Current_Room = Return_Room(Path_to_tread);
        }
        else if (Current_Room->ID == 4)
        {
            cout << "The Final Room\nWelcome\n";
            cout<<"Would You like to chalange "<<Current_Room->Get_Monster().Name<<endl;cin>>line;
            if(line == "Yes" || line == "yes" || line == "YES"){ 
            if (Current_Room->called == true)
                cout << "The Room is empty\n";
            else
            {
                Monster = Current_Room->Get_Monster();
                x = Battle(x, Monster);
                if(x.Current_HP==0) return x;
                Rooms[Current_Room->Room_No - 1]->called = true;
            }
            cout << "Would You like to Asscened Higher?   Yes/No\n";
            cin >> line;
            if (line == "Yes" || line == "yes" || line == "YES")
            {
                return x;
            }
            }
            Path_to_tread = Paths(Current_Room);
            Current_Room = Return_Room(Path_to_tread);
        }
    }
    return x;
}
int Dungeon_Floor::Paths(Room *Current_Room)
{
    char c;
    int a;
    bool x = false;
    while (x != true)
    {
        cout << "Choose 1 of the directions to move in\n";
        cout << "      N      \n"
             << "W           E\n"
             << "      S\n";
        cin >> c;
        if (c == 'N')
        {
            if (Current_Room->North == 0)
            {
                cout << "The Path Forward Is Blocked\n";

                continue;
            }
            a = Current_Room->North;
            x = true;
        }
        else if (c == 'S')
        {
            if (Current_Room->South == 0)
            {
                cout << "The Path Forward Is Blocked\n";
                continue;
            }
            a = Current_Room->South;
            x = true;
        }
        else if (c == 'W')
        {
            if (Current_Room->West == 0)
            {
                cout << "The Path Forward Is Blocked\n";
                continue;
            }
            a = Current_Room->West;
            x = true;
        }
        else if (c == 'E')
        {
            if (Current_Room->East == 0)
            {
                cout << "The Path Forward Is Blocked\n";
                continue;
            }
            a = Current_Room->East;
            x = true;
        }
        else
        {
            cout << "Chose a valid Direction to tread forward to\n North South West East\n Enter N S W E\n";
            continue;
        }
    }
    return a;
}
void Dungeon_Floor::Dungeon_Floor_Assigning_Blessings(SpellBook a, int Rank)
{
    for (int i = 0; i < 6; i++)
        Avaliable_Spells[i] = a.Elements[i][Rank];
}
void Dungeon_Floor::RoomShuffle()
{
    int rund;
    rund = randint(2, total_Room - 1);
    Rooms[0]->Room_No = 1;
    Rooms[0]->North = 2;
    Rooms[1]->South = 1;
    for (int i = 1; i < total_Room; i++)
    {
        if (Rooms[i]->Door_avaliable())
        {
            rund = randint(2, total_Room - 1);
            while (!Rooms[rund]->Door_avaliable())
                rund = randint(2, total_Room - 1);
            if (Rooms[i]->North == 0)
            {
                if (Rooms[rund]->South == 0)
                {
                    Rooms[i]->North = Rooms[rund]->Room_No;
                    Rooms[rund]->South = Rooms[i]->Room_No;
                    rund = randint(2, total_Room - 1);
                    while (!Rooms[rund]->Door_avaliable())
                        rund = randint(2, total_Room - 1);
                }
            }
            if (Rooms[i]->South == 0)
            {
                if (Rooms[rund]->North == 0)
                {
                    Rooms[i]->South = Rooms[rund]->Room_No;
                    Rooms[rund]->North = Rooms[i]->Room_No;
                    rund = randint(2, total_Room - 1);
                    while (!Rooms[rund]->Door_avaliable())
                        rund = randint(2, total_Room - 1);
                }
            }
            if (Rooms[i]->West == 0)
            {
                if (Rooms[rund]->East == 0)
                {
                    Rooms[i]->West = Rooms[rund]->Room_No;
                    Rooms[rund]->East = Rooms[i]->Room_No;
                    rund = randint(2, total_Room - 1);
                    while (!Rooms[rund]->Door_avaliable())
                        rund = randint(2, total_Room - 1);
                }
            }
            if (Rooms[i]->East == 0)
            {
                if (Rooms[rund]->West == 0)
                {
                    Rooms[i]->East = Rooms[rund]->Room_No;
                    Rooms[rund]->West = Rooms[i]->Room_No;
                }
            }
        }
        //RoomConnect();
    }
}
void Dungeon_Floor::print()
{
    for (int i = 0; i < total_Room; i++)
    {
        cout << Rooms[i]->ID << " North = " << Rooms[i]->North << " South = " << Rooms[i]->South << " West = " << Rooms[i]->West << " East = " << Rooms[i]->East << endl;
    }
}
Player Dungeon_Floor::Battle(Player x, Enemy Monster)
{
    spell ab;
    int expected_level;
    int turn;
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
            Monster.Take_Damage(x.Use_spell());
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
    if (x.Current_HP == 0){
        cout << "You Lose " << endl;
        File_za_wardo(Monster,x,true);
    }
    else
    {
        cout << "You win" << endl;
        File_za_wardo(Monster,x,false);
        x.levelup(Monster.level * 20);
    }
    for (int i = 0; i < 10; i++)
    {
        x.DPS_inflicted_with[i].TurnRate = 0;
        x.DPS_inflicted_with[i].DPS = 0;
    }
    return x;
}
Room *Dungeon_Floor::Return_Room(int x)
{
    for (int i = 0; i < total_Room; i++)
    {
        if (Rooms[i]->Room_No == x)
        {
            return Rooms[i];
        }
    }
    return Rooms[0];
}