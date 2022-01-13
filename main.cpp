#include <iostream>
#include "Creature.h"
#include "CreaturesList.h"

static void play(CreaturesList& user, CreaturesList& enemy);
static void playRound(CreaturesList &user, CreaturesList &enemy);
static void computerMove(CreaturesList &enemy, CreaturesList &user, Creature *&pc, Creature *&ally);

// Default CreatureList that holds all 15 default Creatures
CreaturesList CREATURESLIST;

// Round global counter
int ROUND = 1;

using namespace std;

/*
 * Main method starts with asking user if he wants to continue from saved progress
 * Continues with either loading saved progress or
 * Selecting new Creatures from the default CREATURESLIST list
 * Sets Difficulty of the game
 * Selects random enemies for next Round
 */
int main() {            //TODO COLOURED LINES KOMENTARZE
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
    CreaturesList enemy = CREATURESLIST.selectRandomEnemyList();
    play(user, enemy);
    return 0;
}

/*
 * This method has a loop which will start another rounds until the ROUND counter hits 5 rounds which means the game will have 4 rounds
 * At the beginning of every round user is asked whether he wants to save the game and exit
 * If not - The game will continue by selecting another random enemies list for this round
 * When the loop ends - the game will check if any of the creatures on user list is alive and if so it will print out congratulations message
 */
static void play(CreaturesList& user, CreaturesList& enemy) {
    while(ROUND < 5) {
        int exit;
        cout<<"\t\t\t\tDo you wish to save the game and exit ?"<<endl<<"\t\t\t\t\t1. Yes"<<endl<<"\t\t\t\t\t2. No"<<endl<<"\t\t\t\t\tSelect :";
        cin>>exit;
        if (exit == 1) {
            user.saveGame(ROUND);
            return;
        }
        enemy = CREATURESLIST.selectRandomEnemyList();
        cout<<endl<<"\t\t\t\t\tRound "<<ROUND<<endl<<"\t\t\t\t\tFIGHT"<<endl;
        playRound(user, enemy);
    }
    if (user.creaturesAlive()) {
        cout<<endl<<"\t\t\t\tCONGRATULATIONS !! YOU WON THE GAME !!"<<endl;
    }
}

/*
 * This method is the core game itself
 * In the beginning we refresh cooldowns of every Creature in user CreatureList
 * Game begins with picking currently controlled Creatures
 * For the duration of the round the user will be presented with options to :
 *  1. - attack enemy
 *  2. - use special ability
 *  3. - change currently controlled Creature
 *  4. - show list of user and enemy CreatureList
 *
 *  After every decision made (except 4) the computer moves using method computerMove();
 *
 *  The loop ends when either user or enemy hasn't got any Creature alive on their CreatureList
 *  Depending on the result the game will show congratulation message or good luck message
 */
static void playRound(CreaturesList &user, CreaturesList &enemy) {
    if (ROUND > 1) {
        user.refreshCooldowns();
    }
    Creature *ally = user.selectCreature();
    Creature *pc = enemy.selectCreaturePC();

    int choice = 0;
    while (user.creaturesAlive() && enemy.creaturesAlive()) {
        Creature::showCurrentChosen(ally, pc);
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

/*
 * This method is used for computer answers
 * The computer has ability to attack user or use special ability
 * Choice is made randomly.
 * When computer's Creature dies, another one from the list is chosen to be controlled
 */
static void computerMove(CreaturesList &enemy,CreaturesList &user, Creature *&pc, Creature *&ally) {
    srand((unsigned) time(0));
    int choice;
    bool valid = true;
    while (valid) {
        if (pc->isCooldown()) {
            choice = 0;
        } else {
            choice = rand() % 2;
        }
        int result;
        if (choice == 1) {
            result = pc->specialAttack(*ally);
            if (result == 2) {
                cout << endl << "Your creature has died !" << endl;
                if (user.creaturesAlive()){
                    ally = user.selectCreature();
                }
            }
            valid = false;
            if (result == 1) {
                valid = true;
            }
        } else {
            if (pc->attack(*ally, 0)) {
                cout << endl << "Your creature has died !" << endl;
                if (user.creaturesAlive()) {
                    ally = user.selectCreature();
                }
            }
            valid = false;
        }
    }
}