/*
** EPITECH PROJECT, 2025
** day8
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>


class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();
        DroidMemory(const DroidMemory &other);

        size_t getFingerPrint() const;
        size_t getExp() const;
        void setFingerPrint(size_t fingerPrint);
        void setExp(size_t exp);
        
        bool operator==(const DroidMemory &other) const;
        bool operator!=(const DroidMemory &other) const;
        bool operator<(const DroidMemory &other) const;
        bool operator>(const DroidMemory &other) const;
        bool operator<=(const DroidMemory &other) const;
        bool operator>=(const DroidMemory &other) const;

        DroidMemory& operator<<(DroidMemory &other);
        DroidMemory& operator>>(DroidMemory &other);
        DroidMemory& operator+=(const DroidMemory &other);
        DroidMemory& operator+=(size_t exp);
        DroidMemory operator+(const DroidMemory &other) const;
        DroidMemory operator+(size_t exp) const;

        bool operator==(size_t exp) const;
        bool operator!=(size_t exp) const;

    private:
        size_t fingerPrint;
        size_t exp;
};

std::ostream& operator<<(std::ostream& os, const DroidMemory& mem);

#endif /* !DROIDMEMORY_HPP_ */
