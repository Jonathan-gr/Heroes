#include "Knight.h"
#include <iostream>

// Automatically sets the name to "Knight"
Knight::Knight(int h, int a)
    : Creature("Knight", h, a) {}

void Knight::attack()
{
    std::cout << name << " attacks with power: " << attackPower << std::endl;
}

Knight::~Knight()
{
    std::cout << name << " destroyed." << std::endl;
}
