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
    void Attack(Creature &enemy);
    const std::string &getName() const;
    void setName(const std::string &name);
    int getStrength() const;
    void setStrength(int strength);
    double getAgility() const;
    void setAgility(double agility);
    int getHp() const;
    void setHp(int hp);
    const SpecialMove &getSpecialMove() const;
    void setSpecialMove(const SpecialMove &specialMove);
    int getExp() const;
    void setExp(int exp);
    Element getElement() const;
    void setElement(Element element);
    friend std::ostream& operator <<(std::ostream& o, const Creature& c);
    friend std::ostream& operator <<(std::ostream& o, const Element& c);
};
#endif //ROUNDGAMEPROJECT_CREATURE_H
