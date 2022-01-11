#include "SpecialMove.h"

SpecialMove::SpecialMove(Special special) {
    this->special = special;
    switch(this->special) {
        case attackBoost:
            this->describtion = "Attack Boost : Boosts your attack damage by 2";
            break;
        case hpBoost:
            this->describtion = "HP Boost : Boosts your health by 5";
            break;
        case agilityBoost:
            this->describtion = "Agility Boost : Boosts your agility by 10";
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
            this->describtion = "XP Boost : Gives some additional XP points";
            break;
        case tornado:
            this->describtion = "Tornado : Lower enemy's agility by 20";
            break;
        default:
            break;
    }
}

SpecialMove::SpecialMove() {
    this->describtion = "Special move not specified";
}

std::ostream &operator<<(std::ostream &o, const SpecialMove &c) {
    o<<c.describtion;
    return o;
}

Special SpecialMove::getSpecial() {
    return special;
}

std::string SpecialMove::getSpecialString() const {
    switch (this->special) {
        case hpBoost:
            return "hpBoost";
        case agilityBoost:
            return "agilityBoost";
        case attackBoost:
            return "attackBoost";
        case tornado:
            return "tornado";
        case ignite:
            return "ignite";
        case laserBeam:
            return "laserBeam";
        case exhaust:
            return "exhaust";
        case xpBoost:
            return "xpBoost";
    }
    return "std::string()";
}

Special SpecialMove::getSpecialIndex(std::string special) {
    if (special == "hpBoost") {
        return hpBoost;
    } else if (special == "agilityBoost"){
        return agilityBoost;
    } else if (special == "attackBoost"){
        return attackBoost;
    } else if (special == "tornado"){
        return tornado;
    } else if (special == "ignite"){
        return ignite;
    } else if (special == "laserBeam"){
        return laserBeam;
    } else if (special == "exhaust"){
        return exhaust;
    } else {
        return xpBoost;
    }
}
