#include "SpecialMove.h"

SpecialMove::SpecialMove(Special special) {
    this->special = special;
    switch(this->special) {
        case attackBoost:
            this->describtion = "Attack Boost : Boosts your attack damage by 3 for 2 rounds";
            break;
        case hpBoost:
            this->describtion = "HP Boost : Boosts your health by 5 for 2 rounds";
            break;
        case agilityBoost:
            this->describtion = "Agility Boost : Boosts your agility by 0.2 for 2 rounds";
            break;
        case ignite:
            this->describtion = "Ignite : Set your enemy on fire dealing him 9 damage";
            break;
        case exhaust:
            this->describtion = "Exhaust : Make your enemy tired and deal 3 damage less";
            break;
        case laserBeam:
            this->describtion = "Laser Beam : Deal 7 damage to your enemy";
            break;
        case xpBoost:
            this->describtion = "XP Boost : level up your Creature instantly";
            break;
        case tornado:
            this->describtion = "Tornado : Lower enemy's agility by 0.2";
            break;
        default:
            break;
    }
    this->cooldown = false;
}

SpecialMove::SpecialMove() {
    this->describtion = "Special move not specified";
}

std::ostream &operator<<(std::ostream &o, const SpecialMove &c) {
    o<<c.describtion;
    return o;
}
