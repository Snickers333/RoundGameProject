#include "SpecialMove.h"

// Depending on type of Special enum, this constructor sets special field and a description associated with it
SpecialMove::SpecialMove(Special special) {
    this->special = special;
    switch (this->special) {
        case attackBoost:
            this->describtion = "Attack Boost : Boosts your attack damage by 3";
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

// Default constructor in case it is needed
SpecialMove::SpecialMove() {
    this->describtion = "Special move not specified";
}

// Overloading output stream operator which converts SpecialMove class object to description of this SpecialMove class
std::ostream &operator<<(std::ostream &o, const SpecialMove &c) {
    o << c.describtion;
    return o;
}

// Getter for the private special field
Special SpecialMove::getSpecial() {
    return special;
}

// Getter for private special field with conversion to string
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

// Method which converts input string to Special enum
Special SpecialMove::getSpecialIndex(const std::string &special) {
    if (special == "hpBoost") {
        return hpBoost;
    } else if (special == "agilityBoost") {
        return agilityBoost;
    } else if (special == "attackBoost") {
        return attackBoost;
    } else if (special == "tornado") {
        return tornado;
    } else if (special == "ignite") {
        return ignite;
    } else if (special == "laserBeam") {
        return laserBeam;
    } else if (special == "exhaust") {
        return exhaust;
    } else {
        return xpBoost;
    }
}
