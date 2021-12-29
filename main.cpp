#include <iostream>
#include "Creature.h"
#include "CreaturesList.h"
#include "SpecialMove.h"
CreaturesList CREATURESLIST;

static void play(CreaturesList user, CreaturesList enemy);

static void playRound();

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
    play(user, enemy);
    return 0;
}

static void play(CreaturesList user, CreaturesList enemy) {
    Creature *ally = user.selectCreature();
    Creature *pc = enemy.selectCreature();

    int round = 1;
    while(user.creaturesAlive() && enemy.creaturesAlive()) {
        int exit;
        cout<<"Do you want to save the game and exit ?"<<endl<<"1. Yes"<<endl<<"2. No"<<endl<<"Select :";
        cin>>exit;
        if (exit == 1) {
            //TODO Save Game
            return;
        }

        cout<<"Round "<<round++<<endl<<"FIGHT"<<endl;
        playRound();
    }
}

static void playRound() {

}

