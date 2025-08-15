#pragma once
#include <string>
#include <iostream>
#include "creatures/Creature.h"

const int MAX_CREATURE_TYPES = 3; // 0 = Knight, 1 = Priest, 2 = Dragon

class Hero
{
private:
    int goldCoins;
    std::string name;
    int creatureCounts[MAX_CREATURE_TYPES] = {0};        // counts for each type
    Creature *creatures[MAX_CREATURE_TYPES] = {nullptr}; // one slot per type
    int typeCount;                                       // how many types are currently used

public:
    Hero(const std::string &heroName);
    ~Hero();

    bool addCreature(Creature *c); // add creature to specific index
    void attackAll();
    std::string getName() const;
    int getTypeCount() const { return typeCount; }
    void addGold(int amount) { goldCoins += amount; }
    int getGold() const { return goldCoins; }
    void setGold(int amount) { goldCoins = amount; }
    bool getAllCreatures();
};
