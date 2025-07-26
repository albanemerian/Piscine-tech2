/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** Admiral
*/

#include "Admiral.hpp"
#include "Federation.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name) : _name(name) {
    std::cout << "Admiral " << name << " ready for action." << std::endl;
    this->_firePtr = &Federation::Starfleet::Ship::fire;
    this->_movePtr = &Federation::Starfleet::Ship::move;
}

Federation::Starfleet::Admiral::~Admiral() {}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << _name << ":" << std::endl;
    (ship->*_firePtr)(target);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
{
    return ((ship->*_movePtr)(dest));
    // return true;
}
