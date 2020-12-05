#pragma once
#include <iostream>
class Room{
protected:
    int North;
    int South;
    int West;
    int East;
    int Room_No;
    bool Finished;
public:
Room();
friend class Dungeon_Floor;
};
