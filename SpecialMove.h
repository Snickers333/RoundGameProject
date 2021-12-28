
//
// Created by bkkami on 28.12.2021.
//

#ifndef ROUNDGAMEPROJECT_SPECIALMOVE_H
#define ROUNDGAMEPROJECT_SPECIALMOVE_H


#include <iostream>
enum Special {
    hpBoost,
    agilityBoost,
    attackBoost
};

class SpecialMove {
private:
    Special special;
    std::string describtion;
public:
    SpecialMove();
    SpecialMove(Special special);
};



#endif //ROUNDGAMEPROJECT_SPECIALMOVE_H
