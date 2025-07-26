/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** Exam
*/

#include "Exam.hpp"
#include <iostream>

bool Exam::cheat = false;

Exam::Exam(bool *cheatPtr) {
    (void)cheatPtr;
}

Exam::~Exam() {}

void Exam::start(int vessels) {
    std::cout << "[The exam is starting]" << std::endl;
    std::cout << vessels << " Klingon vessels appeared out of nowhere." << std::endl;
    std::cout << "they are fully armed and shielded" << std::endl;

    if (cheat) {
        std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
    } else {
        std::cout << "This exam is hard... you lost again." << std::endl;
    }
}

bool Exam::isCheating() const {
    return cheat;
}
