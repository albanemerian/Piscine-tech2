/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN_HPP_
#define BORGQUEEN_HPP_

#include <iostream>
#include "Borg.hpp"
#include "Federation.hpp"

namespace Borg {
    class BorgQueen {
    public:
        BorgQueen();
        ~BorgQueen();
        typedef bool (Ship::*movePtr)(Destination);
        typedef void (Ship::*firePtr)(Federation::Starfleet::Ship *);
        typedef void (Ship::*destroyPtr)(Federation::Ship *);
        bool move(Borg::Ship *ship, Destination dest);
        void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
        void destroy(Borg::Ship *ship, Federation::Ship *target); 
    private:
        // std::string _name;
        movePtr _movePtr;
        firePtr _firePtr;
        destroyPtr _destroyPtr;
    };
}

#endif /* !BORGQUEEN_HPP_ */
