/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    _name = "toy";
    picture = "";
    _type = BASIC_TOY;
}

Toy::Toy(ToyType type, std::string name, std::string filename)
{
    _type = type;
    _name = name;
    Picture pic(filename);
    picture = pic.data;
}

Toy::~Toy()
{
}


std::string Toy::getName() const
{
    return _name;
}

std::string Toy::getAscii() const
{
    return picture;
}

Toy::ToyType Toy::getType() const
{
    return _type;
}


void Toy::setName(std::string name)
{
    _name = name;
}

void Toy::setAscii(std::string filename)
{
    Picture pic(filename);
    picture = pic.data;
}
