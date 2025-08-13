#include "Hero.h"
#include <iostream>

Hero::Hero(const std::string &heroName) : name(heroName), count(0)
{
    for (int i = 0; i < 5; ++i)
    {
        Creatures[i] = nullptr;
    }
}
Hero::~Hero()
{
    for (int i = 0; i < count; ++i)
    {
        delete Creatures[i];
    }
    std::cout << name << " destroyed." << std::endl;
}
bool Hero::addCreature(Creature *c)
{
    if (count < 5 && c != nullptr)
    {
        Creatures[count] = c;
        count++;
        std::cout << "Creature added. Total count: " << count << std::endl;
        return true;
    }
    return false;
}
void Hero::attackAll()
{
    if (count == 0)
    {
        std::cout << name << " has No creatures to attack with." << std::endl;
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        std::cout << name << "'s " << Creatures[i]->getName() << " is attacking!" << std::endl;
        if (Creatures[i] != nullptr)
        {
            Creatures[i]->attack();
        }
    }
}
std::string Hero::getName() const
{
    return name;
}