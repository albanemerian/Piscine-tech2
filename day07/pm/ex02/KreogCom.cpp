/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** KreogCom
*/

#include "KreogCom.hpp"
#include <iostream>

KreogCom::KreogCom(int x, int y, int serial) : m_serial(serial), _x(x), _y(y), head(nullptr)
{
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    if (head == nullptr) {
        head = new LinkedList(_x, _y, m_serial);
    }
    LinkedList *newNode = new LinkedList(x, y, serial);
    newNode->next = head;
    head = newNode;
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

void KreogCom::removeCom()
{
    if (head == nullptr) {
        return;
    }
    LinkedList *tmp = head;
    std::cout << "KreogCom " << head->m_serial << " shutting down" << std::endl;
    head = head->next;
    delete tmp;
}

KreogCom *KreogCom::getCom()
{
    if (head == nullptr)
        return nullptr;
    return this;
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << m_serial << " currently at " << _x << " " << _y << std::endl;
}


// KreogCom 51 currently at 73 34$
// KreogCom 65 currently at 56 25$
// KreogCom 101010 currently at 42 42$
void KreogCom::locateSquad()
{
    LinkedList *temp = head;
    while (temp != nullptr) {
        std::cout << "KreogCom " << temp->m_serial << " currently at " << temp->_x << " " << temp->_y << std::endl;
        temp = temp->next;
    }
}
