/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Knight
*/

#include "Peasant.hpp"
#include "Knight.hpp"
#include <iostream>

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    // printf("in knight destructor\n");
    std::cout << name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() < 10) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    } else {
        setPower(getPower() - 10);
        std::cout << getName() << " strikes with his sword." << std::endl;
        return 20;
    }
}

int Knight::special()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() < 30) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    } else {
        setPower(getPower() - 30);
        std::cout << getName() << " impales his enemy." << std::endl;
        return 50;
    }
}

void Knight::rest()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }
    std::cout << getName() << " eats." << std::endl;
    setPower(getPower() + 50);
}

// void Knight::damage(int damage)
// {
//     setHp(getHp() - damage);
//     if (getHp() <= 0) {
//         std::cout << getName() << " is out of combat." << std::endl;
//         setHp(0);
//     } else {
//         std::cout << getName() << " takes " << damage << " damage." << std::endl;
//     }
// }
