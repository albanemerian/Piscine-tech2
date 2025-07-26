/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** Parts
*/

#include "Parts.hpp"
#include <iostream>

// Parts() {}

// ~Parts() {}


//arms class function miaou
Arms::Arms(std::string serial, bool functionnal) : _serial(serial), _functionnal(functionnal) {}

Arms::~Arms() {}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}

bool Arms::isFunctionnal() const
{
    return _functionnal;
}

std::string Arms::serial() const
{
    return _serial;
}

//legs class fonction miaou
Legs::Legs(std::string serial, bool functionnal) : _serial(serial), _functionnal(functionnal) {}

Legs::~Legs() {}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}

bool Legs::isFunctionnal() const
{
    return _functionnal;
}

std::string Legs::serial() const
{
    return _serial;
}


//Heads function miaou
Head::Head(std::string serial, bool functionnal) : _serial(serial), _functionnal(functionnal) {}

Head::~Head() {}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}

bool Head::isFunctionnal() const
{
    return _functionnal;
}

std::string Head::serial() const
{
    return _serial;
}
