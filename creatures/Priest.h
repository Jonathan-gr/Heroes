#pragma once
#include "Creature.h"

class Priest : public Creature
{

public:
    Priest();
    void attack() override; // override pure virtual function
    void heal() override;   // new method for healing
    ~Priest() override;
};