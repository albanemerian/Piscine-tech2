/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** BorgQueen
*/

#include "BorgQueen.hpp"

Borg::BorgQueen::BorgQueen() {
    this->_movePtr = &Borg::Ship::move;
    this->_firePtr = &Borg::Ship::fire;
    this->_destroyPtr = &Borg::Ship::fire;
}

Borg::BorgQueen::~BorgQueen() {}

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
    return ((ship->*_movePtr)(dest));
}

void Borg::BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
{
    // std::cout << "On order from Borg Queen:" << std::endl;
    (ship->*_firePtr)(target);
}

void Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
    // std::cout << "On order from Borg Queen:" << std::endl;
    (ship->*_destroyPtr)(target);
}

