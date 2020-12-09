#include "../Header/EntranceRoom.h"
#include "../Header/ItemRoom.h"
#include "../Header/MonsterRoom.h"
#include "../Header/BlessingRoom.h"
void EntranceRoom::set_EntranceRoom(int count)
{
    Room_No = count;
    ID = 0;
    North = 1;
}