/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** FruitMixer
*/

#include "FruitMixer.hpp"
#include "FruitBox.hpp"

// FruitMixer::FruitMixer()
// {
// }

// FruitMixer::~FruitMixer()
// {
// }

unsigned int FruitMixer::mixFruits(FruitBox& box) const
{
    if (!blade) {
        std::cout << "mixer has no blade" << std::endl;
        return 0;
    }

    unsigned int totalVitamins = 0;
    FruitBox tempBox(box.getSize());

    while (box.nbFruits() > 0) {
        IFruit* fruit = box.popFruit();
        if (fruit->isPeeled()) {
            totalVitamins += (*blade)(*fruit);
        } else {
            tempBox.pushFruit(fruit);
        }
    }

    while (tempBox.nbFruits() > 0) {
        box.pushFruit(tempBox.popFruit());
    }

    return totalVitamins;
}

void FruitMixer::setBlade(IBlade* newBlade)
{
    blade = newBlade;
}

