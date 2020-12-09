#include "../Header/BossRoom.h"
BossRoom::BossRoom(Enemy Boss, int count)
{
    Room_No = count;
    this->Boss = Boss;
    ID = 4;
}
Enemy BossRoom::Get_Monster()
{
    return Boss;
}
BossRoom::BossRoom()
{
}