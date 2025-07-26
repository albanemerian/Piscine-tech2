/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include <algorithm>
#include <list>

FruitBox::FruitBox(unsigned int size) : _size(size)
{
}

FruitBox::~FruitBox()
{
    if (fruit_list.empty())
        return;
    
    for (IFruit* fruit : fruit_list) {
        if (fruit != nullptr)
            delete fruit;
    }
    fruit_list.clear();
}

unsigned int FruitBox::getSize() const
{
    return _size;
}

unsigned int FruitBox::nbFruits() const
{
    return std::count_if(fruit_list.begin(), fruit_list.end(), 
        [](const IFruit* fruit) { return fruit != nullptr; });
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (fruit_list.size() >= _size || fruit == nullptr)
        return false;

    auto it = std::find(fruit_list.begin(), fruit_list.end(), fruit);
    if (it != fruit_list.end())
        return false;
    fruit_list.push_back(fruit);
    return true;
}

IFruit *FruitBox::popFruit()
{
    if (fruit_list.empty())
        return nullptr;
    IFruit *fruit = fruit_list.front();
    fruit_list.pop_front();
    return fruit;
}

FruitBox::LinkedList FruitBox::getFruitList() const
{
    return fruit_list;
}

std::ostream &operator<<(std::ostream &os, const FruitBox &box)
{
    os << "[";
    bool first = true;
    for (const IFruit* fruit : box.getFruitList()) {
        if (fruit != nullptr) {
            if (!first)
                os << ", ";
            os << *fruit;
            first = false;
        }
    }
    os << "]";
    return os;
}
