/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** Admiral
*/

#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_

#include <iostream>
#include "Federation.hpp"
#include "Borg.hpp"

namespace Federation {
    namespace Starfleet {
        class Admiral {
        public:
            Admiral(std::string name);
            ~Admiral();
            typedef bool (Ship::*movePtr)(Destination);
            typedef void (Ship::*firePtr)(Borg::Ship *);
            void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
            bool move(Federation::Starfleet::Ship *ship, Destination dest);
            // _movePtr = &Ship::move;
            // _firePtr = &Ship::fire;
        private:
            std::string _name;
            movePtr _movePtr;
            firePtr _firePtr;
        };
    }
}

#endif /* !ADMIRAL_HPP_ */
