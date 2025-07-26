/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** FruitFactory
*/

#ifndef FRUITFACTORY_HPP_
#define FRUITFACTORY_HPP_

#include <iostream>
#include <unordered_map>
#include "IFruit.hpp"

class FruitFactory {
    public:
        FruitFactory() = default;
        ~FruitFactory();
        void registerFruit(IFruit* fruit);
        void unregisterFruit(const std::string& name);
        IFruit* createFruit(const std::string& name) const;

    private:
        std::unordered_map<std::string, IFruit*> fruits;
};

#endif /* !FRUITFACTORY_HPP_ */
