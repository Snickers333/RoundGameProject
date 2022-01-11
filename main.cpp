#include <iostream>
#include "Creature.h"
#include "CreaturesList.h"
#include "SpecialMove.h"
CreaturesList CREATURESLIST;
int ROUND = 1;

static void play(const CreaturesList& user, const CreaturesList& enemy);

static void playRound(CreaturesList user, CreaturesList enemy);

static void computerMove(CreaturesList enemy, Creature *pc, Creature *ally);

using namespace std;
int main() {
    //checkIfToContinue(); TODO from saved state (ROUND must be read), AGILITY DODGE CHANCE, COLOURED LINES
    cout<<"\t\t\t\tWelcome to the Game!"<<endl<<"List of available Creatures :"<<endl<<endl;
    cout<<CREATURESLIST;

    CreaturesList user = CREATURESLIST.makeUserSelection();
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

        cout<<endl<<"\t\t\t\t\tRound "<<ROUND<<endl<<"\t\t\t\t\tFIGHT"<<endl;
        playRound(user, enemy);
    }
    cout<<endl<<"\t\t\t\tCONGRATULATIONS"<<"    YOU WON"<<endl;
}

static void playRound(CreaturesList user, CreaturesList enemy) {
    Creature *ally = user.selectCreature();
    Creature *pc = enemy.selectCreaturePC(ally);
    cout<<endl<<"\t\t\t\tYour enemy is :"<<endl<<endl;
    cout<<" Name"<<" \t\t"<<"Attack"<<"\t"<<"Agility"<<"\t"<<"Health"<<"\t"<<"Element"<<"\t\t"<<"Special Move"<<endl;
    cout<<*pc<<endl;

    int choice = 0;
    while (user.creaturesAlive() && enemy.creaturesAlive()) {
        if (!ally->alive()) {
            cout<<endl<<"Your creature has died !"<<endl;
            ally = user.selectCreature();
        } else if (!pc->alive()) {
            pc = enemy.selectCreaturePC(pc);
        }
        if (choice != 0) {
            Creature::showCurrentChosen(ally, pc);
        }
        cout<<"\t\t\t\tYour options are :"<<endl<<"\t\t\t\t\t1. Attack"<<endl<<"\t\t\t\t\t2. Special attack"<<endl<<"\t\t\t\t\t3. Change Creature"<<endl<<"\t\t\t\t\t4. Show Creatures List"<<endl<<"\t\t\t\t\tSelect :";
        cin>>choice;
        switch (choice) {
            case 1:
                ally->attack(*pc, 0);
                computerMove(enemy, pc, ally);
                break;
            case 2:
                if (ally->specialAttack(*pc))
                    break;
                computerMove(enemy, pc, ally);
                break;
            case 3:
                ally = user.selectCreature();
                computerMove(enemy, pc, ally);
                break;
            case 4:
                CreaturesList::showCurrent(user, enemy);
                break;
            default :
                cout<<"Make a choice in range"<<endl;
                break;
        }
    }
    if (!enemy.creaturesAlive()) {
        cout<<"\t\t\t\t\tNice Job !"<<endl<<"\t\t\t\tYou won the "<<ROUND++<<" round!"<<endl<<endl;
    } else {
        cout<<"\t\t\t\t\tYou Lost"<<endl<<"\t\t\t\tGood luck next time!"<<endl<<endl;
    }
}

static void computerMove(CreaturesList enemy, Creature *pc, Creature *ally) {
    srand((unsigned) time(0));
    int choice;
    bool valid = true;
    while (valid) {
        choice = (rand() % 3) + 1;
        switch (choice) {
            case 1:
                pc->attack(*ally, 0);
                valid = false;
                cout<<"PC attacked";
                break;
            case 2:
                if (pc->specialAttack(*ally)) {
                    break;
                }
                valid = false;
                cout<<"PC special";
                break;
            case 3:
                pc = enemy.selectCreaturePC(pc);
                valid = false;
                cout<<"PC creatureselect";
                break;
            default :
                cout<<"Make a choice in range"<<endl;
                break;
        }
    }
}

