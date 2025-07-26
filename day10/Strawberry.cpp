/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** Strawberry
*/

#include "Strawberry.hpp"

Strawberry::Strawberry() : ABerry()  // Properly initialize base class
{
    _name = "strawberry";
    _vitamins = 6;
    _isPeeled = true;
}

Strawberry::~Strawberry()
{
}
