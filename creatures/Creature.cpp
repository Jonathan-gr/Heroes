#include "Creature.h"
#include <iostream>

Creature::Creature(int h, int a) : health(h), attackPower(a) {}

void Creature::printStats()
{
    std::cout << "Creature stats - Health: " << health
              << ", Attack: " << attackPower << std::endl;
}
