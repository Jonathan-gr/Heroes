#pragma once
#include "Creature.h"

class Knight : public Creature
{

public:
    Knight(int h, int a);
    void attack() override; // override pure virtual function
    ~Knight() override;
};
