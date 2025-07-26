/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** Stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stack>
#include <string>

class Stack {
    public:
        Stack() = default;
        ~Stack() = default;
        void push(double value);
        double pop();
        double top() const;


        void add();
        void sub();
        void mul();
        void div();
        class Error : public std::exception {
            public:
                enum ErrorType {
                    OP,
                    TOPO,
                    OTHER
                };
                const char* what() const noexcept override {
                    if (type == OP)
                        return "Not enough operands";
                    else
                        return "Empty stack";
                }
                ErrorType type = OTHER;
        };
    private:
        std::stack<double> _stack;
        Error _lasterror;

    protected:
};

#endif /* !STACK_HPP_ */
