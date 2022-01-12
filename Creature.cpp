//
// Created by bkkami on 28.12.2021.
//

#include "Creature.h"
#include <utility>

// Constructor creating object and assigning necessary fields for the Creature
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

// Overloading of output stream operator which outputs text representation of Element Enum
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

// Name Getter
const std::string &Creature::getName() const {
    return name;
}

// Strength Getter
int Creature::getStrength() const {
    return strength;
}

// Strength Setter
void Creature::setStrength(int str) {
    Creature::strength = str;
}

// Agility Getter
int Creature::getAgility() const {
    return agility;
}

// Agility Setter
void Creature::setAgility(int ag) {
    Creature::agility = ag;
}

// HP Getter
int Creature::getHp() const {
    return HP;
}

// HP Setter
void Creature::setHp(int hp) {
    HP = hp;
}

// SpecialMove Getter
SpecialMove Creature::getSpecialMove() const {
    return specialMove;
}

// Exp amount Getter
int Creature::getExp() const {
    return EXP;
}

// Exp amount Setter
void Creature::setExp(int exp) {
    EXP = exp;
}

// Element type Getter
Element Creature::getElement() const {
    return element;
}

// Method that checks if Special Ability is on cooldown ( True = is on cooldown, False = is not on cooldown )
bool Creature::isCooldown() const {
    return cooldown;
}

// Method that sets Special Ability cooldown
void Creature::setCooldown(bool cd) {
    Creature::cooldown = cd;
}

// Output stream operator overload for important Creature fields
std::ostream &operator<<(std::ostream &o, const Creature &c) {
    o<<" "<<c.getName()<<"\t"<<c.getStrength()<<"\t"<<c.getAgility()<<"\t"<<c.getHp()<<"\t"<<c.getElement()<<"\t\t"<<c.getSpecialMove()<<std::endl;
    return o;
}

// Method that attacks enemy Creature, setting enemy Creature hp accordingly, checking if enemy Creature died and adding xp if applicable
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

// Checks if a Creature should be leveled up and if so - increases its Strength by 2 and HP by 3
void Creature::checkLevelUp() {
    if (this->getExp() % 3 == 0) {
        this->setExp(this->getExp()+1);
        this->setHp(this->getHp()+3);
        this->setStrength(this->getStrength()+2);
        std::cout<<std::endl<<this->getName()<<" Has Just Leveled UP !"<<std::endl;
    }
}

// Uses special ability of given creature and puts its cooldown to True
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

// Method that checks if the two given Creature's Elements are conflicting with each other - Modifying damage accordingly
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

// Prints out currently chosen Creatures by user and Enemy
void Creature::showCurrentChosen(Creature *ally, Creature *pc) {
    std::cout<<"\t\t\t\t\tYOU"<<std::endl<<std::endl;
    std::cout<<" Name"<<" \t\t"<<"Attack"<<"\t"<<"Agility"<<"\t"<<"Health"<<"\t"<<"Element"<<"\t\t"<<"Special Move"<<std::endl;
    std::cout<<*ally<<std::endl;
    std::cout<<"\t\t\t\t\tENEMY"<<std::endl<<std::endl;
    std::cout<<" Name"<<" \t\t"<<"Attack"<<"\t"<<"Agility"<<"\t"<<"Health"<<"\t"<<"Element"<<"\t\t"<<"Special Move"<<std::endl;
    std::cout<<*pc<<std::endl;
}

// Method that checks if the creature is still alive
bool Creature::alive() const {
    if (this->getHp() > 0) {
        return true;
    }
    return false;
}

// Method that converts given string to an Element class type
Element Creature::getElementIndex(const std::string& element) {
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
