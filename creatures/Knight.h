#pragma once
#include "Creature.h"

class Knight : public Creature
{

public:
    Knight();
    void attack() override; // override pure virtual function
    ~Knight() override;
};
