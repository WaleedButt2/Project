#pragma once
#include "Enemies.h"
#include "Room.h"
using namespace std;
class MonsterRoom : public Room{
    Enemy Monster;
    int ID=2;
public:
MonsterRoom(Enemy* Avaliable_Enemies,int Size,int count);
MonsterRoom();
friend class Dungeon_Floor;
};
