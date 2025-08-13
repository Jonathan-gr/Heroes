#pragma once
#include <iostream>

class Creature
{
protected:
    int health;
    int attackPower;

public:
    Creature(int h, int a);
    virtual void attack() = 0; // pure virtual function → makes Creature abstract
    virtual ~Creature();       // virtual destructor
};
