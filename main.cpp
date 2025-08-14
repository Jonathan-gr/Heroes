#include <iostream>
#include "creatures/Knight.h"
#include "creatures/Priest.h"
#include "Hero.h"
int main()
{

    Hero *hero1 = new Hero("Arthur");
    Creature *knight1 = new Knight();
    Creature *knight2 = new Knight();
    Creature *priest1 = new Priest();
    hero1->addCreature(knight1);
    hero1->addCreature(knight2);
    hero1->addCreature(priest1);
    for (int i = 0; i < hero1->getTypeCount(); ++i)
    {
        if (hero1->getCreatureArr()[i].creature->getName() == "Priest")
        {
            hero1->getCreatureArr()[i].creature->heal(); // Call the heal method on Priest
        }
        else if (hero1->getCreatureArr()[i].creature->getName() == "Knight")
        {
            Knight *knight = dynamic_cast<Knight *>(hero1->getCreatureArr()[i].creature);
            if (knight)
            {
                knight->attack(); // Call the attack method on Knight
            }
        }
    }
    std::cout << hero1->getName() << " is ready for battle!" << std::endl;
    std::cout << "dcdcdc" << std::endl;

    hero1->attackAll(); // Calls Knight::attack() for both, even though type is Creature*
    delete hero1;       // This will also delete knight1 and knight2 due to Hero's destructor
}
