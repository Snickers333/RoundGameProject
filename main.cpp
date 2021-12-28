#include <iostream>
#include <vector>
#include "Creature.h"
#include "CreaturesList.h"
#include "SpecialMove.h"
const CreaturesList CREATURESLIST;

using namespace std;
int main() {
    //checkIfToContinue();
    cout<<"Welcome to the Game!"<<endl<<"List of available Creatures :"<<endl;
    CreaturesList userList = CreaturesList::makeUserSelection(CREATURESLIST);
    cout<<userList;
    return 0;
}



