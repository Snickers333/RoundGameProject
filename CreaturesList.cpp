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
