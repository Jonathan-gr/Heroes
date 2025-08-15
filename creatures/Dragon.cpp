#include "Dragon.h"
#include <iostream>

Dragon::Dragon()
    : Creature("Dragon", 5, 35) {}

void Dragon::attack()
{
    std::cout << name << " attacks with power: " << attackPower << std::endl;
}

Dragon::~Dragon()
{
    std::cout << name << " destroyed." << std::endl;
}
