/*
** EPITECH PROJECT, 2025
** day8
** File description:
** main
*/


#include "Droid.hpp"
#include <iostream>
#include <string>
#include "DroidMemory.hpp"


int main()
{ 
    size_t dg = 42;
    Droid d("R2D2");
    // d.setBattleData(new DroidMemory(dg + 1));
    DroidMemory mem1;
    mem1 += 42;

    DroidMemory mem2 = mem1;
    std::cout << mem1 << std::endl;

    DroidMemory mem3;
    mem3 << mem1;
    mem3 >> mem1;
    mem3 << mem1;

    std::cout << mem3 << std::endl;
    std::cout << mem1 << std::endl;
}

// int main()
// {
//     Droid d("R2D2");
//     size_t energy = 50;
//     d << energy;
//     std::cout << d << std::endl;

//     DroidMemory mem1;
//     mem1 += 42;
//     std::cout << mem1 << std::endl;

//     DroidMemory mem2 = mem1;
//     std::cout << mem2 << std::endl;

//     DroidMemory mem3;
//     mem3 << mem1;
//     mem3 >> mem1;
//     mem3 << mem1;
//     std::cout << mem3 << std::endl;
//     std::cout << mem1 << std::endl;

//     return 0;
// }
