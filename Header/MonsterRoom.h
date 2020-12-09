#pragma once
#include "Enemies.h"
#include "Room.h"
using namespace std;
class MonsterRoom : public Room
{
    Enemy Monster;

public:
    MonsterRoom(Enemy *Avaliable_Enemies, int Size, int count);
    MonsterRoom();
    friend class Dungeon_Floor;
    Enemy Get_Monster();
};
