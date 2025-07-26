/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** List
*/

#include "List.hpp"

List::List()
{
}

List::~List()
{
    for (auto it = _list.begin(); it != _list.end(); ++it) {
        delete *it;
    }
    _list.clear();
}


bool List::empty() const
{
    if (_list.empty())
        return true;
    return false;
}

std::size_t List::size() const
{
    return _list.size();
}



IObject *&List::front()
{
    if (_list.empty())
        throw InvalidOperationException("List is empty");
    return _list.front();
}

IObject *List::front() const
{
    if (_list.empty())
        throw InvalidOperationException("List is empty");
    return _list.front();
}

IObject *&List::back()
{
    if (_list.empty())
        throw InvalidOperationException("List is empty");
    return _list.back();
}

IObject *List::back() const
{
    if (_list.empty())
        throw InvalidOperationException("List is empty");
    return _list.back();
}


void List::pushBack(IObject *obj)
{
    _list.push_back(obj);
}

void List::pushFront(IObject *obj)
{
    _list.push_front(obj);
}

void List::popFront()
{
    if (_list.empty())
        throw InvalidOperationException("Invalid operation on a list");
    delete _list.front();
    _list.pop_front();
}

void List::popBack()
{
    if (_list.empty())
        throw InvalidOperationException("Invalid operation on a list");
    delete _list.back();
    _list.pop_back();
}

void List::clear()
{
    if (_list.empty())
        throw InvalidOperationException("List is empty");
    for (auto it = _list.begin(); it != _list.end(); ++it) {
        delete *it;
    }
    _list.clear();
}

void List::forEach(void (*function)(IObject *))
{
    for (auto it = _list.begin(); it != _list.end(); it++) {
        function(*it);
    }
}

// void List::InvalidOperationException::InvalidOperationException(std::string const &message)  : message(message)
// {
//     std::runtime_error(message);
// }
