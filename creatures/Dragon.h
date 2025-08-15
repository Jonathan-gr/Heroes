#pragma once
#include "Creature.h"

class Dragon : public Creature
{

public:
    Dragon();
    void attack() override; // override pure virtual function
    ~Dragon() override;
};
