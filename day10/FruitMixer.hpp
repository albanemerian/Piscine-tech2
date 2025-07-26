/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** FruitMixer
*/

#ifndef FRUITMIXER_HPP_
#define FRUITMIXER_HPP_

#include "IFruitMixer.hpp"

class FruitMixer : public IFruitMixer
{
public:
    FruitMixer() : blade(nullptr) {}
    ~FruitMixer() override = default;

    unsigned int mixFruits(FruitBox& box) const override;
    void setBlade(IBlade* newBlade) override;

private:
    IBlade* blade;
};


#endif /* !FRUITMIXER_HPP_ */
