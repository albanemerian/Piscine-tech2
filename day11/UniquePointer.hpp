/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

#include "IObject.hpp"
#include <utility>

class UniquePointer {
    public:

        UniquePointer();
        UniquePointer(IObject* object); 
        // explicit UniquePointer(IObject* object, bool explicitFlag); // miaoyyuy
        ~UniquePointer();
        UniquePointer(const UniquePointer&) = delete;
        UniquePointer& operator=(const UniquePointer&) = delete;
        UniquePointer(UniquePointer&& other) noexcept;

        UniquePointer& operator=(UniquePointer&& other) noexcept;
        UniquePointer& operator=(IObject* object);

        IObject* operator->() const;
        IObject& operator*() const;

        void reset(IObject* object = nullptr);
        void swap(UniquePointer& other) noexcept;
        bool isValid() const;

    private:
        IObject* ptr;
};

#endif // UNIQUEPOINTER_HPP
