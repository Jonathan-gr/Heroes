#include "Hero.h"

Hero::Hero(const std::string &heroName)
    : name(heroName), typeCount(0), goldCoins(100)
{
    // Arrays already initialized above with {0} and {nullptr}
}

Hero::~Hero()
{
    for (int i = 0; i < MAX_CREATURE_TYPES; ++i)
    {
        delete creatures[i];
    }
    std::cout << "Hero '" << name << "' destroyed.\n";
}

bool Hero::addCreature(Creature *c)
{
    if (c == nullptr)
        return false;
    int typeIndex = -1;
    if (c->getName() == "Knight")
        typeIndex = 0; // Knight
    else if (c->getName() == "Priest")
        typeIndex = 1; // Priest
    else if (c->getName() == "Dragon")
        typeIndex = 2; // Dragon

    if (typeIndex < 0)
    {
        std::cerr << "Invalid creature type: " << c->getName() << std::endl;
        return false;
    }
    std::cout << "Adding creature of type: " << c->getName() << std::endl;
    if (creatures[typeIndex] == nullptr)
    {
        creatures[typeIndex] = c;
        typeCount++;
    }
    creatureCounts[typeIndex]++;
    std::cout << "Added creature at index " << typeIndex
              << ". Total of this type: " << creatureCounts[typeIndex] << "\n";
    return true;
}

void Hero::attackAll()
{
    for (int i = 0; i < MAX_CREATURE_TYPES; ++i)
    {
        if (creatures[i] != nullptr && creatureCounts[i] > 0)
        {
            int totalAttack = creatures[i]->getAttackPower() * creatureCounts[i];

            std::string creatureName = creatures[i]->getName();
            std::string attackName = "attack";
            if (creatureCounts[i] > 1)
            {
                creatureName += "s";
            }
            else
            {
                attackName = "attacks";
            }

            std::cout << name << "'s " << creatureCounts[i] << " " << creatureName
                      << " " << attackName << " with total power: " << totalAttack << "\n";
        }
    }
}
bool Hero::getAllCreatures()
{
    if (typeCount == 0)
    {
        std::cout << "No creatures available.\n";
        return false;
    }
    std::cout << "Hero " << name << " has the following creatures:\n";
    for (int i = 0; i < MAX_CREATURE_TYPES; ++i)
    {
        if (creatures[i] != nullptr)
        {
            std::cout << "- " << creatures[i]->getName() << " (Count: " << creatureCounts[i] << ")\n";
        }
    }
    return true;
}
std::string Hero::getName() const
{
    return name;
}
