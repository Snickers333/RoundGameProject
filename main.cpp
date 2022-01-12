#include <iostream>
#include "Creature.h"
#include "CreaturesList.h"


CreaturesList CREATURESLIST;
int ROUND = 1;

static void play(CreaturesList& user, CreaturesList& enemy);

static void playRound(CreaturesList &user, CreaturesList &enemy);

static void computerMove(CreaturesList &enemy, CreaturesList &user, Creature *&pc, Creature *&ally);

using namespace std;
int main() {            //TODO from saved state (ROUND must be read), COLOURED LINES
    int choice;
    cout<<"Do you wish to begin where you left off ?"<<endl<<"1. Yes"<<endl<<"2. No"<<endl<<"Selection :";
    cin>>choice;
    CreaturesList user;
    if (choice == 1) {
        ROUND = user.readGame();
        cout<<endl<<"The round number is "<<ROUND<<endl;
    } else {
        cout << "\t\t\t\tWelcome to the Game!" << endl << "List of available Creatures :" << endl << endl;
        cout << CREATURESLIST;
        user = CREATURESLIST.makeUserSelection();
    }
    CREATURESLIST.setDifficulty();
    CreaturesList enemy = CREATURESLIST.selectRandomEnemies();
    play(user, enemy);
    return 0;
}

static void play(CreaturesList& user, CreaturesList& enemy) {
    while(ROUND < 4) {
        int exit;
        cout<<"\t\t\t\tDo you wish to save the game and exit ?"<<endl<<"\t\t\t\t\t1. Yes"<<endl<<"\t\t\t\t\t2. No"<<endl<<"\t\t\t\t\tSelect :";
        cin>>exit;
        if (exit == 1) {
            user.saveGame(ROUND);
            return;
        }

        cout<<endl<<"\t\t\t\t\tRound "<<ROUND<<endl<<"\t\t\t\t\tFIGHT"<<endl;
        playRound(user, enemy);
    }
    cout<<endl<<"\t\t\t\tCONGRATULATIONS !! YOU WON THE GAME !!"<<endl;
}

static void playRound(CreaturesList &user, CreaturesList &enemy) {
    Creature *ally = user.selectCreature();
    Creature *pc = enemy.selectCreaturePC();
    cout<<endl<<"\t\t\t\tYour enemy is :"<<endl<<endl;
    cout<<" Name"<<" \t\t"<<"Attack"<<"\t"<<"Agility"<<"\t"<<"Health"<<"\t"<<"Element"<<"\t\t"<<"Special Move"<<endl;
    cout<<*pc<<endl;

    int choice = 0;
    while (user.creaturesAlive() && enemy.creaturesAlive()) {
        if (choice != 0) {
            Creature::showCurrentChosen(ally, pc);
        }
        cout<<"\t\t\t\tYour options are :"<<endl<<"\t\t\t\t\t1. Attack"<<endl<<"\t\t\t\t\t2. Special attack"<<endl<<"\t\t\t\t\t3. Change Creature"<<endl<<"\t\t\t\t\t4. Show Creatures List"<<endl<<"\t\t\t\t\tSelect :";
        cin>>choice;
        int result;
        switch (choice) {
            case 1:
                if (ally->attack(*pc, 0)) {
                    pc = enemy.selectCreaturePC();
                    break;
                }
                computerMove(enemy, user, pc, ally);
                break;
            case 2:
                result = ally->specialAttack(*pc);
                if (result == 1) {
                    break;
                } else if (result == 2) {
                    pc = enemy.selectCreaturePC();
                    break;
                }
                computerMove(enemy, user, pc, ally);
                break;
            case 3:
                ally = user.selectCreature();
                computerMove(enemy, user, pc, ally);
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
        ROUND = 10;
    }
}

static void computerMove(CreaturesList &enemy,CreaturesList &user, Creature *&pc, Creature *&ally) {
    srand((unsigned) time(0));
    int choice;
    bool valid = true;
    while (valid) {
        if (pc->isCooldown()) {
            choice = (rand() % 3) + 1;
        } else {
            choice = 1;
        }
        int result;
        if (choice == 2) {
            result = pc->specialAttack(*ally);
            if (result == 1) {
                break;
            } else if (result == 2) {
                cout << endl << "Your creature has died !" << endl;
                ally = user.selectCreature();
            }
            valid = false;
        } else {
            if (pc->attack(*ally, 0)) {
                cout << endl << "Your creature has died !" << endl;
                ally = user.selectCreature();
            }
            valid = false;
        }
    }
}