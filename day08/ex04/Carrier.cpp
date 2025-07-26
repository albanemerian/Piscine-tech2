/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD08-albane.merian
** File description:
** Carrier
*/

#include "Carrier.hpp"
#include "Droid.hpp"
#include <iostream>

Carrier::Carrier(std::string id)
    : id(id), energy(300), attack(100), toughness(90), speed(0) {
    for (int i = 0; i < 5; ++i) {
        droids[i] = nullptr;
    }
}

Carrier::~Carrier() {
    for (int i = 0; i < 5; ++i) {
        delete droids[i];
    }
}

std::string Carrier::getId() const {
    return id;
}

size_t Carrier::getEnergy() const {
    return energy;
}

size_t Carrier::getAttack() const {
    return attack;
}

size_t Carrier::getToughness() const {
    return toughness;
}

size_t Carrier::getSpeed() const {
    return speed;
}

void Carrier::setId(std::string id) {
    this->id = id;
}

void Carrier::setEnergy(size_t energy) {
    // if (energy < 0) {
    //     return;
    // }
    if (energy > 600)
        this->energy = 600;
    else if (energy <= 600)
        this->energy = energy;
}

void Carrier::setSpeed(size_t speed) {
    this->speed = speed;
}

Carrier& Carrier::operator<<(Droid* &droid) {
    for (int i = 0; i < 5; ++i) {
        if (droids[i] == nullptr) {
            droids[i] = droid;
            droid = nullptr;
            speed = 100 - 10 * (i + 1);
            return *this;
        }
    }
    return *this;
}

Carrier& Carrier::operator>>(Droid* &droid) {
    for (int i = 0; i < 5; ++i) {
        if (droids[i] != nullptr) {
            droid = droids[i];
            droids[i] = nullptr;
            int count = 0;
            for (int j = 0; j < 5; ++j) {
                if (droids[j] != nullptr) {
                    ++count;
                }
            }
            speed = (count == 0) ? 0 : 100 - 10 * count;
            return *this;
        }
    }
    return *this;
}

Droid* Carrier::operator[](size_t index) const {
    if (index < 5) {
        return droids[index];
    }
    return nullptr;
}

Droid*& Carrier::operator[](size_t index) {
    if (index < 5) {
        return droids[index];
    }
    static Droid* nullDroid = nullptr;
    return nullDroid;
}

Carrier& Carrier::operator~() {
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        if (droids[i] != nullptr) {
            ++count;
        }
    }
    speed = (count == 0) ? 0 : 100 - 10 * count;
    return *this;
}

bool Carrier::operator()(int x, int y) {
    int count = 0;

    for (int i = 0; i < 5; ++i) {
        if (droids[i] != nullptr) {
            ++count;
        }
    }
    size_t cost = (abs(x) + abs(y)) * (10 + count);
    if (speed == 0 || energy < cost) {
        return false;
    }
    energy -= cost;
    return true;
}

Carrier& Carrier::operator<<(size_t &energy) {
    size_t transfer = (600 - this->energy < energy) ? (600 - this->energy) : energy;
    this->energy += transfer;
    energy -= transfer;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Carrier& carrier) {
    os << "Carrier '" << carrier.getId() << "' Droid(s) on-board:\n";
    Droid* const* droids = carrier.getDroids();
    for (int i = 0; i < 5; ++i) {
        os << "[" << i << "] : ";
        if (droids[i] != nullptr) {
            os << *droids[i] << "\n";
        } else {
            os << "Free\n";
        }
    }
    os << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return os;
}


