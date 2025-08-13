#pragma once

class Creature
{
protected:
    int health;
    int attackPower;

public:
    Creature(int h, int a);
    void printStats();
};
