/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
#define SHAREDPOINTER_HPP_

#include <utility>
#include "IObject.hpp"

class SharedPointer {
    public:
        SharedPointer();
        SharedPointer(IObject* object); // Allow implicit conversion
        SharedPointer(const SharedPointer& other);
        SharedPointer(SharedPointer&& other) noexcept;
        ~SharedPointer();

        SharedPointer& operator=(const SharedPointer& other);
        SharedPointer& operator=(SharedPointer&& other) noexcept;
        SharedPointer& operator=(IObject* object);

        IObject* operator->() const;
        IObject& operator*() const;

        void reset(IObject* object = nullptr);
        void swap(SharedPointer& other) noexcept;
        bool isValid() const;
        int use_count() const;

    private:
        void release();

        IObject* ptr;
        unsigned int* ref_count;
};

#endif /* !SHAREDPOINTER_HPP_ */
