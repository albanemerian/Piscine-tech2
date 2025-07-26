/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** Assistant
*/

#ifndef ASSISTANT_HPP_
#define ASSISTANT_HPP_

#include <string>
#include "Student.hpp"

class Assistant {
    public:
        Assistant(const int &id);
        ~Assistant();
        void giveDrink(Student *student, const std::string &drinkName);
        std::string readDrink(const std::string &studentName);
        void helpStudent(Student *student);
        void timeCheck();
        int getId() const;
    private:
        int id;
        bool working = false;
};

#endif /* !ASSISTANT_HPP_ */
