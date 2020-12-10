#include "../Header/Dungeon.h"
#include <random>
void Story()
{
    srand(time(NULL));
    Dungeon Za_Wordo;
    Player Merlin;
    cout << "Welcome To The Begiening Of Your Journey\nStep Forward now. Do not fear\nShow why you were chosen and They were not\n";
    Merlin = Za_Wordo.Dungeon_Floor_1.Traverse_Rooms(Merlin);
    if(Merlin.get_current_hp()==0){cout<<"Little Worm Who died without even knowing there was a sky above the sky.\nFall\n"; exit(0);}
    cout << "Little One you have passed the barest of Challanges but this long road has just begun\n";
    cout << "Keep walking forward\n";
    Merlin=Za_Wordo.Dungeon_Floor_2.Traverse_Rooms(Merlin);
}