#pragma once
#include <iostream>
#include "Enemy.h"
class Room
{
protected:
    int ID;
    int North;
    int South;
    int West;
    int East;
    int Room_No;
    bool called = false;

public:
    Room();
    bool Rooms_Exists(int x);
    bool Door_avaliable();
    virtual Enemy Get_Monster();
    virtual spell Get_spell();
    virtual string Get_Item();
    friend class Dungeon_Floor;
};
