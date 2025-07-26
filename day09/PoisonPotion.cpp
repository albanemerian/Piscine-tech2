/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** PoisonPotion
*/

#include "ICharacter.hpp"
#include "PoisonPotion.hpp"
#include <iostream>

// PoisonPotion::PoisonPotion()
// {
// }

// PoisonPotion::~PoisonPotion()
// {
// }

int PoisonPotion::getType() const
{
    return 3;
}

void PoisonPotion::drink(ICharacter &character) const {

    if (character.getHp() <= 50 || character.getHp() <= 0) {
        std::cout << character.getName() << " has been poisoned." << std::endl;
        character.setHp(0);
        return;
    }
    character.setHp(character.getHp() - 50);
    std::cout << character.getName() << " has been poisoned." << std::endl;
}
