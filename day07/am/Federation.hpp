/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
// #include "Borg.hpp"

namespace Borg {
    class Ship;
}

namespace Federation {
    namespace Starfleet {
        class Ensign {
            public:
                Ensign(std::string name);
                ~Ensign();
            private:
                std::string _name;
        };
        class Captain {
            public:
                Captain(std::string name);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);
            private:
                std :: string _name;
                int _age;
        };
        // class Admiral {
        //     public:
        //         Admiral(std::string name);
        //         void (Ship::*movePtr)(Destination);
        //         void (Ship::*firePtr)(Borg::Ship *);
        //     private:
        //         std::string _name;
        // };
        class Ship {
        public:
            Ship(int length = 289, int width = 132, std::string name = "Enterprise", short maxWarp = 6, int torpedo = 0);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Captain *captain);
            bool move(int warp, Destination d); // set _location to d
            bool move(int warp); // set _location to _home
            bool move(Destination d); // set _location to d
            bool move(); // set _location to _home
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);
            WarpSystem::Core *getCore();
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            std::string _captain;
            Destination _location;
            Destination _home;
            int _shield;
            int _photonTorpedo;
        };

    }
    class Ship {
    public:
        Ship(int length, int width, std::string name);
        ~Ship();
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d); // set _location to d
        bool move(int warp); // set _location to _home
        bool move(Destination d); // set _location to d
        bool move(); // set _location to _home
        WarpSystem::Core *getCore();
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
        int _shield; // set to 100 upon construction
        int _weaponFrequency; // can be provided upon construction
        short _repair; // can be provided upon construction
    };
}

#endif /* !FEDERATION_HPP_ */
