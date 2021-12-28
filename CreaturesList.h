//
// Created by bkkami on 28.12.2021.
//

#ifndef ROUNDGAMEPROJECT_CREATURESLIST_H
#define ROUNDGAMEPROJECT_CREATURESLIST_H
#include <iostream>
#include <vector>
#include "Creature.h"
#include "SpecialMove.h"

class CreaturesList {
private:
    std::vector<Creature> list;
public:
    CreaturesList();
    CreaturesList(std::vector<Creature> list);
    friend std::ostream& operator <<(std::ostream& o, const CreaturesList& c);
};


#endif //ROUNDGAMEPROJECT_CREATURESLIST_H
