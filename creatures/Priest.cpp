#include "Priest.h"
#include <iostream>

Priest::Priest()
    : Creature("Priest", 20, 2) {}

void Priest::attack()
{
    std::cout << name << " is weak and attacks with power: " << attackPower << std::endl;
}

// Priest.cpp
void Priest::heal()
{
    std::cout << name << " heals itself for 5 health points." << std::endl;
    this->health += 5;
    std::cout << name << "'s current health: " << this->health << std::endl;
}

Priest::~Priest()
{
    std::cout << name << " destroyed." << std::endl;
}
