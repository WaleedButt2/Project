#pragma once
#include "../Header/Enemy.h"
#include "../Header/Player.h"
class Enemies : public Enemy
{
public:
    Enemy enemies[34];
    Enemies();
    bool search_level(int x);
    friend Player battle(Player x);
};