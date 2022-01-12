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
#include <string>


using namespace std;
class CreaturesList {
private:
    std::vector<Creature> list;
public:
    // Default constructor. Also used to create list of default Creatures
    CreaturesList();
    // Constructor that assigns existing vector to CreatureList object
    CreaturesList(std::vector<Creature> list);
    // Overload output stream operator for CreaturesList
    friend std::ostream& operator <<(std::ostream& o, const CreaturesList& c);
    // Method returns a copy of an object from CreatureList
    Creature getCopyCreature(int index) const;
    // Method which allows user to select his starting creatures
    CreaturesList makeUserSelection() const;
    // Method that sets difficulty of the game
    void setDifficulty();
    // Method that selects random list of enemy Creatures
    CreaturesList selectRandomEnemyList() const;
    // Method that helps user to select currently controlled Creature
    Creature * selectCreature();
    // Method that checks if any of the Creatures stored on list is alive
    bool creaturesAlive();
    // Method that prints currently used Allied Creatures and Enemy Creatures
    static void showCurrent(const CreaturesList& list, const CreaturesList& list1);
    // Method that selects another creature used by computer
    Creature *selectCreaturePC();
    // Method that saves the current game progress
    void saveGame(int round) const;
    // Method that loads current game progress
    int readGame();
    // Method that refreshes all Creatures Special ability cooldown
    void refreshCooldowns();
};


#endif //ROUNDGAMEPROJECT_CREATURESLIST_H
