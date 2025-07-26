/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** ACitrus
*/

#include "ACitrus.hpp"

ACitrus::ACitrus()
{
}

ACitrus::~ACitrus()
{
}

void ACitrus::peel()
{
    _isPeeled = true;
}

bool ACitrus::isPeeled() const
{
    return _isPeeled;
}

std::string ACitrus::getName() const
{
    return _name;
}

unsigned int ACitrus::getVitamins() const
{
    return (_isPeeled ? _vitamins : 0);
}

void ACitrus::setVitamins(unsigned int vitamins)
{
    // return vitamins;
    _vitamins = vitamins;
}

void ACitrus::setPeeled(bool isPeeled)
{
    // return isPeeled;
    _isPeeled = isPeeled;
}

IFruit *ACitrus::clone() const
{
    ACitrus *clones = new ACitrus();

    clones->_name = _name;
    clones->_vitamins = _vitamins;
    clones->_isPeeled = _isPeeled;
    return clones;
}
