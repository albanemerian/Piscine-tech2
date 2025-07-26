/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

#include <iostream>
#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();

        int attack() override;
        int special() override;
        void rest() override;
        // void damage(int damage) override;
    // protected:
    // private:
};

#endif /* !ENCHANTER_HPP_ */
