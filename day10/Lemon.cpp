/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** Lemon
*/

#include "Lemon.hpp"

// Lemon::Lemon(const std::string& name, unsigned int vitamins, bool isPeeled, bool isPeelable) 
//  // : Fruit(vitamins, isPeeled, isPeelable)
// {
//     printf("Lemon name is %s\n", name.c_str());
// }

Lemon::Lemon()
{
    _name = "lemon";
    _vitamins = 4;
    _isPeeled = false;
}

Lemon::~Lemon()
{
}
