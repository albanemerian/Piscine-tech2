/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << getName() << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() < 50) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    } else {
        setPower(getPower() - 50);
        std::cout << getName() << " casts a fireball." << std::endl;
        return 99;
    }
}

void Enchanter::rest()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }
    std::cout << getName() << " meditates." << std::endl;
    setPower(100);
}

// void Enchanter::damage(int damage)
// {
//     setHp(getHp() - damage);
//     if (getHp() <= 0) {
//         std::cout << getName() << " is out of combat." << std::endl;
//         setHp(0);
//     } else {
//         std::cout << getName() << " takes " << damage << " damage." << std::endl;
//     }
// }
