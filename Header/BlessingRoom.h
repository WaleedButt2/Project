#pragma once
#include "Room.h"
#include "spell.h"
class BlessingRoom :public Room
{
    spell Blessing;
    int ID=3;

public:
    BlessingRoom(spell *Avaliable_Spells,int counter,int x);
    BlessingRoom();
};