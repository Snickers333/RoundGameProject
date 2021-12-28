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

std::ostream &operator<<(std::ostream &o, const Element &e) {
    switch (e) {
        case water:
            o<<"Water";
            break;
        case earth:
            o<<"Earth";
            break;
        case wind:
            o<<"Wind";
            break;
        case fire:
            o<<"Fire";
            break;
        case ice:
            o<<"Ice";
            break;
        case steel:
            o<<"Steel";
            break;
    }
    return o;
}

const std::string &Creature::getName() const {
    return name;
}

void Creature::setName(const std::string &name) {
    Creature::name = name;
}

int Creature::getStrength() const {
    return strength;
}

void Creature::setStrength(int strength) {
    Creature::strength = strength;
}

double Creature::getAgility() const {
    return agility;
}

void Creature::setAgility(double agility) {
    Creature::agility = agility;
}

int Creature::getHp() const {
    return HP;
}

void Creature::setHp(int hp) {
    HP = hp;
}

const SpecialMove &Creature::getSpecialMove() const {
    return specialMove;
}

void Creature::setSpecialMove(const SpecialMove &specialMove) {
    Creature::specialMove = specialMove;
}

int Creature::getExp() const {
    return EXP;
}

void Creature::setExp(int exp) {
    EXP = exp;
}

Element Creature::getElement() const {
    return element;
}

void Creature::setElement(Element element) {
    Creature::element = element;
}
