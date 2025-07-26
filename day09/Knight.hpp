/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include <iostream>
#include "Peasant.hpp"
#include "ICharacter.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();

        int attack() override;
        int special() override;
        void rest() override;
        // void damage(int damage) override;
};

#endif /* !KNIGHT_HPP_ */
