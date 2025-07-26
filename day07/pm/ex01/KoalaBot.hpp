/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_


#include <iostream>
#include "Parts.hpp"


class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();
        void setParts(const Arms &amrs);
        void setParts(const Legs &legs);
        void setParts(const Head &head);
        void swapParts(Arms &parts);
        void swapParts(Legs &parts);
        void swapParts(Head &parts);
        void informations() const;
        bool status() const;
        // Parts partsInstance;

    protected:
    private:
        std::string _serial;
        Arms armsKoala;
        Legs legsKoala;
        Head headKoala;
};

#endif /* !KOALABOT_HPP_ */
