/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &filename) : Toy(WOODY, name, filename)
{
}


void Woody::speak(const std::string statement)
{
    std::cout << "WOODY: " << getName() << " \"" << statement << "\"" << std::endl;
}
