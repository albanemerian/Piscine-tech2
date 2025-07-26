/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** AFruit
*/

#include "AFruit.hpp"


AFruit::AFruit()
{
    // printf("AFruit name is \n");
}

AFruit::~AFruit()
{
}

unsigned int AFruit::getVitamins() const
{
    return (_isPeeled ? _vitamins : 0);
}

std::string AFruit::getName() const
{
    return _name;
}

void AFruit::peel()
{
    _isPeeled = true;
}

bool AFruit::isPeeled() const
{
    return _isPeeled;
}

IFruit *AFruit::clone() const
{
    AFruit *clones = new AFruit();

    clones->_name = _name;
    clones->_vitamins = _vitamins;
    clones->_isPeeled = _isPeeled;
    return clones;
}
