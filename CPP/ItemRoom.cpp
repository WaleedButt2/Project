#include "../Header/ItemRoom.h"
int randin(int Min, int Max)
{
    return rand() % (Max + 1 - Min) + Min;
}
ItemRoom::ItemRoom(int count,int x){
    count=x+count;
    Room_No=count;
    srand((unsigned)time(0));
    int rum=randin(0,8);
    if(rum%2==0) item="10H";
    else if(rum%3==0)  item="10M";
    else if(rum==1||rum==5)  item="20P";
    else if(rum==7)  item="99P";
}
ItemRoom::ItemRoom(){
    
}
