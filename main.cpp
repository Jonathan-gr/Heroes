#include <iostream>
#include "creatures/Creature.h"

int main()
{
    Creature c1(100, 20);
    c1.printStats();

    std::cout << "Hello, Heroes!" << std::endl;
    return 0;
}
