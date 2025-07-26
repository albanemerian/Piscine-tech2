/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** Steelblade
*/

#ifndef STEELBLADE_HPP_
#define STEELBLADE_HPP_

#include "IFruitMixer.hpp"

class SteelBlade : public IFruitMixer::IBlade {
    public:
        SteelBlade() = default;
        ~SteelBlade() override = default;
        unsigned int operator()(const IFruit& fruit) const override
        {
            return fruit.getVitamins();
        }

    protected:
    private:
};

#endif /* !STEELBLADE_HPP_ */
