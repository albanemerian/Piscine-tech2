/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** Seminar
*/

#ifndef SEMINAR_HPP_
#define SEMINAR_HPP_

#include "Dean.hpp"
#include "Student.hpp"
#include "Seminar.hpp"
#include "Assistant.hpp"
#include <vector>

class Seminar {
    public:
        Seminar();
        ~Seminar();
        void run();
        void addDean(Dean *dean);
        void addAssistant(Assistant *assistant);
        void addStudent(Student *student);
    private:
        Dean *dean;
        std::vector<Assistant*> assistants;
        std::vector<Student*> students;
        bool running = false;
};

#endif /* !SEMINAR_HPP_ */
