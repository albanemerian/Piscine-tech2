/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_
#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Destination.hpp"

// namespace Federation {
//     namespace Starfleet {
//         class Ship;
//     }
//     class Ship;
// }

namespace Borg {
    class Ship {
    public:
        Ship(int weaponFrequency = 20, short repair = 3);
        ~Ship();
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d); // set _location to d
        bool move(int warp); // set _location to _home
        bool move(Destination d); // set _location to d
        bool move(); // set _location to _home
        int getShield();
        void setShield(int shield);
        int getWeaponFrequency();
        void setWeaponFrequency(int frequency);
        short getRepair();
        void setRepair(short repair);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair();
    private:
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _home;
        Destination _location;
        int _shield;
        int _weaponFrequency;
        short _repair;
    };
}

#endif /* !BORG_HPP_ */
