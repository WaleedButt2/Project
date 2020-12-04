#include "../Header/MonsterRoom.h"
int randi(int Min, int Max)
{
    return rand() % (Max + 1 - Min) + Min;
}
MonsterRoom::MonsterRoom(){

}
MonsterRoom::MonsterRoom(Enemy* Avaliable_Enemies,int Size,int count){
    Room_No=count;
    Monster=Avaliable_Enemies[randi(0,Size-1)];
}