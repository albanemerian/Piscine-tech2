/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** FruitUtils
*/

#ifndef FRUITUTILS_HPP_
#define FRUITUTILS_HPP_

#include "FruitBox.hpp"

class FruitUtils  {
    public:
        // FruitUtils();
        // ~FruitUtils();
        static unsigned int getIFruitSize(IFruit **fruits);
        static FruitBox **pack(IFruit **fruits, unsigned int boxSize);
        static IFruit **unpack(FruitBox **fruitBoxes);
        static void sort(FruitBox &unsorted, FruitBox &Lemon, FruitBox &Citrus, FruitBox &Berry);
    protected:
    private:
};

#endif /* !FRUITUTILS_HPP_ */
