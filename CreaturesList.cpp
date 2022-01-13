//
// Created by bkkami on 28.12.2021.
//

#include "CreaturesList.h"
#include <utility>

// Default constructor creates list of available creatures and stores them in vector
CreaturesList::CreaturesList() {
    list.emplace_back("Stomper", 3, 10, 18, hpBoost, earth);
    list.emplace_back("Fire spark", 7, 20, 9, attackBoost, fire);
    list.emplace_back("Angry Fish", 4, 10, 13, xpBoost, water);
    list.emplace_back("FastRunner", 5, 50, 6, tornado, wind);
    list.emplace_back("Ice Wolf", 6, 30, 13, exhaust, ice);
    list.emplace_back("Iron Golem", 4, 10, 16, laserBeam, steel);
    list.emplace_back("Blaze  ", 5, 20, 11, ignite, fire);
    list.emplace_back("Wind Bat", 5, 40, 9, agilityBoost, wind);
    list.emplace_back("IceMonster", 6, 20, 10, laserBeam, ice);
    list.emplace_back("Squid Arc", 5, 30, 10, hpBoost, water);
    list.emplace_back("Dirt Lord", 3, 10, 15, exhaust, earth);
    list.emplace_back("Magma Cube", 12, 10, 7, agilityBoost, fire);
    list.emplace_back("Qck Silver", 2, 20, 11, xpBoost, steel);
    list.emplace_back("Freezer", 5, 10, 13, exhaust, ice);
    list.emplace_back("Swinger", 4, 20, 15, attackBoost, wind);
}

// Constructor that assigns existing Creatures vector to the field of this class
CreaturesList::CreaturesList(std::vector<Creature> list) {
    this->list = std::move(list);
}

// Overloading output stream operator to list every Creature stored in this class
std::ostream &operator<<(std::ostream &o, const CreaturesList &c) {
    int counter = 0;
    o << "    " << "Name" << " \t" << "Attack" << "\t" << "Agility" << "\t" << "Health" << "\t" << "Element" << "\t\t"
      << "Special Move" << std::endl;
    for (const auto &item: c.list) {
        counter++;
        if (counter > 9) {
            o << counter << "." << item;
        } else {
            o << counter << ". " << item;
        }
    }
    return o;
}

// Method that makes a copy of existing creature stored at given index in vector
Creature CreaturesList::getCopyCreature(int index) const {
    return list[index - 1];
}

// This method helps user to select his initial creatures list at beginning of the game
CreaturesList CreaturesList::makeUserSelection() const {
    vector<Creature> result;
    int selection;
    while (result.size() < 6) {
        cout << "\t\t\t\tWelcome to the Game!" << endl << endl << "List of available Creatures :" << endl
             << endl;
        cout<<this->list<<endl;
        cout << endl << "\t\t\t\tChoose your Creatures. " << 6 - result.size() << " to go" << endl;
        cout << "\t\t\t\t\tSelect :";
        cin >> selection;
        if (selection > 0 && selection < 16) {
            result.push_back(getCopyCreature(selection));
        } else {
            cout<<endl<<"Incorrect choice, try again"<<endl;
        }
        system("CLS");
    }
    return result;
}

// Method that helps user to select the difficulty of enemy Creatures for the rest of the game
void CreaturesList::setDifficulty() {
    cout << "\t\t\t\tChoose difficulty :" << endl << "\t\t\t\t\t1. Easy" << endl << "\t\t\t\t\t2. Medium" << endl
         << "\t\t\t\t\t3. Hard" << endl;
    int level;
    cout << "\t\t\t\t\tSelect :";
    cin >> level;
    double mod = 1;
    system("CLS");
    switch (level) {
        case 1:
            mod = 1;
            cout << "\t\t\t\tSelected difficulty EASY" << endl << endl;
            break;
        case 2:
            mod = 1.3;
            cout << "\t\t\t\tSelected difficulty MEDIUM" << endl << endl;
            break;
        case 3:
            mod = 1.5;
            cout << "\t\t\t\tSelected difficulty HARD" << endl << endl;
            break;
        default:
            break;
    }
    for (auto &item: this->list) {
        item.setHp(item.getHp() * mod);
        if (item.getElement() != wind) {
            item.setAgility(item.getAgility() * mod);
        }
        item.setStrength(item.getStrength() * mod);
    }
}

// This method returns a CreatureList of random picked enemies from the default list
CreaturesList CreaturesList::selectRandomEnemyList() const {
    vector<Creature> result;
    int selection;
    srand((unsigned) time(0));
    for (int i = 0; i < 4; i++) {
        selection = (rand() % 15) + 1;
        result.push_back(getCopyCreature(selection));
    }
    return result;
}

// This method allows user to select currently controlled Creature
Creature *CreaturesList::selectCreature() {
    int choice;
    do {
        cout << endl << this->list << endl;
        cout << "\t\t\t\tPick your fighter :";
        cin >> choice;
        if (choice < 1 || choice > 6){
            system("CLS");
            cout << "Incorrect choice" << endl;
        } else if (list[choice - 1].getHp() <= 0) {
            system("CLS");
            cout << "Incorrect choice, this creature is already dead." << endl;
        }
    } while ((choice < 1 || choice > 6) || list[choice - 1].getHp() <= 0);
    system("CLS");
    return &list[choice - 1];
}

// This method selects another Creature controlled by the Computer
Creature *CreaturesList::selectCreaturePC() {
    for (int i = 0; i < 4; ++i) {
        if (list[i].alive()) {
            return &list[i];
        }
    }
    cout << endl << " Your enemy changed his creature ! " << endl;
    return &list[0];
}

// Method that checks if any of the enemies in the list is still alive
bool CreaturesList::creaturesAlive() {
    bool alive = false;
    for (const auto &item: list) {
        if (item.getHp() > 0) {
            alive = true;
        }
    }
    return alive;
}

// This method prints out currently selected Creatures by user and Enemy
void CreaturesList::showCurrent(const CreaturesList &user, const CreaturesList &enemy) {
    cout << "\t\t\t\t\tYour team :" << endl << endl;
    cout << user << endl;
    cout << "\t\t\t\t\tYour Nemesis :" << endl << endl;
    cout << enemy << endl;
}

// Method that saves the current game progress
void CreaturesList::saveGame(int round) const {
    ofstream saveState("savefile.txt");
    for (auto const &c: this->list) {
        saveState << c.getName() << "\n" << c.getStrength() << "\n" << c.getAgility() << "\n" << c.getHp() << "\n"
                  << c.getSpecialMove().getSpecialString() << "\n" << c.getElement() << "\n";
    }
    saveState << round;
    saveState.close();
}

// Method that loads current game progress
int CreaturesList::readGame() {
    ifstream file("savefile.txt");
    string read;
    this->list.clear();
    string name;
    int dmg;
    int agility;
    int hp;
    Special special;
    Element element;
    if (file.is_open()) {
        for (int i = 0; i < 6; ++i) {
            getline(file, read);
            name = read;
            getline(file, read);
            dmg = stoi(read);
            getline(file, read);
            agility = stoi(read);
            getline(file, read);
            hp = stoi(read);
            getline(file, read);
            special = SpecialMove::getSpecialIndex(read);
            getline(file, read);
            element = Creature::getElementIndex(read);
            this->list.emplace_back(name, dmg, agility, hp, special, element);
        }
    }
    getline(file, read);
    return stoi(read);
}

// Method that refreshes all Creatures Special ability cooldown every round
void CreaturesList::refreshCooldowns() {
    for (auto &item: this->list) {
        item.setCooldown(false);
    }
    cout << endl << "New round ! Abilities cooldowns has been reset !" << endl;
}

