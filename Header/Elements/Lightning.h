#pragma once
#include <strings.h>
#include "spell.h"
class Lightning : spell{
    private:
    int base_dps;       //damage per second
    public:
    Lightning();  //constructor for base dps and for reading spells from a file and adding it into array
    //char* get_status_effect();  //returns status like "burn" or "freeze" or "rooted" etc..
};