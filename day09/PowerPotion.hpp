/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** PowerPotion
*/

#ifndef POWERPOTION_HPP_
#define POWERPOTION_HPP_

#include "IPotion.hpp"
// #include "ICharacter.hpp"

class PowerPotion : virtual public IPotion {
    public:
        // PowerPotion() = default;
        // ~PowerPotion() override = default;
        void drink(ICharacter &character) const;
        int getType() const;
};

#endif /* !POWERPOTION_HPP_ */
