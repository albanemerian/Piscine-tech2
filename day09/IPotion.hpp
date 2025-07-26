/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** IPotion
*/

#ifndef IPOTION_HPP_
#define IPOTION_HPP_

// #include "ICharacter.hpp"
class ICharacter; // Forward declaration

class IPotion {
    public:
        virtual ~IPotion() = default;
        virtual void drink(ICharacter &character) const = 0;
        virtual int getType() const = 0;
        //get type (const = 0)
};

#endif /* !IPOTION_HPP_ */
