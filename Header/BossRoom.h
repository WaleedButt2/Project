#include "Room.h"
#include "Enemy.h"
class BossRoom: public Room{
    Enemy Boss;
    int ID=4;
public:
void set_Boss(Enemy Boss,int count);
};