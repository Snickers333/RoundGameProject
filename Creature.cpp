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
    this->EXP = 1;
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

std::ostream &operator<<(std::ostream &o, const Creature &c) {
    o<<" "<<c.getName()<<"\t"<<c.getStrength()<<"\t"<<c.getAgility()<<"\t"<<c.getHp()<<"\t"<<c.getElement()<<"\t\t"<<c.getSpecialMove()<<std::endl;
    return o;
}

void Creature::attack(Creature &enemy) {
    int modifier = conflict(this, enemy);
    if ((modifier + this->getStrength()) < 0) {
        std::cout<<std::endl<<"Your damage to this entity was to low to deal any damage"<<std::endl<<std::endl;
        return;
    }
    enemy.setHp(enemy.getHp()-(this->getStrength()+modifier));
    std::cout<<std::endl<<"You have dealt "<<(this->getStrength()+modifier)<<" damage to your enemy"<<std::endl<<std::endl;
    if (enemy.getHp() <= 0) {
        this->setExp(this->getExp()+1);
    }
    if (this->getExp() % 3 == 0) {
        this->setExp(this->getExp()+1);
        this->setHp(this->getHp()+3);
        this->setStrength(this->getStrength()+2);
        //TODO AGILITY LEVEL UP
    }
}

int Creature::conflict(const Creature *ally, const Creature &enemy) const {
    switch (ally->getElement()) {
        case water:
            switch (enemy.getElement()) {
                case earth:
                    return 2;
                case water:
                    return -2;
                case fire:
                    return 2;
            }
            break;
        case earth:
            switch (enemy.getElement()) {
                case wind:
                    return -2;
                case fire:
                    return 2;
                case ice:
                    return 2;
                case steel:
                    return 2;
            }
            break;
        case wind:
            switch (enemy.getElement()) {
                case earth:
                    return -2;
                case ice:
                    return 2;
                case steel:
                    return -2;
            }
            break;
        case fire:
            switch (enemy.getElement()) {
                case water:
                    return -2;
                case ice:
                    return 2;
                case earth:
                    return -2;
                case steel:
                    return 2;
            }
            break;
        case ice:
            switch (enemy.getElement()) {
                case water:
                    return -2;
                case earth:
                    return 2;
                case fire:
                    return -2;
                case ice:
                    return -2;
            }
            break;
        case steel:
            switch (enemy.getElement()) {
                case water:
                    return 2;
                case fire:
                    return -2;
                case wind:
                    return 2;
                case steel:
                    return -2;
            }
            break;
        default:
            return 0;
    }
    return 0;
}

void Creature::showCurrentChosen(Creature *ally, Creature *pc) {
    std::cout<<"\t\t\t\t\tYOU"<<std::endl<<std::endl;
    std::cout<<" Name"<<" \t\t"<<"Attack"<<"\t"<<"Agility"<<"\t"<<"Health"<<"\t"<<"Element"<<"\t\t"<<"Special Move"<<std::endl;
    std::cout<<*ally<<std::endl;
    std::cout<<"\t\t\t\t\tENEMY"<<std::endl<<std::endl;
    std::cout<<" Name"<<" \t\t"<<"Attack"<<"\t"<<"Agility"<<"\t"<<"Health"<<"\t"<<"Element"<<"\t\t"<<"Special Move"<<std::endl;
    std::cout<<*pc<<std::endl;
}
