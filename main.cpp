#include <iostream>
#include "Creature.h"
#include "CreaturesList.h"
#include "SpecialMove.h"
CreaturesList CREATURESLIST;

using namespace std;
int main() {
    //checkIfToContinue(); TODO from saved state
    cout<<"Welcome to the Game!"<<endl<<"List of available Creatures :"<<endl<<endl;
    cout<<CREATURESLIST;

    CreaturesList userList = CREATURESLIST.makeUserSelection();
    cout<<"Your team :"<<endl;
    cout<<userList;
    cout<<endl;


    CREATURESLIST.setDifficulty();
    CreaturesList enemy = CREATURESLIST.selectRandomEnemies();
    cout<<enemy;
    return 0;
}



