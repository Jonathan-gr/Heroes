#include <iostream>
#include <vector>
#include <string>
#include "Hero.h"
#include "Shop.h"

// Example main loop
int main()
{
    std::vector<Hero *> heroes;
    Shop shop;
    int gold = 200; // start gold for simplicity

    while (true)
    {
        std::cout << "\n=== Main Menu ===\n";
        std::cout << "1. Add new hero\n";
        std::cout << "2. Buy creature for hero\n";
        std::cout << "3. List heroes\n";
        std::cout << "4. Attack with all\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::string heroName;
            std::cout << "Enter hero name: ";
            std::cin >> heroName;
            heroes.push_back(new Hero(heroName));
            std::cout << "Hero '" << heroName << "' created!\n";
        }
        else if (choice == 2)
        {
            if (heroes.empty())
            {
                std::cout << "No heroes available! Create one first.\n";
                continue;
            }

            std::cout << "Select a hero:\n";
            for (size_t i = 0; i < heroes.size(); ++i)
            {
                std::cout << i + 1 << ". " << heroes[i]->getName() << "\n";
            }
            int heroChoice;
            std::cin >> heroChoice;

            if (heroChoice < 1 || heroChoice > (int)heroes.size())
            {
                std::cout << "Invalid hero selection.\n";
                continue;
            }

            shop.buyCreature(*heroes[heroChoice - 1]);
        }
        else if (choice == 3)
        {
            std::cout << "\n--- Heroes ---\n";
            for (auto hero : heroes)
            {
                hero->getAllCreatures();
            }
        }
        else if (choice == 4)
        {
            if (heroes.empty())
            {
                std::cout << "No heroes available! Create one first.\n";
                continue;
            }

            std::cout << "Select a hero:\n";
            for (size_t i = 0; i < heroes.size(); ++i)
            {
                std::cout << i + 1 << ". " << heroes[i]->getName() << "\n";
            }
            int heroChoice;
            std::cin >> heroChoice;

            if (heroChoice < 1 || heroChoice > (int)heroes.size())
            {
                std::cout << "Invalid hero selection.\n";
                continue;
            }

            heroes[heroChoice - 1]->attackAll();
        }

        else if (choice == 5)
        {
            std::cout << "Exiting game.\n";
            break;
        }
    }

    // Cleanup
    for (auto hero : heroes)
    {
        delete hero;
    }

    return 0;
}
