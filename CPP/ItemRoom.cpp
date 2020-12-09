#include "../Header/ItemRoom.h"
#include "../Header/MonsterRoom.h"
#include "../Header/BlessingRoom.h"
ItemRoom::ItemRoom(int count)
{
    ID = 1;
    Room_No = count;
    srand((unsigned)time(0));
    int rum = rand() % 100 + 1;
    if (rum % 2 == 0)
        item = "10H";
    else if (rum % 3 == 0)
        item = "10M";
    else if (rum % 5 == 0)
        item = "20P";
    else if (rum % 23 == 0)
        item = "99P";
    else
        item = "05H";
}
ItemRoom::ItemRoom()
{
}
string ItemRoom::Get_Item()
{
    string x = item;
    return x;
}