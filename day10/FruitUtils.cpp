/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"
#include "FruitBox.hpp"
#include "ACitrus.hpp"
#include "ABerry.hpp"
#include "Lemon.hpp"
// FruitUtils::FruitUtils()
// {
// }

// FruitUtils::~FruitUtils()
// {
// }

unsigned int FruitUtils::getIFruitSize(IFruit **fruits)
{
    unsigned int size = 0;

    if (fruits == nullptr)
        return 0;
    for (unsigned int i = 0; fruits[i] != nullptr; i++)
        size++;
    // printf("size: %d\n", size);
    return size;
}

IFruit **FruitUtils::unpack(FruitBox **fruitboxes)
{
    if (fruitboxes == nullptr)
        return nullptr;

    unsigned int total_fruits = 0;
    for (int i = 0; fruitboxes[i] != nullptr; i++) {
        total_fruits += fruitboxes[i]->nbFruits();
    }
    IFruit **fruits = new IFruit*[total_fruits + 1];
    unsigned int fruit_index = 0;

    for (int i = 0; fruitboxes[i] != nullptr; i++) {
        IFruit *fruit;
        while ((fruit = fruitboxes[i]->popFruit()) != nullptr) {
            fruits[fruit_index++] = fruit;
        }
    }
    fruits[fruit_index] = nullptr;
    return fruits;
}

FruitBox **FruitUtils::pack(IFruit **fruits, unsigned int boxSize)
{
    // if (boxSize <= 1)
    //     return nullptr;

    unsigned int num_fruits = getIFruitSize(fruits);
    unsigned int num_boxes = (num_fruits + boxSize - 1) / boxSize;

    FruitBox **boxes = new FruitBox *[num_boxes + 1];
    if (boxes == nullptr)
        return nullptr;

    unsigned int fruit_index = 0;
    for (unsigned int i = 0; i < num_boxes; i++) {
        unsigned int this_box_size = (i < num_boxes - 1) ? boxSize : (num_fruits - fruit_index);
        boxes[i] = new FruitBox(this_box_size); // Correctly allocate each FruitBox

        for (unsigned int j = 0; j < this_box_size && fruit_index < num_fruits; j++) {
            boxes[i]->pushFruit(fruits[fruit_index++]);
        }
    }
    boxes[num_boxes] = nullptr; // Ensure the last element is nullptr

    return boxes;
}

void FruitUtils::sort(FruitBox &unsorted, FruitBox &Lemons, FruitBox &Citrus, FruitBox &Berry)
{
    FruitBox tempBox(unsorted.getSize());
    IFruit *fruit;

    while ((fruit = unsorted.popFruit()) != nullptr) {
        if (dynamic_cast<ACitrus *>(fruit)) {
            if (dynamic_cast<Lemon *>(fruit)) {
                    if (!Lemons.pushFruit(fruit))
                        tempBox.pushFruit(fruit);
            } else {
                if (!Citrus.pushFruit(fruit))
                    tempBox.pushFruit(fruit);
            }
        } else if (dynamic_cast<ABerry *>(fruit)) {
            if (!Berry.pushFruit(fruit))
                tempBox.pushFruit(fruit);
        } else {
            tempBox.pushFruit(fruit);
        }
    }
    while ((fruit = tempBox.popFruit()) != nullptr) {
        unsorted.pushFruit(fruit);
    }
}
