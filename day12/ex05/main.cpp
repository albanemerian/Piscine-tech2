/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** main
*/

#include <memory>
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
    Buzz buzz("buzz", "woody.txt");

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

int main_statement()
{
    std::unique_ptr<Toy> b(new Buzz("buzziiiii"));
    std::unique_ptr<Toy> w(new Woody("wood"));
    std::unique_ptr<Toy> t(new Toy(Toy::ALIEN, "ET", "alien.txt"));

    b->speak("To the code, and beyond !!!!!!!!");
    w->speak("There's a snake in my boot.");
    t->speak("the claaaaaaw");
    return 0;
}
int main_furi()
{
    Toy a(Toy::BASIC_TOY, "REX", "exemple.txt");

    std::cout << a;
    a << "rawr xD";
    std::cout << a;
    return 0;
}

int main_error()
{
    Woody w("wood");

    if (w.setAscii("file_who_does_not_exist.txt") == false) {
        auto e = w.getLastError();
        if (e.type == Toy::Error::PICTURE) {
                std::cout << "Error in " << e.where() << ": " << e.what() << std::endl;
        }
    }

    if (w.speak_es("Woody does not have spanish mode") == false) {
        auto e = w.getLastError();
        if (e.type == Toy::Error::SPEAK) {
            std::cout << "Error in " << e.where() << ": " << e.what() << std::endl;
        }
    }

    if (w.speak_es("Woody does not have spanish mode") == false) {
        auto e = w.getLastError();
        if (e.type == Toy::Error::SPEAK) {
            std::cout << "Error in " << e.where() << ": " << e.what() << std::endl;
        }
    }
    return 0;
}

int main()
{
    main_base();
    main_wood();
    printf("\n----\n");
    main_buzz();
    printf("\n----\n");
    main_statement();
    printf("\n----\n");
    main_furi();
    printf("\n----\n");
    main_error();
    printf("\n----\n");

    Toy toy;
    Toy::Error e = toy.getLastError();

    std::cout << "no error in " << e.where() << ": " << e.what() << std::endl;

    toy.setAscii("nonexistent_file.txt");
    e = toy.getLastError();
    if (e.type != Toy::Error::UNKNOWN) {
        std::cout << "Error in " << e.where() << ": " << e.what() << std::endl;
    }

    toy.speak_es("Hola");
    e = toy.getLastError();
    if (e.type != Toy::Error::UNKNOWN) {
        std::cout << "Error in " << e.where() << ": " << e.what() << std::endl;
    }

    return 0;
}
