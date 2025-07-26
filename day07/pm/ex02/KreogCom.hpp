/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <iostream>
#include <algorithm>
#include <list>

class KreogCom {
    class LinkedList {
        public:
            LinkedList(int x, int y, int serial) : m_serial(serial), _x(x), _y(y), next(nullptr) {}
            int m_serial;
            int _x;
            int _y;
            LinkedList *next;
    };
    public:
        KreogCom(int x, int y, int serial);
        ~ KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping();
        void locateSquad();
    private:
        const int m_serial;
        int _x;
        int _y;
        LinkedList *head;
};

#endif /* !KREOGCOM_HPP_ */
