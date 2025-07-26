/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>

// class Parts {

// public:
class Arms {
    public:
        Arms(std::string serial = "A-01", bool functionnal = true);
        ~Arms();
        void informations() const;
        bool isFunctionnal() const;
        std::string serial() const;
    protected:
    private:
        std::string _serial;
        bool _functionnal;
};
class Legs {
    public:
        Legs(std::string serial = "L-01", bool functionnal = true);
        ~Legs();
        void informations() const;
        bool isFunctionnal() const;
        std::string serial() const;
    private:
        std::string _serial;
        bool _functionnal;
};
class Head {
    public:
        Head(std::string serial = "H-01", bool functionnal = true);
        ~Head();
        void informations() const;
        bool isFunctionnal() const;
        std::string serial() const;
    private:
        std::string _serial;
        bool _functionnal;
};
    // Arms arms;
    // Legs legs;
    // Head head;
// private:
//     Arms _arms;
//     Legs _legs;
//     Head _head;
// };

// using Parts::Arms;
// using Parts::Legs;
// using Parts::Head;
#endif /* !PARTS_HPP_ */
