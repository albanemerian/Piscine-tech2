/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** PowerPotion
*/

#include "PowerPotion.hpp"
#include "ICharacter.hpp"
#include <iostream>

// PowerPotion::PowerPotion()
// {
// // }

// PowerPotion::~PowerPotion()
// {
// }

int PowerPotion::getType() const
{
    return 2;
}

void PowerPotion::drink(ICharacter &character) const {

    if (character.getPower() >= 50) {
        std::cout << character.getName() << "'s power is restored." << std::endl;
        character.setPower(100);
        return;
    }
    character.setPower(character.getPower() + 50);
    std::cout << character.getName() << "'s power is restored." << std::endl;
}

