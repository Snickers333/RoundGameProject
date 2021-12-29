#include <iostream>
#include "Creature.h"
#include "CreaturesList.h"
#include "SpecialMove.h"
CreaturesList CREATURESLIST;

static void playRound(CreaturesList user, CreaturesList enemy);

using namespace std;
int main() {
    //checkIfToContinue(); TODO from saved state
    cout<<"Welcome to the Game!"<<endl<<"List of available Creatures :"<<endl<<endl;
    cout<<CREATURESLIST;

    CreaturesList user = CREATURESLIST.makeUserSelection();
    cout<<"Your team :"<<endl;
    cout<<user;
    cout<<endl;


    CREATURESLIST.setDifficulty();
    CreaturesList enemy = CREATURESLIST.selectRandomEnemies();
    playRound(user, enemy);
    return 0;
}

static void playRound(CreaturesList user, CreaturesList enemy) {
    Creature *ally = user.selectCreature();
    Creature *pc = enemy.selectCreature();
}

