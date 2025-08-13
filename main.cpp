#include <iostream>
#include "creatures/Knight.h"
#include "Hero.h"
int main()
{

    Hero *hero1 = new Hero("Arthur");
    Creature *knight1 = new Knight(100, 20);
    Creature *knight2 = new Knight(120, 25);

    hero1->addCreature(knight1);
    hero1->addCreature(knight2);

    hero1->attackAll(); // Calls Knight::attack() for both, even though type is Creature*
    delete hero1;       // This will also delete knight1 and knight2 due to Hero's destructor
}
