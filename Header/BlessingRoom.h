#pragma once
#include "Room.h"
#include "spell.h"
class BlessingRoom : public Room
{
    spell Blessing;

public:
    BlessingRoom(spell *Avaliable_Spells, int counter);
    BlessingRoom();
    spell Get_spell();
};