#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Dungeon_Floor.h"
#include "Player.h"
using namespace std;
class Dungeon{
    Dungeon_Floor Dungeon_Floor_1;
    Dungeon_Floor Dungeon_Floor_2;
    Dungeon_Floor Dungeon_Floor_3;
    Dungeon_Floor Dungeon_Floor_4;
    Dungeon_Floor Dungeon_Floor_5;
    Dungeon_Floor Dungeon_Floor_6;
    Dungeon_Floor Dungeon_Floor_7;
    Dungeon_Floor Dungeon_Floor_8;
    Dungeon_Floor Dungeon_Floor_9;
    Dungeon_Floor Dungeon_Floor_10;
    Dungeon_Floor Dungeon_Floor_Final_Boss;
    Dungeon_Floor Dungeon_End_game;
public:
Dungeon();
friend void Story();
};