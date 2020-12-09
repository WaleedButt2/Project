#include "../Header/Room.h"
Room::Room()
{
    North = 0;
    South = 0;
    West = 0;
    East = 0;
}
bool Room::Rooms_Exists(int x)
{
    if (x == Room_No)
        return true;
    return false;
}
bool Room::Door_avaliable()
{
    if (North != 0 && South != 0 && West != 0 && East != 0)
        return false;
    return true;
}
Enemy Room::Get_Monster()
{
    cout << "Problem\n";
    Enemy a;
    return a;
}
spell Room::Get_spell()
{
    cout << "Problem\n";
    spell a;
    return a;
}
string Room::Get_Item()
{
    cout << "Problem\n";
    return "A";
}