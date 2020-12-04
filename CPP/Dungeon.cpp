#include "../Header/Dungeon.h"
Dungeon::Dungeon(){
    int i=0;int count=0;
    Enemies a;SpellBook s;
    i=Dungeon_Floor_1.Dungeon_Room_Creator(a,i,5,count,s,0);
    i=Dungeon_Floor_2.Dungeon_Room_Creator(a,i,10,count,s,1);
    i=Dungeon_Floor_3.Dungeon_Room_Creator(a,i,15,count,s,2);
    i=Dungeon_Floor_4.Dungeon_Room_Creator(a,i,20,count,s,3);
    i=Dungeon_Floor_5.Dungeon_Room_Creator(a,i,25,count,s,4);
    i=Dungeon_Floor_6.Dungeon_Room_Creator(a,i,30,count,s,5);
    i=Dungeon_Floor_7.Dungeon_Room_Creator(a,i,35,count,s,6);
    i=Dungeon_Floor_8.Dungeon_Room_Creator(a,i,40,count,s,7);
    i=Dungeon_Floor_9.Dungeon_Room_Creator(a,i,45,count,s,8);
    i=Dungeon_Floor_10.Dungeon_Room_Creator(a,i,50,count,s,9);
}