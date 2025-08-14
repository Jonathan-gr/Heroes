#include "Hero.h"
#include <iostream>

Hero::Hero(const std::string &heroName) : name(heroName), typeCount(0)
{
    for (int i = 0; i < MAX_CREATURE_TYPES; ++i)
    {
        creatureArr[i].creature = nullptr;
        creatureArr[i].count = 0;
    }
}
Hero::~Hero()
{
    for (int i = 0; i < typeCount; ++i)
    {
        std::cout << "Deleting creature of type: " << creatureArr[i].creature->getName() << std::endl;
        delete creatureArr[i].creature;
    }
    std::cout << name << " destroyed." << std::endl;
}
bool Hero::addCreature(Creature *c)
{
    if (typeCount >= MAX_CREATURE_TYPES)
    {
        std::cout << "Cannot add more creatures. Max limit reached." << std::endl;
        return false;
    }

    for (int i = 0; i < typeCount; ++i)
    {
        if (creatureArr[i].creature->getName() == c->getName())
        {
            creatureArr[i].count++;
            std::cout << "Added another " << c->getName() << ". Total count: " << creatureArr[i].count << std::endl;
            return true;
        }
    }

    // If we reach here, it means it's a new type of creature
    creatureArr[typeCount].creature = c;
    creatureArr[typeCount].count = 1;
    typeCount++;
    std::cout << "Added new creature: " << c->getName() << ". Total types: " << typeCount << std::endl;
    return true;
}
void Hero::attackAll()
{
    for (int i = 0; i < typeCount; ++i)
    {
        std::cout << "Attacking with " << creatureArr[i].creature->getName() << " (Count: " << creatureArr[i].count << ")" << std::endl;
        for (int j = 0; j < creatureArr[i].count; ++j)
        {
            creatureArr[i].creature->attack();
        }
    }
}
std::string Hero::getName() const
{
    return name;
}