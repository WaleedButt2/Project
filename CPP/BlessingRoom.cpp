#include "../Header/BlessingRoom.h"
BlessingRoom::BlessingRoom(spell *Avaliable_Spells, int count)
{
    Room_No = count;
    ID = 3;
    int i = 0;
    for (i = 0; i < 6; i++)
    {
        if (Avaliable_Spells[i].Taken == true)
            continue;
        else
            break;
    }
    Blessing = Avaliable_Spells[i];
    Avaliable_Spells[i].Taken = true;
}
BlessingRoom::BlessingRoom()
{
}
spell BlessingRoom::Get_spell()
{
    return Blessing;
}