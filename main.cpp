#include <iostream>
#include <vector>
#include "Creature.h"
#include "CreaturesList.h"
#include "SpecialMove.h"
const CreaturesList CREATURESLIST;

static CreaturesList makeUserSelection();

using namespace std;
int main() {
    //checkIfToContinue();
    cout<<"Welcome to the Game!"<<endl<<"List of available Creatures :"<<endl;
    CreaturesList userList = makeUserSelection();
    cout<<userList;
    return 0;
}

static CreaturesList makeUserSelection() {
    vector<Creature> result;

    int selection;
    cout<<CREATURESLIST;

    for (int i = 6; i > 0; i--) {
        cout<<"Choose your Creatures. "<<i<<" to go"<<endl;
        cout<<"Select :";
        cin>>selection;
        result.push_back(CreaturesList::getCopyCreature(selection, CREATURESLIST));
    }
    return result;
}

