#pragma once
#include <iostream>

class Creature
{
protected:
    std::string name; // Added to store the name of the creature
    int health;
    int attackPower;

public:
    Creature(const std::string &creatureName, int h, int a);
    virtual void attack() = 0;   // pure virtual function → makes Creature abstract
    virtual ~Creature();         // virtual destructor
    std::string getName() const; // get the creature's name
};
