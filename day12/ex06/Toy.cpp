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

bool Toy::setAscii(std::string filename)
{
    std::ifstream imageFile(filename);
    if (!imageFile.is_open()) {
        _lastError.type = Error::PICTURE;
        return false;
    }
    _picture = Picture(filename);
    return true;
}

bool Toy::speak(std::string statement)
{
    _statement = statement;
    std::cout << getName() << " \"" << _statement << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(std::string statement)
{
    (void)statement;
    _statement = "";
    _lastError.type = Error::SPEAK;
    return false;
}

Toy &Toy::operator<<(std::string const &str)
{
    _picture.data = str;
    return *this;
}

Toy::Error Toy::getLastError()
{
    return _lastError;
}

std::string Toy::Error::where() const
{
    switch (type) {
        case PICTURE:
            return "setAscii";
        case SPEAK:
            return "speak_es";
        case UNKNOWN:
        default:
            return "";
    }
}

std::string Toy::Error::what() const
{
    std::string msg = "";

    if (where() == "speak_es") {
        // type = SPEAK;
        msg = "wrong mode";
        return msg.c_str();
    }
    if (where() == "setAscii") {
        // type = PICTURE;
        msg = "bad new illustration";
        return msg.c_str();
    }
    // type = UNKNOWN;
    msg = "";
    return msg.c_str();
}


std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    return os << toy.getName() << std::endl << toy.getAscii() << std::endl;
}
