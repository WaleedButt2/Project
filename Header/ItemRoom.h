#pragma once
#include "Room.h"
#include <string.h>
#include <string>
using namespace std;
class ItemRoom : public Room{
    int ID=1;
    string item;         
public:
ItemRoom(int count,int x);
ItemRoom();
};
