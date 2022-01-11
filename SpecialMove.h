
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
    tornado, // try
    ignite,
    laserBeam,
    exhaust, //try
    xpBoost
};

class SpecialMove {
private:
    Special special;
    std::string describtion;
    bool cooldown;
public:
    SpecialMove();
    SpecialMove(Special special);
    friend std::ostream& operator <<(std::ostream& o, const SpecialMove& c);
    Special getSpecial() const;
    bool isCooldown() const;
    void setCooldown(bool cooldown);
};



#endif //ROUNDGAMEPROJECT_SPECIALMOVE_H
