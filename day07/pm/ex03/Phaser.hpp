/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** Phaser
*/

#ifndef PHASER_HPP_
#define PHASER_HPP_

#include <iostream>
#include <vector>

class Phaser {
    public:
        enum AmmoType {
            REGULAR,
            PLASMA,
            ROCKET
        };

        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser();
        void fire();
        void ejectClip();
        void changeType(AmmoType newType);
        void reload();
        void addAmmo(AmmoType type);
        int getCurrentAmmos() const;

    private:
        static const int Empty = 0;
        int maxAmmo;
        int currentAmmo;
        AmmoType defaultType;
        std::vector<AmmoType> magazine;
};

#endif /* !PHASER_HPP_ */
