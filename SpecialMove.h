
//
// Created by bkkami on 28.12.2021.
//

#ifndef ROUNDGAMEPROJECT_SPECIALMOVE_H
#define ROUNDGAMEPROJECT_SPECIALMOVE_H


#include <iostream>

enum Special {
    hpBoost,
    agilityBoost,
    attackBoost,
    tornado,
    ignite,
    laserBeam,
    exhaust,
    xpBoost
};

class SpecialMove {
private:
    Special special;
    std::string describtion;
public:
    // Default constructor
    SpecialMove();

    // Constructor which initializes special and the description associated to it
    SpecialMove(Special special);

    // Overloading output stream operator
    friend std::ostream &operator<<(std::ostream &o, const SpecialMove &c);

    // Getter private special field
    Special getSpecial();

    // Special field Getter with conversion to string
    std::string getSpecialString() const;

    // Method - String conversion to Special Enum
    static Special SpecialMove::getSpecialIndex(const std::string &special);
};


#endif //ROUNDGAMEPROJECT_SPECIALMOVE_H
