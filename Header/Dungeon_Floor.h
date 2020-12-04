#include "Enemies.h"
#include "MonsterRoom.h"
#include "ItemRoom.h"
#include "BlessingRoom.h"
#include "SpellBook.h"
#include "BossRoom.h"
#include "EntranceRoom.h"
#pragma once
class Dungeon_Floor{
public:
int Max_level;
int No_of_MonsterRooms;
int No_of_ItemRooms;
int No_of_SpellRooms;
Enemy *Avaliable_enemies;
ItemRoom *Item_Rooms;
MonsterRoom *Monster_Rooms;
int Size;
BossRoom FinalRoom;
EntranceRoom Entrance;
BlessingRoom *Blessing_Rooms;
spell Avaliable_Spells[6];
Enemy Boss;
int Dungeon_Floor_Assiging_enemies(Enemies a,int i,int Max_level,int count);
int Dungeon_Room_Creator(Enemies a,int i,int Max_level,int count,SpellBook b,int x);
void Dungeon_Floor_Assigning_Blessings(SpellBook a,int Rank);
void RoomShuffle();
};