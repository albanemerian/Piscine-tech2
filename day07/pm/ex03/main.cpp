/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** main
*/

#include "Phaser.hpp"
#include <iostream>
#include <ostream>
#include "Sounds.hpp"

int main()
{
    Phaser p(5, Phaser::ROCKET);

    p.fire();
    p.reload();

    std::cout << "Firing all ammunition" << std::endl;
    while (p.getCurrentAmmos() > 0)
        p.fire();

    p.ejectClip();
    p.fire(); // Should print "Clip empty, please reload"

    p.addAmmo(Phaser::PLASMA);
    p.fire(); // Should print the plasma sound

    p.changeType(Phaser::REGULAR);
    p.reload();
    p.fire(); // Should print the regular sound

    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET); // Should print "Clip full"

    return 0;
}
