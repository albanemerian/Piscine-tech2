/*
** EPITECH PROJECT, 2025
** day8
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : Fingerprint(rand()), exp(0) {}

DroidMemory::~DroidMemory() {}

size_t DroidMemory::getFingerprint() const {
    return Fingerprint;
}

size_t DroidMemory::getExp() const {
    return exp;
}

void DroidMemory::setFingerprint(size_t Fingerprint) {
    this->Fingerprint = Fingerprint;
}

void DroidMemory::setExp(size_t exp) {
    this->exp = exp;
}

DroidMemory& DroidMemory::operator<<(DroidMemory &other) {
    this->exp += other.exp;
    this->Fingerprint ^= other.Fingerprint;
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory &other) {
    other.exp += this->exp;
    other.Fingerprint ^= this->Fingerprint;
    return *this;
}

DroidMemory& DroidMemory::operator+=(const DroidMemory &other) {
    this->exp += other.exp;
    this->Fingerprint ^= other.Fingerprint;
    return *this;
}

DroidMemory& DroidMemory::operator+=(size_t exp) {
    this->exp += exp;
    this->Fingerprint ^= exp;
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

std::ostream& operator<<(std::ostream& os, const DroidMemory& mem) {
    os << "DroidMemory '" << mem.getFingerprint() << "', " << mem.getExp();
    return os;
}
