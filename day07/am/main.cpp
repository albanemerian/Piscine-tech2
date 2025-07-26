/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** main
*/

#include "Federation.hpp"
#include "Borg.hpp"
#include "Admiral.hpp"
#include "Exam.hpp"
#include <iostream>

// int main(void) //exo 0
// {
//     Federation::Starfleet::Ship UssJanissary(289, 132, "Janissary", 6);
//     Federation::Ship Independent(150, 230, "Nomad");
//     WarpSystem::QuantumReactor QR;
//     WarpSystem::QuantumReactor QR2;
//     WarpSystem::Core core(&QR);
//     WarpSystem::Core core2(&QR2);

//     UssJanissary.setupCore(&core);
//     UssJanissary.checkCore();
//     Independent.setupCore(&core2);
//     Independent.checkCore();

//     QR.setStability(false);
//     QR2.setStability(false);
//     UssJanissary.checkCore();
//     Independent.checkCore();

//     return 0;
// }

// int main() //exo 1
// {
//     Federation::Starfleet::Ship UssJanissary(289, 132, "Janissary", 6);
//     Federation::Starfleet::Captain James("James T. Kirk");
//     Federation::Starfleet::Ensign Ensign("Pavel Chekov");
//     WarpSystem::QuantumReactor QR;
//     WarpSystem::QuantumReactor QR2;
//     WarpSystem::Core core(&QR);
//     WarpSystem::Core core2(&QR2);

//     UssJanissary.setupCore(&core);
//     UssJanissary.checkCore();
//     UssJanissary.promote(&James);

//     Borg::Ship Cube;
//     Cube.setupCore(&core2);
//     Cube.checkCore();

//     return 0;
// }

// int main(void)
// {
//     Federation::Starfleet::Ship UssJanissary(289, 132, " Janissary ", 6);
//     printf(" \n");
//     Federation::Starfleet::Ship BiggerShip(345, 219, " Pathfinder ", 6, 5);
//     printf("\n");
//     Federation::Starfleet::Ship DefaultShip;
//     return 0;
// }

int main()
{
    Exam e = Exam(&Exam::cheat);
    e.kobayashiMaru = &Exam::start;
    (e.*e.kobayashiMaru)(3);
    Exam::cheat = true;
    if (e.isCheating())
        (e.*e.kobayashiMaru)(4);
    return 0;
}
