/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Priest
*/

#include "Priest.hpp"
#include <iostream>

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }
    std::cout << getName() << " prays." << std::endl;
    setPower(100);
    setHp(100);
}
