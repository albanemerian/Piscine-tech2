/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** Dean
*/

#ifndef DEAN_HPP_
#define DEAN_HPP_

#include <string>
#include "Student.hpp"

class Dean {
    public:
        Dean(const std::string &name);
        ~Dean();
        void timeCheck();
        void teachStudent(Student *student, const std::string &lesson);
        std::string getName() const;
    private:
        std::string name;
        bool working = true;
};

#endif /* !DEAN_HPP_ */
