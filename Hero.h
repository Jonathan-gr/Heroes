

#pragma once
#include "creatures/Creature.h"

class Hero
{
private:
    std::string name;
    Creature *Creatures[5];
    int count;

public:
    Hero(const std::string &heroName);
    ~Hero();
    bool addCreature(Creature *c); // add a creature to the hero
    void attackAll();              // call attack() on all creatures
    std::string getName() const;
};