/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** Federation
*/

#include "Federation.hpp"
#include "Borg.hpp"
#include <iostream>


Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
    : _length(length), _width(width), _name(name), _maxWarp(maxWarp), _core(nullptr), _home(EARTH), _shield(100), _photonTorpedo(torpedo) {
    _location = _home;
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
    if (torpedo > 0) {
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
    }
}

Federation::Starfleet::Ship::~Ship() {}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore() {
    std::cout << "USS " << _name << ": The core is " 
              << (_core->checkReactor()->isStable() ? "stable" : "unstable") 
              << " at the time." << std::endl;
}

WarpSystem::Core *Federation::Starfleet::Ship::getCore() {
    return _core;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    _location = d;
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
        return true;
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    _location = _home;
    if (warp <= _maxWarp && _core->checkReactor()->isStable())
        return true;
    return false; 
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    _location = d;
    if (d != _location && _core->checkReactor()->isStable())
        return true;
    return false;
}

bool Federation::Starfleet::Ship::move()
{
    _location = _home;
    if (_core->checkReactor()->isStable())
        return true;
    return false; 
}

Federation::Starfleet::Captain::Captain(std::string name) : _name(name) {}

Federation::Starfleet::Captain::~Captain() {}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain->getName();
    std::cout << _captain << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;    
}

std::string Federation::Starfleet::Captain::getName() {
    return _name;
}

int Federation::Starfleet::Captain::getAge() {
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age) {
    _age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign() {}

int Federation::Starfleet::Ship::getShield()
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *ship)
{
    if (1 > _photonTorpedo) {
        std::cout << _name << ": No more torpedo to fire, " << _captain << "!" << std::endl;
        return;
    }
    _photonTorpedo -= 1;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    ship->setShield(ship->getShield() - 50);
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedo to fire, " << _captain << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *ship)
{
    if (torpedoes > _photonTorpedo) {
        std::cout << _name << ": No more torpedo to fire, " << _captain << "!" << std::endl;
        return;
    }
    _photonTorpedo -= torpedoes;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    ship->setShield(ship->getShield() - 50 * torpedoes);
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedo to fire, " << _captain << "!" << std::endl;
}

//ships
Federation::Ship::Ship(int length, int width, std::string name) 
    : _length(length), _width(width), _name(name), _maxWarp(1), _core(nullptr), _home(VULCAN) {
    _location = _home;
    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship() {}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore() {

    std::cout << _name << ": The core is " 
              << (_core->checkReactor()->isStable() ? "stable" : "unstable") 
              << " at the time." << std::endl;
}

WarpSystem::Core *Federation::Ship::getCore() {
    return _core;
}

bool Federation::Ship::move(int warp, Destination d)
{
    _location = d;
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
        return true;
    return false;
}

bool Federation::Ship::move(int warp)
{
    _location = _home;
    if (warp <= _maxWarp && _core->checkReactor()->isStable())
        return true;
    return false; 
}

bool Federation::Ship::move(Destination d)
{
    _location = d;
    if (d != _location && _core->checkReactor()->isStable())
        return true;
    return false;
}

bool Federation::Ship::move()
{
    _location = _home;
    if (_core->checkReactor()->isStable())
        return true;
    return false; 
}

// Federation::Starfleet::Admiral::Admiral(std::string name) : _name(name) {
//     std::cout << "Admiral " << name << " ready for action." << std::endl;
//     movePtr = &Federation::Starfleet::Ship::move;
//     firePtr = &Federation::Starfleet::Ship::fire;
// }
