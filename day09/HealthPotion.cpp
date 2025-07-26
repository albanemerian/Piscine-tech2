/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** HealthPotion
*/

#include "HealthPotion.hpp"
#include "ICharacter.hpp"
#include <iostream>

// HealthPotion::HealthPotion()
// {
// }

// HealthPotion::~HealthPotion()
// {
// }

// bool HealthPotion::getDrink() const
// {
    
// }

int HealthPotion::getType() const
{
    return 1;
}

void HealthPotion::drink(ICharacter &character)  const {
    
    if (character.getHp() >= 100) {
        std::cout << character.getName() << " feels rejuvenated." << std::endl;
        return;
    }
    if (character.getHp() >= 50) {
        std::cout << character.getName() << " feels rejuvenated." << std::endl;
        character.setHp(100);
    } else {
        character.setHp(character.getHp() + 50);
        std::cout << character.getName() << " feels rejuvenated." << std::endl;
    }
}
