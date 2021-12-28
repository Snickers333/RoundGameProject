//
// Created by bkkami on 28.12.2021.
//

#include "Creature.h"

#include <utility>

Creature::Creature(std::string name,int strength, double agility, int HP, Special special, Element element) {
    this->name = std::move(name);
    this->strength = strength;
    this->agility = agility;
    this->HP = HP;
    this->specialMove = SpecialMove(special);
    this->EXP = 0;
    this->element = element;
}