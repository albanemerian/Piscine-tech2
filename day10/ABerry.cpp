/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** ABerry
*/

#include "ABerry.hpp"
#include <iostream>
#include "AFruit.hpp"

ABerry::ABerry()
{
    _isPeeled = true;
}


ABerry::~ABerry()
{
}


void ABerry::setVitamins(unsigned int vitamins)
{
    _vitamins = vitamins;
}

std::string ABerry::getName() const
{
    return _name;
}

unsigned int ABerry::getVitamins() const
{
    return _vitamins;
}

IFruit *ABerry::clone() const
{
    ABerry *clones = new ABerry();

    clones->_name = _name;
    clones->_vitamins = _vitamins;
    clones->_isPeeled = _isPeeled;
    return clones;
}
