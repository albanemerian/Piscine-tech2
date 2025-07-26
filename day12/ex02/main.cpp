/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** main
*/


#include "Toy.hpp"
#include "Picture.hpp"
#include <iostream>
#include "Buzz.hpp"
#include "Woody.hpp"

int main_base()
{
    Toy toto;
    Toy ET(Toy::BUZZ, "green", "./buzz.txt");

    toto.setName("TOTO !");

    if (toto.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy: " << toto.getName() << std::endl
                  << toto.getAscii() << std::endl;
    if (ET.getType() == Toy::ALIEN)
        std::cout << "this alien is: " << ET.getName() << std::endl
                  << ET.getAscii() << std::endl;
    return 0;
}


int main_wood()
{
    Toy toto;
    Buzz buzz("buzz", "buzz.txt");

    toto.setName("TOTO !");

    if (toto.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy: " << toto.getName() << std::endl
                  << toto.getAscii() << std::endl;
    if (buzz.getType() == Toy::BUZZ)
        std::cout << "this toy is: " << buzz.getName() << std::endl
                  << buzz.getAscii() << std::endl;
    return 0;
}

int main_buzz()
{
    Toy toto;
    Buzz buzz("woody", "buzz.txt");

    toto.setName("TOTO !");

    if (toto.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy: " << toto.getName() << std::endl
                  << toto.getAscii() << std::endl;
    if (buzz.getType() == Toy::BUZZ)
        std::cout << "this toy is: " << buzz.getName() << std::endl
                  << buzz.getAscii() << std::endl;
    return 0;
}


int main()
{
    main_base();
    main_wood();
    printf("\n----\n");
    main_buzz();
    return 0;
}
