/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : virtual public Knight, virtual public Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();

        int attack();
        int special();
        void rest();
        // void damage(int damage);
        // int attack() : Knight::attack();
        // int special() : Enchanter::special();
        // int rest() : Priest::rest();
    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
