/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD08-albane.merian
** File description:
** Supply
*/

#include "Supply.hpp"


Supply::Supply(Types type, size_t amount)
    : _type(type), _amount(amount), _wrecks(nullptr), _currentIndex(0) {}


Supply::Supply(Types type, size_t amount, Droid** droids)
    : _type(type), _amount(amount), _wrecks(droids), _currentIndex(0) {}

Supply::~Supply() {
    if (_type == Wreck && _wrecks) {
        for (size_t i = 0; i < _amount; ++i) {
            delete _wrecks[i];
        }
        delete[] _wrecks;
    }
}

size_t Supply::getAmount() const {
    return _amount;
}

Supply::Types Supply::getType() const {
    return _type;
}

Supply::operator size_t() const {
    return _amount;
}

Droid** Supply::getWrecks() const {
    return _wrecks;
}


bool Supply::operator==(Types type) const {
    return _type == type;
}

bool Supply::operator!=(Types type) const {
    return _type != type;
}

Supply& Supply::operator++() {
    if (_type == Wreck && _wrecks) {
        _currentIndex = (_currentIndex + 1) % _amount;
    }
    return *this;
}

Supply& Supply::operator--() {
    if (_type == Wreck && _wrecks) {
        _currentIndex = (_currentIndex == 0) ? _amount - 1 : _currentIndex - 1;
    }
    return *this;
}

Droid*& Supply::operator*() const {
    if (_type == Wreck && _wrecks) {
        return _wrecks[_currentIndex];
    }
    // throw std::runtime_error("Dereference operation not valid for non-Wreck type");
}

Droid* Supply::operator->() const {
    return _wrecks ? _wrecks[_currentIndex] : nullptr;
}

Supply& Supply::operator!() {
    if (this->_type == Supply::Wreck) {
        for (size_t i = 0; i < this->_amount; i++) {
            if (this->_wrecks[i] != nullptr) {
                delete this->_wrecks[i];
                this->_wrecks[i] = nullptr;
            }
        }
    }
    this->_amount = 0;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Supply& supply) {
    os << "Supply : " << supply.getAmount() << ", ";
    switch (supply.getType()) {
        case Supply::Iron:
            os << "Iron";
            break;
        case Supply::Silicon:
            os << "Silicon";
            break;
        case Supply::Wreck:
            os << "Wreck";
            if (supply.getAmount() > 0) {
                for (size_t i = 0; i < supply.getAmount(); i++) {
                    // Droid* droid = supll
                    if (supply.getWrecks()[i] != nullptr)
                        os << "\n" << *supply.getWrecks()[i];
                }
            }
            break;
    }
    return os;
}
