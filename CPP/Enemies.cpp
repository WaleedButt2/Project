#include "../Header/Enemies.h"
#include "../CPP/FileHandlerV2.0.cpp"
Enemies::Enemies()
{
    File_V2(enemies);
}
bool Enemies::search_level(int x){
    for(int i =0;i<29;i++){
        if(enemies[i].level==x)  return true;
    }
    return false;
}