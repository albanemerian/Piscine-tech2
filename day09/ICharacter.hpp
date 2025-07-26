/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <iostream>
#include "IPotion.hpp"
#include "HealthPotion.hpp"
#include "PowerPotion.hpp"
#include "PoisonPotion.hpp"

class ICharacter {
    public:
        // ICharacter() = default;
        virtual ~ICharacter() = default;  // Make destructor virtual
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual void setPower(int power) = 0;
        virtual void setHp(int hp) = 0;

        virtual const std::string &getName() const = 0;

        virtual void drink(const PowerPotion& potion) = 0;
        virtual void drink(const PoisonPotion& potion) = 0;
        virtual void drink(const HealthPotion& potion) = 0;
        virtual void drink(const IPotion& potion) = 0;

};

#endif /* !ICHARACTER_HPP_ */
