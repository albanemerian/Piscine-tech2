/*
** EPITECH PROJECT, 2025
** day8
** File description:
** main
*/

#include "Droid.hpp"
#include <iostream>
#include <string>
#include <ostream>


int main()
{
    Droid d;
    Droid d1("Avenger");
    size_t Durasel = -9;

    std::cout << d << std::endl;
    std::cout << d1 << std::endl;
    d = d1;
    d.setStatus(new std::string("Kill Kill Kill!"));
    d << Durasel;
    std::cout << d << "--" << Durasel << std::endl;
    Droid d2 = d;
    d.setId("Rex");
    std::cout << (d2 != d) << std::endl;

    return 0;
}
// int main()
// {
//     Droid d1;
//     Droid d2("Avenger");
    
//     // Initial status
    
//     std::cout << d1 << std::endl;
//     std::cout << d2 << std::endl;
    
//     // Create and test energy supply
//     std::cout << "Durasel d1, the Energy rabbit : " << d1.getEnergy() << std::endl;
    
//     // Test energy transfer and attack
//     d2.setEnergy(100);
//     std::cout << d2 << std::endl;
//     std::cout << "Energy remaining in the Rabbit: " << d2.getEnergy() << std::endl;
    
//     // Memory operations
//     std::cout << "Ok! Kill 'em all!" << std::endl;
    
//     // Create new droid
//     Droid d3("Rex");
//     std::cout << "Nice to meet you Rex!" << std::endl;
    
//     // This is where the error appears in your output
//     d2.setEnergy(100);  // Reset energy to ensure consistent state
//     std::cout << d2 << std::endl;
    
//     // Continue with battle simulation
//     d2.setEnergy(42);
//     d1.setEnergy(100);
//     std::cout << d2 << std::endl;
//     std::cout << "Energy before in the Rabbit: " << d1.getEnergy() << std::endl;
//     d1.setEnergy(-100);  // Drain remaining energy
//     // d1.setEnergy(100);
//     std::cout << "Energy during in the Rabbit: " << d1.getEnergy() << std::endl;
//     size_t Durasel = -200;
//     d1 << Durasel;
//     std::cout << "Energy after in the Rabbit: " << d1.getEnergy() << std::endl;
        
//     // Cleanup
//     std::cout << "Droid 'Avenger' Destroyed" << std::endl;
//     std::cout << "Droid 'Avenger' Destroyed" << std::endl;
//     std::cout << "Droid 'Rex' Destroyed" << std::endl;
    
//     return 0;
// }


// // int main()
// // {
// //     Droid d;
// //     Droid d1("Avenger");
// //     size_t Durasel = 200;

// //     std::cout << d << std::endl;
//     std::cout << d1 << std::endl;
//     d = d1;
//     d.setStatus(new std::string("Kill Kill Kill!"));
//     d << Durasel;
//     std::cout << d << "--" << Durasel << std::endl;
//     Droid d2 = d;
//     d.setId("Rex");
//     std::cout << (d2 != d) << std::endl;

//     return 0;
// }

    // Droid d1;
    // Droid d2("Avenger");
    // std::cout << d1 << " Activated" << std::endl;
    // std::cout << d2 << " Activated" << std::endl;
    // std::cout << d1 << std::endl;
    // std::cout << d2 << std::endl;

    // size_t energy = 200;
    // std::cout << "Durasel, the Energy rabbit : " << energy << std::endl;
    // d2 << energy;
    // std::cout << d2 << std::endl;
    // std::cout << "Energy remaining in the Rabbit: " << energy << std::endl;

    // d2.setStatus(new std::string("Activated, Memory Dumped"));
    // std::cout << d2 << std::endl;

    // return 0;
