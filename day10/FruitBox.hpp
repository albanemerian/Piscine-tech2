/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include <queue>
#include <iostream>
#include "IFruit.hpp"
#include <list>

class FruitBox  {
    public:
        FruitBox(unsigned int size);
        ~FruitBox();

        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit *fruit);
        IFruit *popFruit();

        typedef std::list<IFruit *>LinkedList;
        LinkedList getFruitList() const;

    protected:
        
        LinkedList fruit_list;
        unsigned int _size;  // Add this line
    private:
        
};

std::ostream &operator<<(std::ostream &os, const FruitBox &fruit);
#endif /* !FRUITBOX_HPP_ */


// ✓ FruitBox(unsigned int size); : builds a FruitBox that can hold size fruits.
// ✓ unsigned int getSize(); : returns the size of the FruitBox.
// ✓ unsigned int nbFruits(); : returns the number of fruits currently in the FruitBox.
// ✓ bool pushFruit(IFruit *); : push a fruit to the FruitBox, returns false if the box is full or the fruit is
// already in the box.
// ✓ IFruit *popFruit(); : remove a fruit from the FruitBox, returns a nullptr if the box is empty.
// The FruitBox must delete the fruits it contains at its destruction. It must be possible to display its
// content to a std::ostream.
