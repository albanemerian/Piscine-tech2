/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** Assistant
*/

#include <iostream>
#include "Assistant.hpp"
#include <fstream>
#include <cstdio>

Assistant::Assistant(const int &id) : id(id)
{
    std::cout << "Assistant " << id << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *student, const std::string &drinkName)
{
    std::cout << "Assistant " << id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
    student->drink(drinkName);
}

std::string Assistant::readDrink(const std::string &studentName)
{
    std::string filename = studentName + ".drink";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return "";
    }
    std::string drinkName;
    std::getline(file, drinkName);
    file.close();
    if (drinkName.empty()) {
        std::cerr << "Error: File " << filename << " is empty or invalid" << std::endl;
        return "";
    }
    std::remove(filename.c_str());
    std::cout << "Assistant " << id << ": " << studentName << " needs a " << drinkName << " *sip coffee*" << std::endl;
    return drinkName;
}

void Assistant :: helpStudent(Student *student)
{
    std::string name = student->getName();
    std::string drink = readDrink(name);
    if (!drink.empty()) {
        giveDrink(student, drink);
        return;
    }
    std::cout << "Assistant " << id << ": " << name << " seems fine *sip coffee*" << std::endl;
}

int Assistant::getId() const
{
    return id;
}

void Assistant::timeCheck()
{
    if (working) {
        std::cout << "Assistant " << id << ": Enough teaching for today *sip coffee*" << std::endl;
    } else {
        std::cout << "Assistant " << id << ": Time to teach some serious business *sip coffee*" << std::endl;
    }
    working = !working;
}
