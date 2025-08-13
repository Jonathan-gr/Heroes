#include <iostream>
#include "creatures/Knight.h"

int main()
{
    Knight *k2 = new Knight(150, 30);
    k2->attack();
    delete k2;

    return 0;
}
