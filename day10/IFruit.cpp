/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** IFruit
*/

#include "IFruit.hpp"


std::ostream &operator<<(std::ostream &os, IFruit &fruit)
{
    os << "[name: '" << fruit.getName() << "', vitamins: " << fruit.getVitamins() << " peeled: " << fruit.isPeeled() << "]";
    return os;
}

std::ostream &operator<<(std::ostream &os, const IFruit &fruit)
{
    os << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", peeled: " << (fruit.isPeeled() ? "true" : "false") << "]";
    return os;
}
