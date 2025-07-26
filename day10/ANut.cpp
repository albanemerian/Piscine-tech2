/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** ANut
*/

#include "ANut.hpp"

ANut::ANut()
{
}

ANut::~ANut()
{
}

void ANut::peel()
{
    _isPeeled = true;
}

bool ANut::isPeeled() const
{
    return _isPeeled;
}

std::string ANut::getName() const
{
    return _name;
}

unsigned int ANut::getVitamins() const
{
    return (_isPeeled ? _vitamins : 0);
}


void ANut::setVitamins(unsigned int vitamins)
{
    _vitamins = vitamins;
}

void ANut::setPeeled(bool isPeeled)
{
    _isPeeled = isPeeled;
}

IFruit *ANut::clone() const
{
    ANut *clones = new ANut();

    clones->_name = _name;
    clones->_vitamins = _vitamins;
    clones->_isPeeled = _isPeeled;
    return clones;
}
