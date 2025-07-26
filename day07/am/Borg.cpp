/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** Borg
*/

#include "Federation.hpp"
#include "Borg.hpp"
#include "WarpSystem.hpp"
#include <iostream>

Borg::Ship::Ship(int weaponFrequency, short repair) 
    : _side(300), _maxWarp(9), _home(UNICOMPLEX), _shield(100), _weaponFrequency(weaponFrequency), _repair(repair) {
    _location = _home;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship() {}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore()
{
    std::cout << (_core->checkReactor()->isStable() ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    _location = d;
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
        return true;
    return false;
}

bool Borg::Ship::move(int warp)
{
    _location = _home;
    if (warp <= _maxWarp && _core->checkReactor()->isStable())
        return true;
    return false; 
}

bool Borg::Ship::move(Destination d)
{
    _location = d;
    if (d != _location && _core->checkReactor()->isStable())
        return true;
    return false;
}

bool Borg::Ship::move()
{
    _location = _home;
    if (_core->checkReactor()->isStable())
        return true;
    return false; 
}

int Borg::Ship::getShield()
{
    return _shield;
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return _weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return _repair;
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    target->setShield(target->getShield() - _weaponFrequency);
}

void Borg::Ship::fire(Federation::Ship *target)
{
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    target->getCore()->checkReactor()->setStability(false);
}

void Borg::Ship::repair()
{
    if (_repair > 0) {
        _repair--;
        _shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    } else {
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    }
}
