#pragma once
#include <string>
#include <iostream>
#include "creatures/Creature.h"

const int MAX_CREATURE_TYPES = 3;

struct CreatureSlot
{
    Creature *creature; // pointer to a single creature (the type)
    int count;          // number of this type
};

class Hero
{
private:
    std::string name;
    CreatureSlot creatureArr[MAX_CREATURE_TYPES];
    int typeCount; // how many different types of creatures

public:
    Hero(const std::string &heroName);
    ~Hero();

    bool addCreature(Creature *c); // add a creature to the hero
    void attackAll();              // call attack() on all creatures
    std::string getName() const;
    int getTypeCount() const { return typeCount; }         // get the number of different creature types
    CreatureSlot *getCreatureArr() { return creatureArr; } // get the array of creatures
};
