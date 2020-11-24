#pragma once
#include "Elements.h"
class SpellBook{
    private:
    Elements Element;
    public:
    void show_spells_by_rank();
    void search_spell(char* sp);
};