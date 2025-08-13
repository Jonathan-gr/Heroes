#include "Creature.h"
#include <iostream>

Creature::Creature(const std::string &creatureName, int h, int a)
    : name(creatureName), health(h), attackPower(a) {}

Creature::~Creature() {}

std::string Creature::getName() const
{
    return name;
}
