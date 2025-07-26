/*
** EPITECH PROJECT, 2025
** day8
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial, size_t _energy, const size_t _attack, const size_t _toughness, std::string *_string)
 : id(serial), Energy(_energy), attack(_attack), toughness(_toughness), status(_string), BattleData (new DroidMemory())
{
    if (serial.empty()) {
        std::cout << "Droid should be given a name" << std::endl;
        exit(84);
    }
    std::cout << "Droid '" << id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &other)
 : id(other.id), Energy(other.Energy), attack(other.attack), toughness(other.toughness), status(new std::string(*other.status)), BattleData (new DroidMemory(*other.BattleData ))
{
    std::cout << "Droid '" << id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete status;
    delete BattleData ;
    std::cout << "Droid '" << id << "' Destroyed" << std::endl;
}


std::string Droid::getId() const
{
    return this->id;
}
 
size_t Droid::getEnergy() const
{
    return this->Energy;
}

size_t Droid::getAttack() const
{
    return this->attack;
}

size_t Droid::getToughness() const
{
    return this->toughness;
}

std::string *Droid::getStatus() const
{
    return this->status;
}




void Droid::setId(std::string id)
{
    this->id = id;
}

void Droid::setEnergy(size_t energy)
{
    // if (energy < 0) {
    //     return;
    // }
    if (energy > 100)
        this->Energy = 100;
    else if (energy <= 100)
        this->Energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->status = status;
}







Droid &Droid::operator<<(size_t &energy)
{
    size_t transfer = (100 - Energy < energy) ? (100 - Energy) : energy;
    Energy += transfer;
    energy -= transfer;
    return *this;
}

Droid& Droid::operator=(const Droid &other)
{
    if (this != &other) {
        this->id = other.id;
        this->Energy = other.Energy;
        delete this->status;
        this->status = new std::string(*other.status);
        delete this->BattleData ;
        this->BattleData  = new DroidMemory(*other.BattleData );
    }
    return *this;
}

DroidMemory* Droid::getBattleData() const {
    return this->BattleData ;
}

void Droid::setBattleData(DroidMemory* BattleData ) {
    this->BattleData  = BattleData ;
}

bool Droid::operator==(const Droid &droid) const
{
    return *this->status == *droid.status;
}

bool Droid::operator!=(const Droid &droid)  const
{
    return !(*this == droid);
}

std::ostream& operator<<(std::ostream& os, const Droid& d) {
    os << "Droid '" << d.getId() << "', " << *d.getStatus() << ", " << d.getEnergy();
    return os;
}
