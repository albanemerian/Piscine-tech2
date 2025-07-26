/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string &name, const std::string &filename = "buzz.txt");
        ~Buzz() = default;
        void speak(const std::string statement);
        bool speak_es(std::string statement) override;
    private:
        // std::string _name;
        // std::string _filename;
        // ToyType _type;
};

#endif /* !BUZZ_HPP_ */
