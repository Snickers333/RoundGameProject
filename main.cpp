#include <iostream>
#include "Creature.h"
#include "CreaturesList.h"
#include "SpecialMove.h"
CreaturesList CREATURESLIST;

using namespace std;
int main() {
    //checkIfToContinue();
    cout<<"Welcome to the Game!"<<endl<<"List of available Creatures :"<<endl<<endl;
    cout<<CREATURESLIST;

//    CreaturesList userList = CreaturesList::makeUserSelection(CREATURESLIST);
//    cout<<"Your team :"<<endl;
//    cout<<userList;
//    cout<<endl;
//

    CREATURESLIST.setDifficulty();
    CreaturesList enemy = CreaturesList::selectRandom(CREATURESLIST);
    cout<<enemy;
    return 0;
}



