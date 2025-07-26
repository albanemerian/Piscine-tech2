/*
** EPITECH PROJECT, 2025
** day8
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial, size_t _energy, const size_t _attack, const size_t _toughness, std::string *_string)
 : id(serial), energy(_energy), attack(_attack), toughness(_toughness), status(_string), battleData(new DroidMemory())
{
    if (serial.empty()) {
        std::cout << "Droid should be given a name" << std::endl;
        exit(84);
    }
    std::cout << "Droid '" << id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &other)
 : id(other.id), energy(50), attack(other.attack), toughness(other.toughness), status(new std::string(*other.status)), battleData(new DroidMemory(*other.battleData))
{
    std::cout << "Droid '" << id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete status;
    delete battleData;
    std::cout << "Droid '" << id << "' Destroyed" << std::endl;
}

Droid& Droid::operator=(const Droid &other)
{
    if (this != &other) {
        this->id = other.id;
        this->energy = 50;
        delete this->status;
        this->status = new std::string(*other.status);
        delete this->battleData;
        this->battleData = new DroidMemory(*other.battleData);
    }
    return *this;
}

DroidMemory* Droid::getBattleData() const {
    return this->battleData;
}

void Droid::setBattleData(DroidMemory* battleData) {
    this->battleData = battleData;
}

bool Droid::operator==(const Droid &droid) const
{
    return *this->status == *droid.status;
}

bool Droid::operator!=(const Droid &droid)  const
{
    return !(*this == droid);
}

bool Droid::operator()(const std::string *task, size_t exp)
{
    if (this->energy <= 10) {
        this->energy = 0;
        *this->status = "Battery Low";
        return false;
    }
    this->energy -= 10;
    if (this->battleData->getExp() >= exp) {
        this->battleData->setExp(this->battleData->getExp() + exp / 2);
        *this->status = *task + " - Completed!";
        return true;
    } else {
        this->battleData->setExp(this->battleData->getExp() + exp);
        *this->status = *task + " - Failed!";
        return false;
    }
}

std::string Droid::getId() const
{
    return this->id;
}
 
size_t Droid::getEnergy() const
{
    return this->energy;
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
    this->energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->status = status;
}


void Droid::operator<<(size_t &energy)
{
    size_t needed = 100 - this->energy;

    if (energy >= needed) {
        this->energy = 100;
        energy -= needed;
    } else {
        this->energy += energy;
        energy = 0;
    }
}

// bool Droid::operator==(const Droid &droid) const
// {
//     if (this->id == droid.id && this->energy == droid.energy &&
//         this->attack == droid.attack && this->toughness == droid.toughness
//         && *this->status == *droid.status)
//         return true;
//     else 
//         return false;
// }

// bool Droid::operator!=(const Droid &droid)  const
// {
//     return !(*this == droid);
// }

std::ostream& operator<<(std::ostream& os, const Droid& d) {
    os << "Droid '" << d.getId() << "', " << *d.getStatus() << ", " << d.getEnergy();
    return os;
}

