
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
    SpecialMove();
    SpecialMove(Special special);
    friend std::ostream& operator <<(std::ostream& o, const SpecialMove& c);
    Special getSpecial();
    std::string getSpecialString() const;
    static Special SpecialMove::getSpecialIndex(std::string special);
};



#endif //ROUNDGAMEPROJECT_SPECIALMOVE_H
