#pragma once
#include "Room.h"
#include <string.h>
#include <string>
using namespace std;
class ItemRoom : public Room
{
    string item;

public:
    ItemRoom(int count);
    ItemRoom();
    string Get_Item();
};
