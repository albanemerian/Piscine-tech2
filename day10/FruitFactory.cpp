/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** FruitFactory
*/

#include "FruitFactory.hpp"

// FruitFactory::FruitFactory()
// {
// }

FruitFactory::~FruitFactory()
{
    for (auto& pair : fruits) {
        delete pair.second;
    }
}

void FruitFactory::registerFruit(IFruit* fruit) {
    if (fruit) {
        auto it = fruits.find(fruit->getName());
        if (it != fruits.end()) {
            delete it->second;
        }
        fruits[fruit->getName()] = fruit;
    }
}

void FruitFactory::unregisterFruit(const std::string& name) {
    auto it = fruits.find(name);
    if (it != fruits.end()) {
        delete it->second;
        fruits.erase(it);
    }
}

IFruit* FruitFactory::createFruit(const std::string& name) const {
    auto it = fruits.find(name);
    if (it != fruits.end()) {
        return it->second->clone();
    }
    return nullptr;
}

