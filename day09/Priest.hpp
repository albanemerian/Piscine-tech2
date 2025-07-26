/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"
#include <iostream>

class Priest : virtual public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();

        void rest();
    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
