/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** HealthPotion
*/

#ifndef HEALTHPOTION_HPP_
#define HEALTHPOTION_HPP_

#include "IPotion.hpp"
// #include "ICharacter.hpp"

class HealthPotion : virtual public IPotion {
    public:
        HealthPotion() = default;
        ~HealthPotion() override = default;
        void drink(ICharacter &character) const;
        int getType() const;
};

#endif /* !HEALTHPOTION_HPP_ */
