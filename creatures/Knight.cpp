#include "Knight.h"
#include <iostream>

Knight::Knight(int h, int a) : Creature(h, a) {}

void Knight::attack()
{
    std::cout << "Knight attacks with power: " << attackPower << std::endl;
}

Knight::~Knight()
{
    std::cout << "Knight destroyed." << std::endl;
}
