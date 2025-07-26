/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
#define SHAREDPOINTER_HPP_

#include <iostream>

template <typename Type>
class SharedPointer {
    public:
        SharedPointer() : ptr(nullptr), count(nullptr) {}

        SharedPointer(Type *p) : ptr(p), count(new int(1)) {}

        SharedPointer(const SharedPointer &other) : ptr(other.ptr), count(other.count) {
            if (count) {
                ++(*count);
            }
        }
        SharedPointer& operator=(const SharedPointer &other) {
            if (this != &other) {
                release();
                ptr = other.ptr;
                count = other.count;
                if (count) {
                    ++(*count);
                }
            }
            return *this;
        }
        ~SharedPointer() {
            release();
        }
        void reset(Type *p = nullptr) {
            release();
            if (p) {
                ptr = p;
                count = new int(1);
            } else {
                ptr = nullptr;
                count = nullptr;
            }
        }

        Type* get() const {
            return ptr;
        }

        Type& operator*() const {
            return *ptr;
        }

        Type* operator->() const {
            return ptr;
        }
        void release() {
            if (count) {
                --(*count);
                if (*count == 0) {
                    delete ptr;
                    delete count;
                }
            }
        }
    private:
        Type *ptr;
        int *count;
};

#endif /* !SHAREDPOINTER_HPP_ */
