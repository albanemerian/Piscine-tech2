/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** ToyStory
*/


#include "ToyStory.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "ToyStory.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void ToyStory::tellMeAStory(const std::string &filename, Toy &toy1, ToyMethod func1, Toy &toy2, ToyMethod func2)
{
    std::string line;
    bool isToy1Turn = true;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }

    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;

    while (std::getline(file, line)) {
        if (line.substr(0, 8) == "picture:") {
            std::string pictureFile = line.substr(8);
            if (isToy1Turn) {
                if (toy1.setAscii(pictureFile) == false) {
                    std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what() << std::endl;
                    return;
                } else
                    std::cout << toy1.getAscii() << std::endl;
            } else {
                if (toy2.setAscii(pictureFile) == false) {
                    std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() << std::endl;
                    return;
                } else
                    std::cout << toy2.getAscii() << std::endl;
            }
        } else {
            bool success = false;

            if (isToy1Turn)
                success = func1(toy1, line);
            else
                success = func2(toy2, line);
            if (!success) {
                std::cout << (isToy1Turn ? toy1.getLastError().where() : toy2.getLastError().where())  << ": " << (isToy1Turn ? toy1.getLastError().where() : toy2.getLastError().where()) << std::endl;
                return;
            }
            isToy1Turn = !isToy1Turn;
        }
    }
    file.close();
}
