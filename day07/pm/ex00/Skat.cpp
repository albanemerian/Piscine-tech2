/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks) : _name(name), _stimPaks(stimPaks) {}

Skat::~Skat() {}

int &Skat::stimPaks()
{
    return _stimPaks;
}

// void Skat::stimPaks(int number)
// {
//     _stimPaks = number;
// }

const std::string &Skat::name()
{
    return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number <= _stimPaks) {
        stock += number;
        _stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    } else
        std::cout << "Don't be greedy" << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    } else {
        _stimPaks += number;
    }
}

void Skat::useStimPaks()
{
    if (_stimPaks == 0)
        std::cout << "Mediiiiiic" << std::endl;
    else {
        _stimPaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}
