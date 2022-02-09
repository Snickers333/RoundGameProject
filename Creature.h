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
    // Constructor that sets necessary fields to this object
    Creature(std::string name, int strength, int agility, int HP, Special special, Element element);

    // Method that attacks enemy Creature
    bool attack(Creature &enemy, int fixed);

    // Method that uses special attack of the given creature on the enemy
    int specialAttack(Creature &enemy);

    // Name Getter
    const std::string &getName() const;

    // Strength Getter
    int getStrength() const;

    // Strength Setter
    void setStrength(int i);

    // Agility Getter
    int getAgility() const;

    // Agility Setter
    void setAgility(int agility);

    // HP Getter
    int getHp() const;

    // HP Setter
    void setHp(int hp);

    // SpecialMove Getter
    SpecialMove getSpecialMove() const;

    // Exp amount Getter
    int getExp() const;

    // Exp amount Setter
    void setExp(int exp);

    // Element type Getter
    Element getElement() const;

    // Method that checks if Special Ability is on cooldown
    bool isCooldown() const;

    // Method that sets Special Ability cooldown
    void setCooldown(bool cooldown);

    // Output stream operator overload for Creature
    friend std::ostream &operator<<(std::ostream &o, const Creature &c);

    // Output stream operator overload for Element type
    friend std::ostream &operator<<(std::ostream &o, const Element &c);

    // Method that checks whether two elements are conflicting with each other
    static int conflictModifier(const Creature *ally, const Creature &enemy);

    // Method that outputs currently controlled Creatures
    static void showCurrentChosen(Creature *pCreature, Creature *pCreature1);

    // Method that checks whether Creature should level up and increase stats
    void checkLevelUp();

    // Method that checks if a Creature is alive
    bool alive() const;

    // Method - String conversion to Element Enum
    static Element getElementIndex(const std::string &element);
};

#endif //ROUNDGAMEPROJECT_CREATURE_H
