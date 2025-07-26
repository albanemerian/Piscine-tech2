/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD08-albane.merian
** File description:
** Carrier
*/

#ifndef CARRIER_HPP_
#define CARRIER_HPP_

#include <iostream>
#include "Droid.hpp"

class Carrier {
    public:
        Carrier(std::string id);
        ~Carrier();
        Carrier(const Carrier &other) = delete;
        Carrier& operator=(const Carrier &other) = delete;

        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        size_t getSpeed() const;

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setSpeed(size_t speed);

        Carrier& operator<<(Droid* &droid);
        Carrier& operator>>(Droid* &droid);
        Droid* operator[](size_t index) const;
        Droid*& operator[](size_t index);
        Carrier& operator~();
        bool operator()(int x, int y);
        Carrier& operator<<(size_t &energy);

        Droid* const* getDroids() const { return droids; }


    private:
        std::string id;
        size_t energy;
        const size_t attack;
        const size_t toughness;
        size_t speed;
        Droid* droids[5];
};

#endif /* !CARRIER_HPP_ */

