/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP
#define TOYSTORY_HPP

#include "Toy.hpp"
#include <string>
#include <fstream>
#include <functional>

class ToyStory {
public:

    using ToyMethod = std::function<bool(Toy&, const std::string&)>;
    static void tellMeAStory(const std::string &filename, Toy &toy1, ToyMethod func1, Toy &toy2, ToyMethod func2);
};
#endif // TOYSTORY_HPP
