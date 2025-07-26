/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** List
*/

#ifndef LIST_HPP_
#define LIST_HPP_

#include <list>
#include "IObject.hpp"
#include <string>
#include <exception>


class List {
    public:
        List();
        ~List();

        bool empty() const;
        std::size_t size()const;

        IObject *&front();
        IObject *front() const;
        IObject *&back();
        IObject *back() const;

        void pushBack(IObject* obj);
        void pushFront(IObject* obj);
        void popFront();
        void popBack();
        void clear();
        void forEach(void(*function)(IObject*));
        class InvalidOperationException : public std::exception {
            public:
                InvalidOperationException(std::string const& message) : sms(message) {}
                const char* what() const noexcept override {
                    return sms.c_str();
                }
            private:
                std::string sms;
        };
        typedef std::list<IObject*> LinkedList;

    protected:
        LinkedList _list;
        //lsit 
    private:
};

#endif /* !LIST_HPP_ */
