//
// Created by bkkami on 28.12.2021.
//

#ifndef ROUNDGAMEPROJECT_CREATURE_H
#define ROUNDGAMEPROJECT_CREATURE_H
#include <iostream>
#include "SpecialMove.h"

enum Element {
    water,
    earth,
    wind,
    fire,
    ice,
    steel
};

class Creature {
private:
    std::string name;
    int strength;
    double agility;
    int HP;
    SpecialMove specialMove;
    int EXP;
    Element element;
public:
    Creature(std::string name, int strength, double agility, int HP, Special special, Element element);
    void Attack(Creature enemy);
};
#endif //ROUNDGAMEPROJECT_CREATURE_H
