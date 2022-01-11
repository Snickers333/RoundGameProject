//
// Created by bkkami on 28.12.2021.
//

#ifndef ROUNDGAMEPROJECT_CREATURESLIST_H
#define ROUNDGAMEPROJECT_CREATURESLIST_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Creature.h"
#include "SpecialMove.h"
#include <fstream>

using namespace std;
class CreaturesList {
private:
    std::vector<Creature> list;
public:
    CreaturesList();
    CreaturesList(std::vector<Creature> list);
    friend std::ostream& operator <<(std::ostream& o, const CreaturesList& c);
    Creature getCopyCreature(int index) const;
    CreaturesList makeUserSelection() const;
    void setDifficulty();
    CreaturesList selectRandomEnemies() const;
    Creature * selectCreature();
    bool playerOrPc();
    bool creaturesAlive();
    static void showCurrent(CreaturesList list, CreaturesList list1);
    Creature *selectCreaturePC(Creature *creature);
    void saveGame() const;
};


#endif //ROUNDGAMEPROJECT_CREATURESLIST_H
