/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** Student
*/

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <string>

class Student {
    public:
        Student(const std::string &name);
        ~Student();
        bool learn(const std::string &text);
        void drink(const std::string &drinkName);
        std::string getName() const;
    private:
        std::string name;
        int energy = 100;
};

#endif /* !STUDENT_HPP_ */
