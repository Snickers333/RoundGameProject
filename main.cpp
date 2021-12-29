#include <iostream>
#include "Creature.h"
#include "CreaturesList.h"
#include "SpecialMove.h"
CreaturesList CREATURESLIST;
int ROUND = 1;

static void play(const CreaturesList& user, const CreaturesList& enemy);

static void playRound(CreaturesList user, CreaturesList enemy);

using namespace std;
int main() {
    //checkIfToContinue(); TODO from saved state (ROUND must be read)
    cout<<"\t\t\t\tWelcome to the Game!"<<endl<<"List of available Creatures :"<<endl<<endl;
    cout<<CREATURESLIST;

    CreaturesList user = CREATURESLIST.makeUserSelection();
    cout<<"\t\t\t\t\tYour team :"<<endl<<endl;
    cout<<user;
    cout<<endl;


    CREATURESLIST.setDifficulty();
    CreaturesList enemy = CREATURESLIST.selectRandomEnemies();
    play(user, enemy);
    return 0;
}

static void play(const CreaturesList& user, const CreaturesList& enemy) {
    while(ROUND < 4) {
        int exit;
        cout<<"\t\t\t\tDo you want to save the game and exit ?"<<endl<<"\t\t\t\t\t1. Yes"<<endl<<"\t\t\t\t\t2. No"<<endl<<"\t\t\t\t\tSelect :";
        cin>>exit;
        if (exit == 1) {
            //TODO Save Game
            return;
        }

        cout<<endl<<"\t\t\t\t\tRound "<<ROUND++<<endl<<"\t\t\t\t\tFIGHT"<<endl<<endl;
        playRound(user, enemy);
    }
}

static void playRound(CreaturesList user, CreaturesList enemy) {
    Creature *ally = user.selectCreature();
    Creature *pc = enemy.selectCreature();

    int choice = 0;
    while (user.creaturesAlive() && enemy.creaturesAlive()) {
        if (choice != 0) {
            Creature::showCurrentChosen(ally, pc);
        }
        cout<<"\t\t\t\tYour options are :"<<endl<<"\t\t\t\t\t1. Attack"<<endl<<"\t\t\t\t\t2. Special attack"<<endl<<"\t\t\t\t\t3. Change Creature"<<endl<<"\t\t\t\t\t4. Show Creatures List"<<endl<<"\t\t\t\t\tSelect :";
        cin>>choice;
        switch (choice) {
            case 1:
                ally->attack(*pc);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                CreaturesList::showCurrent(user, enemy);
        }
    }
}

