#include "../Header/BlessingRoom.h"
BlessingRoom::BlessingRoom(spell *Avaliable_Spells,int count,int x){
    count=x+count;
    Room_No=count;
    int i =0;
    for(i =0;i<6;i++) 
    if(Avaliable_Spells[i].Tag==-1)  
    continue;
    else
    break;
    Blessing = Avaliable_Spells[i];
    Avaliable_Spells[i].Tag=-1;
}
BlessingRoom::BlessingRoom(){

}