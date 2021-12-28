//
// Created by bkkami on 28.12.2021.
//

#include "CreaturesList.h"

#include <utility>

CreaturesList::CreaturesList() {
    list.emplace_back("Stomper", 3, 0.1, 15, hpBoost, earth);
    list.emplace_back("Fire spark", 7, 0.3, 8, attackBoost, fire);
}

CreaturesList::CreaturesList(std::vector<Creature> list) {
    this->list = std::move(list);
}

std::ostream &operator<<(std::ostream &o, const CreaturesList &c) {
    int counter = 0;
    o<<"   "<<"Name"<<" \t"<<"Attack"<<"\t"<<"Agility"<<"\t"<<"Health"<<"\t"<<"Element"<<"\t\t"<<"Special Move"<<std::endl;
    for (const auto& item : c.list) {
        counter++;
        o<<counter<<". "<<item.getName()<<"\t"<<item.getStrength()<<"\t"<<item.getAgility()<<"\t"<<item.getHp()<<"\t"<<item.getElement()<<"\t"<<item.getSpecialMove()<<std::endl;
    }
    return o;
}

Creature CreaturesList::getCopyCreature(int index, const CreaturesList& v) {
    return v.list[index-1];
}

Creature &CreaturesList::getCreature(int index, CreaturesList &v) {
    return v.list[index-1];
}

CreaturesList CreaturesList::makeUserSelection(const CreaturesList &list) {
    vector<Creature> result;

    int selection;

    for (int i = 6; i > 0; i--) {
        cout<<endl<<"Choose your Creatures. "<<i<<" to go"<<endl;
        cout<<"Select :";
        cin>>selection;
        result.push_back(getCopyCreature(selection, list));
    }
    cout<<endl;
    return result;
}

void CreaturesList::setDifficulty() {
    cout<<"Choose difficulty :"<<endl<<"1. Easy"<<endl<<"2. Medium"<<endl<<"3. Hard"<<endl;
    int level;
    cout<<endl<<"Select :";
    cin>>level;
    double mod = 1;
    switch (level) {
        case 1:
            mod = 1;
            break;
        case 2:
            mod = 1.3;
            break;
        case 3:
            mod = 1.5;
            break;
        default:
            break;
    }
    for (auto &item : this->list) {
        item.setHp(item.getHp()*mod);
        item.setAgility(item.getAgility()*mod);
        item.setStrength(item.getStrength()*mod);
    }
}
