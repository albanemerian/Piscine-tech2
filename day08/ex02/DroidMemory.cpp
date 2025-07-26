/*
** EPITECH PROJECT, 2025
** day8
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : fingerPrint(rand()), exp(0) {}

DroidMemory::~DroidMemory() {}

DroidMemory::DroidMemory(const DroidMemory &other)
{
    this->fingerPrint = other.fingerPrint;
    this->exp = other.exp;
}

size_t DroidMemory::getFingerPrint() const {
    return fingerPrint;
}

size_t DroidMemory::getExp() const {
    return exp;
}

void DroidMemory::setFingerPrint(size_t fingerPrint) {
    this->fingerPrint = fingerPrint;
}

void DroidMemory::setExp(size_t exp) {
    this->exp = exp;
}

DroidMemory& DroidMemory::operator<<(DroidMemory &other) {
    this->exp += other.exp;
    this->fingerPrint ^= other.fingerPrint;
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory &other) {
    other.exp += this->exp;
    other.fingerPrint ^= this->fingerPrint;
    return *this;
}

DroidMemory& DroidMemory::operator+=(const DroidMemory &other) {
    this->exp += other.exp;
    this->fingerPrint ^= other.fingerPrint;
    return *this;
}

DroidMemory& DroidMemory::operator+=(size_t exp) {
    this->exp += exp;
    this->fingerPrint ^= exp;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &other) const {
    DroidMemory result = *this;
    result += other;
    return result;
}

DroidMemory DroidMemory::operator+(size_t exp) const {
    DroidMemory result = *this;
    result += exp;
    return result;
}

bool DroidMemory::operator==(const DroidMemory &other) const {
    return this->exp == other.exp && this->fingerPrint == other.fingerPrint;
}

bool DroidMemory::operator!=(const DroidMemory &other) const {
    return !(*this == other);
}

bool DroidMemory::operator<(const DroidMemory &other) const {
    return this->exp < other.exp;
}

bool DroidMemory::operator>(const DroidMemory &other) const {
    return this->exp > other.exp;
}

bool DroidMemory::operator<=(const DroidMemory &other) const {
    return this->exp <= other.exp;
}

bool DroidMemory::operator>=(const DroidMemory &other) const {
    return this->exp >= other.exp;
}

std::ostream& operator<<(std::ostream& os, const DroidMemory& mem) {
    os << "DroidMemory '" << mem.getFingerPrint() << "', " << mem.getExp();
    return os;
}
