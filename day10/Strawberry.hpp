/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** Strawberry
*/

#ifndef STRAWBERRY_HPP_
#define STRAWBERRY_HPP_

#include "ABerry.hpp"
#include <iostream>

class Strawberry : public ABerry {  // Must inherit from ABerry, not AFruit
public:
    Strawberry();
    ~Strawberry();
};

#endif /* !STRAWBERRY_HPP_ */
