/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy")
{
    _picture.data = "";
    _statement = "";
}


Toy::Toy(const Toy &other)
{
    _type = other._type;
    _name = other._name;
    _picture = other._picture;
}

Toy::Toy(ToyType type, std::string name, std::string filename) : _type(type), _name(name)
{
    _picture = Picture(filename);
}


Toy &Toy::operator=(const Toy &other)
{
    if (this != &other) {
        _type = other._type;
        _name = other._name;
        _picture = other._picture;
    }
    return *this;
}


std::string Toy::getName() const
{
    return _name;
}

std::string Toy::getAscii() const
{
    return _picture.data;
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
    _picture = Picture(filename);
}

void Toy::speak(std::string statement)
{
    _statement = statement;
    std::cout << getName() << " \"" << _statement << "\"" << std::endl;
}
