#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>
#include "../Header/Dungeon_Floor.h"
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
    Monster_Rooms = new MonsterRoom[randMonster]; //(MonsterRoom *)malloc(sizeof(MonsterRoom) * randMonster);
    int randSpell = randint(0, 6);
    Blessing_Rooms = new BlessingRoom[randSpell]; //(BlessingRoom *)malloc(sizeof(BlessingRoom) * randSpell);
    int randItem = randint(2, 8);
    count = 0;
    //cout << randMonster + randSpell + randItem << endl;
    Item_Rooms = new ItemRoom[randItem]; //(ItemRoom *)malloc(sizeof(ItemRoom) * randItem);
    Entrance.set_EntranceRoom(0);
    No_of_ItemRooms = randItem;
    No_of_MonsterRooms = randMonster;
    No_of_SpellRooms = randSpell;
    for (int i = 0; i < randMonster; i++)
        Monster_Rooms[i] = MonsterRoom(Avaliable_enemies, Size, i + 1);
    for (int i = 0; i < randItem; i++)
        Item_Rooms[i] = ItemRoom(i + 1, randMonster);
    for (int i = 0; i < randSpell; i++)
        Blessing_Rooms[i] = BlessingRoom(Avaliable_Spells, i, randItem + randMonster + 1);
    FinalRoom.set_Boss(Boss, randItem + randMonster + 1 + randSpell);
    //cout<<FinalRoom.Room_No<<" "<<Blessing_Rooms[randSpell-1].Room_No<<endl;
    //for(int i=0;i<randMonster;i++) cout<<Monster_Rooms[i].Monster.race<<endl;
    //sleep(1);
    return uwu;
}
void Dungeon_Floor::Dungeon_Floor_Assigning_Blessings(SpellBook a, int Rank)
{
    for (int i = 0; i < 6; i++)
        Avaliable_Spells[i] = a.Elements[i][Rank];
}
void Dungeon_Floor::RoomShuffle(){
    
}