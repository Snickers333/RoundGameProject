//
// Created by bkkami on 28.12.2021.
//

#include "Creature.h"
#include <utility>

Creature::Creature(std::string name,int strength, int agility, int HP, Special special, Element element) {
    this->name = std::move(name);
    this->strength = strength;
    this->agility = agility;
    this->HP = HP;
    this->specialMove = SpecialMove(special);
    this->EXP = 1;
    this->element = element;
    this->cooldown = false;
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

SpecialMove Creature::getSpecialMove() const {
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

bool Creature::isCooldown() const {
    return cooldown;
}

void Creature::setCooldown(bool cooldown) {
    Creature::cooldown = cooldown;
}

std::ostream &operator<<(std::ostream &o, const Creature &c) {
    o<<" "<<c.getName()<<"\t"<<c.getStrength()<<"\t"<<c.getAgility()<<"\t"<<c.getHp()<<"\t"<<c.getElement()<<"\t\t"<<c.getSpecialMove()<<std::endl;
    return o;
}

bool Creature::attack(Creature &enemy, int fixed) {
    srand((unsigned) time(0));
    if (this->getAgility() > (rand() % 100)) {
        std::cout<<std::endl<<"Whoops ! "<<enemy.getName()<<" has dodged "<<this->getName()<<"'s attack !"<<std::endl;
        return false;
    }
    int power;
    if (fixed == 0){
        power = this->getStrength();
    } else {
        power = fixed;
    }
    int modifier = conflictModifier(this, enemy);
    if ((modifier + power) < 0) {
        std::cout<<std::endl<<"Your damage to this entity was too low to make any harm"<<std::endl<<std::endl;
        return false;
    }
    enemy.setHp(enemy.getHp()-(power+modifier));
    std::cout<<std::endl<<this->getName()<<" has dealt "<<(power+modifier)<<" damage to "<<enemy.getName()<<std::endl<<std::endl;
    if (!enemy.alive()) {
        enemy.setHp(0);
        std::cout<<std::endl<<enemy.getName()<<" Has Fallen !"<<std::endl;
        this->setExp(this->getExp()+1);
        this->checkLevelUp();
        return true;
    }
    return false;
}

void Creature::checkLevelUp() {
    if (this->getExp() % 3 == 0) {
        this->setExp(this->getExp()+1);
        this->setHp(this->getHp()+3);
        this->setStrength(this->getStrength()+2);
        std::cout<<std::endl<<this->getName()<<" Has Just Leveled UP !"<<std::endl;
    }
}

int Creature::specialAttack(Creature &enemy) {
    if (this->isCooldown()) {
        std::cout<<std::endl<<this->getName()<<" : Special ability is on cooldown."<<std::endl;
        return 1;
    }
    switch (this->specialMove.getSpecial()) {
        case hpBoost:
            std::cout<<std::endl<<this->getName()<<" ate a lot, resulting in HP increased by 5 !"<<std::endl;
            this->setHp(this->getHp()+5);
            break;
        case agilityBoost:
            std::cout<<std::endl<<this->getName()<<" became quicker and far less noticeable. Agility has increased by 10 !"<<std::endl;
            this->setAgility(this->getAgility() + 10);
            break;
        case attackBoost:
            std::cout<<std::endl<<this->getName()<<" is growing bigger and stronger. Attack has increased by 3 !"<<std::endl;
            this->setStrength(this->getStrength() + 3);
            break;
        case tornado:
            if (enemy.getAgility() < 30) {
                std::cout<<std::endl<<enemy.getName()<<" is slow enough. No need to slow him more."<<std::endl;
                return 1;
            } else {
                std::cout<<std::endl<<"The tornado slows "<<enemy.getName()<<", lowering his Agility by 20 !"<<std::endl;
                enemy.setAgility(enemy.getAgility()-20);
            }
            break;
        case ignite:
            std::cout<<std::endl<<"Black magic sets "<<enemy.getName()<<" on fire !"<<std::endl;
            if (this->attack(enemy, 9)){
                return 2;
            }
            break;
        case laserBeam:
            std::cout<<std::endl<<this->getName()<<"'s laser tears through "<<enemy.getName()<<" !"<<std::endl;
            if (this->attack(enemy, 7)){
                return 2;
            }
            break;
        case exhaust:
            if (enemy.getStrength() >= 4) {
                enemy.setStrength(enemy.getStrength() - 3);
                std::cout<<std::endl<<enemy.getName()<<" is now exhausted, dealing 3 damage less !"<<std::endl;
            } else {
                std::cout<<std::endl<<enemy.getName()<<" is too weak to be exhausted further"<<std::endl;
                return 1;
            }
            break;
        case xpBoost:
            this->setExp(this->getExp()+1);
            std::cout<<std::endl<<"XP has been increased !"<<std::endl;
            this->checkLevelUp();
            break;
    }
    this->setCooldown(true);
    return 0;
}

int Creature::conflictModifier(const Creature *ally, const Creature &enemy) {
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

bool Creature::alive() {
    if (this->getHp() > 0) {
        return true;
    }
    return false;
}

Element Creature::getElementIndex(std::string element) {
    if (element == "Water") {
        return water;
    } else if (element == "Earth") {
        return earth;
    } else if (element == "Wind") {
        return wind;
    } else if (element == "Fire") {
        return fire;
    } else if (element == "Ice") {
        return ice;
    } else {
        return steel;
    }
}
