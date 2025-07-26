/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &filename) : Toy(BUZZ, name, filename)
{
}


void Buzz::speak(const std::string statement)
{
    std::cout << "BUZZ: " << getName() << " \"" << statement << "\"" << std::endl;
}
