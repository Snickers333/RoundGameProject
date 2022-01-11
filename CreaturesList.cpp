//
// Created by bkkami on 28.12.2021.
//

#include "CreaturesList.h"

#include <utility>

CreaturesList::CreaturesList() {
    list.emplace_back("Stomper", 3, 0.1, 18, hpBoost, earth);
    list.emplace_back("Fire spark", 7, 0.2, 9, attackBoost, fire);
    list.emplace_back("Angry Fish", 4, 0.1, 13, xpBoost, water);
    list.emplace_back("FastRunner", 5, 0.5, 6, tornado, wind);
    list.emplace_back("Ice Wolf", 6, 0.3, 13, exhaust, ice);
    list.emplace_back("Iron Golem", 4, 0.1, 16, laserBeam, steel);
    list.emplace_back("Blaze  ", 5, 0.2, 11, ignite, fire);
    list.emplace_back("Wind Bat", 5, 0.4, 9, agilityBoost, wind);
    list.emplace_back("IceMonster", 6, 0.2, 10, laserBeam, ice);
    list.emplace_back("Squid Arc", 5, 0.3, 10, hpBoost, water);
    list.emplace_back("Dirt Lord", 3, 0.1, 15, exhaust, earth);
    list.emplace_back("Magma Cube", 12, 0.1, 7, agilityBoost, fire);
    list.emplace_back("Qck Silver", 2, 0.2, 11, xpBoost, steel);
    list.emplace_back("Freezer", 5, 0.1, 13, exhaust, ice);
    list.emplace_back("Swinger", 4, 0.2, 15, attackBoost, wind);
}

CreaturesList::CreaturesList(std::vector<Creature> list) {
    this->list = std::move(list);
}

std::ostream &operator<<(std::ostream &o, const CreaturesList &c) {
    int counter = 0;
    o<<"    "<<"Name"<<" \t"<<"Attack"<<"\t"<<"Agility"<<"\t"<<"Health"<<"\t"<<"Element"<<"\t\t"<<"Special Move"<<std::endl;
    for (const auto& item : c.list) {
        counter++;
        if (counter > 9) {
            o<<counter<<"."<<item;
        } else {
            o<<counter<<". "<<item;
        }
    }
    return o;
}

Creature CreaturesList::getCopyCreature(int index) const{
    return list[index-1];
}

CreaturesList CreaturesList::makeUserSelection() const{
    vector<Creature> result;

    int selection;

    for (int i = 6; i > 0; i--) {
        cout<<endl<<"\t\t\t\tChoose your Creatures. "<<i<<" to go"<<endl;
        cout<<"\t\t\t\t\tSelect :";
        cin>>selection;
        result.push_back(getCopyCreature(selection));
    }
    cout<<endl;
    return result;
}

void CreaturesList::setDifficulty() {
    cout<<"\t\t\t\tChoose difficulty :"<<endl<<"\t\t\t\t\t1. Easy"<<endl<<"\t\t\t\t\t2. Medium"<<endl<<"\t\t\t\t\t3. Hard"<<endl;
    int level;
    cout<<"\t\t\t\t\tSelect :";
    cin>>level;
    double mod = 1;
    switch (level) {
        case 1:
            mod = 1;
            cout<<endl<<"\t\t\t\t    Selected difficulty EASY"<<endl<<endl;
            break;
        case 2:
            mod = 1.3;
            cout<<endl<<"\t\t\t\t    Selected difficulty MEDIUM"<<endl<<endl;
            break;
        case 3:
            mod = 1.5;
            cout<<endl<<"\t\t\t\t    Selected difficulty HARD"<<endl<<endl;
            break;
        default:
            break;
    }
    for (auto &item : this->list) {
        item.setHp(item.getHp()*mod);
        if (item.getElement() != wind) {
            item.setAgility(item.getAgility()*mod);
        }
        item.setStrength(item.getStrength()*mod);
    }
}

CreaturesList CreaturesList::selectRandomEnemies() const{
    vector<Creature> result;
    int selection;
    srand((unsigned) time(0));
    for (int i = 0; i < 4; i++) {
        selection = (rand() % 15) + 1;
        result.push_back(getCopyCreature(selection));
    }
    return result;
}

Creature * CreaturesList::selectCreature() {
    bool player = playerOrPc();
    int choice;
    do {
        if (player) {
            cout << endl << this->list << endl;
            cout << "\t\t\t\tPick your fighter :";
            cin >> choice;
            cout << endl << "\t\t\t\tYou have chosen :" << endl << endl;
            cout << " Name" << " \t\t" << "Attack" << "\t" << "Agility" << "\t" << "Health" << "\t" << "Element"
                 << "\t\t" << "Special Move" << endl;
            cout << list[choice - 1] << endl;
        } else {
            srand((unsigned) time(0));
            choice = (rand() % 4) + 1;
        }
    } while (list[choice-1].getHp() < 0);
    return &list[choice-1];
}

bool CreaturesList::playerOrPc() {
    int counter = 0;
    for (auto item : list) {
        counter++;
    }
    if (counter == 6) {
        return true;
    } else {
        return false;
    }
}

bool CreaturesList::creaturesAlive() {
    bool alive = false;
    for (const auto& item : list) {
        if (item.getHp() > 0) {
            alive = true;
        }
    }
    return alive;
}

void CreaturesList::showCurrent(CreaturesList user, CreaturesList enemy) {
    cout<<endl<<"\t\t\t\t\tYour team :"<<endl<<endl;
    cout<<user<<endl;
    cout<<"\t\t\t\t\tYour Nemesis :"<<endl<<endl;
    cout<<enemy<<endl;
}
