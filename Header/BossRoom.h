#include "Room.h"
#include "Enemy.h"
class BossRoom : public Room
{
    Enemy Boss;

public:
    Enemy Get_Monster();
    BossRoom(Enemy Boss, int count);
    BossRoom();
};