#pragma once
#include <iostream>
class Room{
protected:
    int North;
    int South;
    int West;
    int East;
    int Room_No;
public:
Room();
friend class Dungeon_Floor;
};
