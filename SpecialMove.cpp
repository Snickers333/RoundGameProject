#include "SpecialMove.h"

SpecialMove::SpecialMove(Special special) {
    this->special = special;
    switch(this->special) {
        case attackBoost:
            this->describtion = "Boosts your attack damage by 3 for 2 rounds";
            break;
        case hpBoost:
            this->describtion = "Boosts your health by 5 for 2 rounds";
            break;
        case agilityBoost:
            this->describtion = "Boosts your agility by <Placeholder> for 2 rounds";
            break;
        default:
            break;
    }
}

SpecialMove::SpecialMove() {
    this->describtion = "Special move not specified";
}
