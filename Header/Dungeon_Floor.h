#include "Enemies.h"
#include "MonsterRoom.h"
#include "ItemRoom.h"
#include "BlessingRoom.h"
#include "SpellBook.h"
#include "BossRoom.h"
#include "Player.h"
#include "EntranceRoom.h"
#pragma once
class Dungeon_Floor{
public:
int Max_level;
int No_of_MonsterRooms=0;
int No_of_ItemRooms=0;
int No_of_SpellRooms=0;
Enemy *Avaliable_enemies;
int Size;
int total_Room;
Room** Rooms;
BossRoom FinalRoom;
EntranceRoom Entrance;
spell Avaliable_Spells[6];
Enemy Boss;
Dungeon_Floor();
Player Traverse_Rooms(Player x);
int Dungeon_Floor_Assiging_enemies(Enemies a,int i,int Max_level,int count);
int Dungeon_Room_Creator(Enemies a,int i,int Max_level,int count,SpellBook b,int x);
void Dungeon_Floor_Assigning_Blessings(SpellBook a,int Rank);
void RoomShuffle();
void print();
int Paths(Room* Current_Room);
Player Battle(Player x,Enemy Monster);
Room* Return_Room(int x);
};