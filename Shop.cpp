#include "Shop.h"
#include <iostream>
#include "creatures/Knight.h"
#include "creatures/Priest.h"
#include "creatures/Dragon.h"
#include "Hero.h"
Shop::Shop()
{
    // Constructor implementation if needed
}
#include <limits> // for std::numeric_limits

bool Shop::buyCreature(Hero &hero)
{
    std::cout << "\n=== Creature Shop ===\n";

    std::cout << "you have " << hero.getGold() << " gold coins.\n";
    std::cout << "1. Knight  (15 gold)\n";
    std::cout << "2. Priest  (30 gold)\n";
    std::cout << "3. Dragon (150 gold)\n";
    std::cout << "Choose a creature to buy (1-3): ";

    int choice;
    std::cin >> choice;

    // Validate input
    if (std::cin.fail() || choice < 1 || choice > 3)
    {
        std::cin.clear(); // clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice.\n";
        return false;
    }

    int cost = 0;
    Creature *newCreature = nullptr;

    switch (choice)
    {
    case 1:
        cost = 15;
        newCreature = new Knight();
        break;
    case 2:
        cost = 30;
        newCreature = new Priest();
        break;
    case 3:
        cost = 150;
        newCreature = new Dragon();
        break;
    }

    if (hero.getGold() < cost)
    {
        std::cout << "You don't have enough gold!\n";
        delete newCreature; // avoid leak
        return false;
    }

    if (hero.addCreature(newCreature))
    {
        hero.setGold(hero.getGold() - cost);
        std::cout << "You bought a " << newCreature->getName() << "!\n";
        return true;
    }
    else
    {
        std::cout << "Couldn't add creature (maybe full?).\n";
        delete newCreature;
        return false;
    }
}

Shop::~Shop()
{
    // Destructor implementation if needed
}