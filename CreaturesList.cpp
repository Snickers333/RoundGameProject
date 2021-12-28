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
    for (auto item : c.list) {
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
