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
    int agility;
    int HP;
    SpecialMove specialMove;
    int EXP;
    Element element;
    bool cooldown;
public:
    Creature(std::string name, int strength, int agility, int HP, Special special, Element element);
    bool attack(Creature &enemy, int fixed);
    int specialAttack(Creature &enemy);
    const std::string &getName() const;
    void setName(const std::string &name);
    int getStrength() const;
    void setStrength(int strength);
    double getAgility() const;
    void setAgility(double agility);
    int getHp() const;
    void setHp(int hp);
    SpecialMove getSpecialMove() const;
    void setSpecialMove(const SpecialMove &specialMove);
    int getExp() const;
    void setExp(int exp);
    Element getElement() const;
    void setElement(Element element);
    bool isCooldown() const;
    void setCooldown(bool cooldown);
    friend std::ostream& operator <<(std::ostream& o, const Creature& c);
    friend std::ostream& operator <<(std::ostream& o, const Element& c);
    static int conflictModifier(const Creature *ally, const Creature& enemy) ;
    static void showCurrentChosen(Creature *pCreature, Creature *pCreature1);
    void checkLevelUp();
    bool alive();
    static Element getElementIndex(std::string element);
};
#endif //ROUNDGAMEPROJECT_CREATURE_H
