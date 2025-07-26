/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** Exam
*/

#ifndef EXAM_HPP_
#define EXAM_HPP_

class Exam {
    public:
        static bool cheat;
        void (Exam::*kobayashiMaru)(int);
        Exam(bool *cheatPtr);
        ~Exam();
        void start(int vessels);
        bool isCheating() const;

    protected:
    private:
        bool _cheat;
};

#endif /* !EXAM_HPP_ */
