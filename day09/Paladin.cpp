/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Paladin
*/

#include "Paladin.hpp"
#include "Knight.hpp"
#include "Priest.hpp"
#include "Peasant.hpp"
#include <iostream>

Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    std::cout << name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << this->Knight::name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return this->Knight::attack();
}

int Paladin::special()
{
    return this->Enchanter::special();
}

void Paladin::rest()
{
    this->Priest::rest();
}


// void Paladin::damage(int damage)
// {
//     this->Knight::damage(damage);
// }
