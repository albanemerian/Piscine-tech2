/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** Dean
*/

#include "Dean.hpp"
#include <iostream>
#include <algorithm>
#include <string.h>
#include <fstream>
#include <cstdlib>

Dean::Dean(const std::string &name) : name(name)
{
    std::cout << "Dean " << name << ": I'm Dean "<< name <<"! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean()
{
    std::cout << "Dean " << name << ": Time to go home." << std::endl;
}

void Dean::timeCheck()
{
    if (working)
        std::cout << "Dean " << name <<": Where is everyone?" << std::endl;
    else
        std::cout << "Dean " << name << ": Don't forget to close the windows when you leave." << std::endl;
    working = !working;
}

void Dean::teachStudent(Student *student, const std::string &lesson)
{
    if (!student->learn(lesson)) {
        std::cout << "Dean " << name << ": All work and no play makes " << student->getName() << " a dull student." << std::endl;
        
        const char* drinks[] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
        std::string drink = drinks[std::rand() % 5];
        
        std::ofstream report(student->getName() + ".drink");
        report << drink;
        report.close();
    }
}

std::string Dean::getName() const
{
    return name;
}
