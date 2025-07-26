/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** PoisonPotion
*/

#ifndef POISONPOTION_HPP_
#define POISONPOTION_HPP_

#include "IPotion.hpp"
// #include "ICharacter.hpp"

class PoisonPotion : virtual public IPotion {
    public:
    //     PoisonPotion() = default;
    //     ~PoisonPotion() override = default;
        // void drink(ICharacter &character) const;
        void drink(ICharacter& potion) const;
        int getType() const;
};

#endif /* !POISONPOTION_HPP_ */
