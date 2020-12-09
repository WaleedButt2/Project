#include "../Header/ItemRoom.h"
#include "../Header/MonsterRoom.h"
#include "../Header/BlessingRoom.h"
int randi(int Min, int Max)
{
    return rand() % (Max + 1 - Min) + Min;
}
MonsterRoom::MonsterRoom()
{
}
MonsterRoom::MonsterRoom(Enemy *Avaliable_Enemies, int Size, int count)
{
    Room_No = count;
    ID = 2;
    Monster = Avaliable_Enemies[rand() % Size];
    //cout<<Monster.race;
}
Enemy MonsterRoom::Get_Monster()
{
    //cout<<Monster.race;
    return Monster;
}