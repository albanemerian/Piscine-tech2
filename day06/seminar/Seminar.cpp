/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** Seminar
*/

#include "Seminar.hpp"
#include <iostream>

Seminar::Seminar() : dean(nullptr)
{
}

Seminar::~Seminar()
{
}

void Seminar::run()
{
    //clock in dean clock in assisstnat
    if (!running) {
        if (!dean || assistants.empty() || students.empty()) {
            std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student." << std::endl;
            return;
        }
        running = true;
        std::cout << "Seminar: Begining 6th day of seminar." << std::endl;
        std::cout << "Dean of Studies: " << dean->getName() << std::endl;
        std::cout << "Teaching assistants: ";
        for (size_t i = 0; i < assistants.size(); ++i) {
            std::cout << assistants[i]->getId();
            if (i < assistants.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        std::cout << "Students: ";
        for (size_t i = 0; i < students.size(); ++i) {
            std::cout << students[i]->getName();
            if (i < students.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        dean->timeCheck();
        for (int clock_in = 0; clock_in < assistants.size(); ++clock_in) {
            assistants[clock_in]->timeCheck();
        }
        // Check on students 5 times
        bool toggle = false;
        for (int check = 0; check < students.size(); ++check) {
            for (size_t i = 0; i < students.size(); ++i) {
                dean->teachStudent(students[i], "I'm learning C++!");
                assistants[toggle ? 1 : 0]->helpStudent(students[i]);
                toggle = !toggle;
            }
        }
    } else {
        running = false;
        std::cout << "Seminar: Ending 6th day of seminar." << std::endl;
        dean->timeCheck();
        for (int clock_out = 0; clock_out < assistants.size(); ++clock_out) {
            assistants[clock_out]->timeCheck();
        }
    }
    dean->timeCheck();
    for (int clock_in = 0; clock_in < assistants.size(); ++clock_in) {
        assistants[clock_in]->timeCheck();
    }
}

void Seminar::addDean(Dean *dean)
{
    if (this->dean) {
        std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;
    } else {
        this->dean = dean;
        std::cout << "Seminar: Dean " << dean->getName() << " is here." << std::endl;
    }
}

void Seminar::addAssistant(Assistant *assistant)
{
    for (auto &a : assistants) {
        if (a->getId() == assistant->getId()) {
            std::cout << "Seminar: Assistant " << assistant->getId() << " is already registered." << std::endl;
            return;
        }
    }
    if (assistants.size() >= 2) {
        std::cout << "Seminar: There is only room for two Teaching Assistants." << std::endl;
    } else {
        assistants.push_back(assistant);
        std::cout << "Seminar: Assistant " << assistant->getId() << " joined the pedagogical team." << std::endl;
    }
}

void Seminar::addStudent(Student *student)
{
    for (auto &s : students) {
        if (s->getName() == student->getName()) {
            std::cout << "Seminar: Student " << student->getName() << " is already registered." << std::endl;
            return;
        }
    }
    if (students.size() >= 5) {
        std::cout << "Seminar: There is only room for five Students." << std::endl;
    } else {
        students.push_back(student);
        std::cout << "Seminar: Student " << student->getName() << " joined the seminar." << std::endl;
    }
}
