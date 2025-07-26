/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** SharedPointer
*/

#include "SharedPointer.hpp"

SharedPointer::SharedPointer() : ptr(nullptr), ref_count(new unsigned int(0)) {}

SharedPointer::SharedPointer(IObject* object) : ptr(object), ref_count(new unsigned int(1)) {} // Non-explicit constructor

SharedPointer::SharedPointer(const SharedPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
    // ++(*ref_count);
    if (ptr)
        ++(*ref_count);
}

SharedPointer::SharedPointer(SharedPointer&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count) {
    other.ptr = nullptr;
    other.ref_count = nullptr;
}

SharedPointer::~SharedPointer() {
    release();
}

SharedPointer& SharedPointer::operator=(const SharedPointer& other) {
    if (this != &other) {
        release();
        ptr = other.ptr;
        ref_count = other.ref_count;
        ++(*ref_count);
    }
    return *this;
}

SharedPointer& SharedPointer::operator=(SharedPointer&& other) noexcept {
    if (this != &other) {
        release();
        ptr = other.ptr;
        ref_count = other.ref_count;
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }
    return *this;
}

SharedPointer& SharedPointer::operator=(IObject* object) {
    if (ptr != object) {
        release();
        ptr = object;
        ref_count = new unsigned int(1);
    }
    return *this;
}

IObject* SharedPointer::operator->() const {
    return ptr;
}

IObject& SharedPointer::operator*() const {
    return *ptr;
}

void SharedPointer::reset(IObject* object) {
    release();
    ptr = object;
    ref_count = new unsigned int(1);
}

void SharedPointer::swap(SharedPointer& other) noexcept {
    std::swap(ptr, other.ptr);
    std::swap(ref_count, other.ref_count);
}

bool SharedPointer::isValid() const {
    return ptr != nullptr;
}

int SharedPointer::use_count() const {
    // ref_count = ref_count ? ref_count : new int(0);
    // return ref_count ? *ref_count : 0;
    if (ptr == nullptr)
        return 0;
    return *ref_count;
}

void SharedPointer::release() {
    if (ref_count && --(*ref_count) == 0) {
        delete ptr;
        delete ref_count;
    }
}
