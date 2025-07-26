/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
**  Stack
*/

#include "Stack.hpp"
#include <iostream>
#include <stack>
#include <functional>


void Stack::push(double value)
{
    _stack.push(value);
}

double Stack::pop()
{
    if (_stack.empty()) {
        _lasterror.type = Error::TOPO;
        throw _lasterror;
    }
    double value = _stack.top();
    _stack.pop();
    return value;
}

double Stack::top() const
{
    if (_stack.empty()) {
        throw _lasterror;
    }
    return _stack.top();
}

void Stack::add()
{
    if (_stack.size() < 2) {
        _lasterror.type = Error::OP;
        throw _lasterror;
    }
    double a = pop();
    double b = pop();
    push(a + b);
}

void Stack::sub()
{
    if (_stack.size() < 2) {
        _lasterror.type = Error::OP;
        throw _lasterror;
    }
    double a = pop();
    double b = pop();
    push(a - b);
}

void Stack::mul()
{
    if (_stack.size() < 2) {
        _lasterror.type = Error::OP;
        throw _lasterror;
    }
    double a = pop();
    double b = pop();
    push(a * b);
}

void Stack::div()
{
    if (_stack.size() < 2) {
        _lasterror.type = Error::OP;
        throw _lasterror;
    }
    double a = pop();
    double b = pop();
    if (b == 0) {
        _lasterror.type = Error::OP;
        throw _lasterror;
    }
    push(a / b);
}


