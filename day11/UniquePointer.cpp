/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** UniquePointer
*/

#include "UniquePointer.hpp"
#include "IObject.hpp"
#include <iostream>


UniquePointer::UniquePointer() : ptr(nullptr) {}

UniquePointer::UniquePointer(IObject* object) : ptr(object) {} // Non-explicit constructor

// UniquePointer::UniquePointer(IObject* object, bool explicitFlag) : ptr(object) {} // Explicit constructor

UniquePointer::~UniquePointer()
{
    delete ptr;
}

UniquePointer::UniquePointer(UniquePointer&& other) noexcept : ptr(other.ptr)
{
    other.ptr = nullptr;
}

UniquePointer &UniquePointer::operator=(UniquePointer&& other) noexcept
{
    if (this != &other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

UniquePointer &UniquePointer::operator=(IObject *object)
{
    if (ptr != object) {
        delete ptr;
        ptr = object;
    }
    return *this;
}

IObject *UniquePointer::operator->() const
{
    return ptr;
}

IObject &UniquePointer::operator*() const
{
    return *ptr;
}

void UniquePointer::reset(IObject *object)
{
    if (ptr != object) {
        delete ptr;
        ptr = object;
    }
}

void UniquePointer::swap(UniquePointer &other) noexcept
{
    std::swap(ptr, other.ptr);
}

bool UniquePointer::isValid() const
{
    return ptr != nullptr;
}
