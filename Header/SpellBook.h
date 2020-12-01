#pragma once
#include "spell.h"
class SpellBook
{
protected:
    spell Elements[6][10];

public:
    SpellBook();
    void show_learned_spells();
    void learn_spell(int x);
    void show_learnable_spells(int x);
    spell search_spell(int s);
};