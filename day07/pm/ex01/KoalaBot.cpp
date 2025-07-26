/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) : _serial(serial) {}

KoalaBot::~KoalaBot() {}

void KoalaBot::setParts(const Arms &amrs)
{
    armsKoala = amrs;
}

void KoalaBot::setParts(const Legs &legs)
{
    legsKoala = legs;
}

void KoalaBot::setParts(const Head &head)
{
    headKoala = head;
}

void KoalaBot::swapParts(Arms &parts)
{
    Arms tmp = armsKoala;
    armsKoala = parts;
    parts = tmp;
}

void KoalaBot::swapParts(Legs &parts)
{
    Legs tmp = legsKoala;
    legsKoala = parts;
    parts = tmp;
}

void KoalaBot::swapParts(Head &parts)
{
    Head tmp = headKoala;
    headKoala = parts;
    parts = tmp;
}

void KoalaBot::informations() const
{
    std::cout <<"[KoalaBot] "<< _serial << std::endl;
    armsKoala.informations();
    legsKoala.informations();
    headKoala.informations();
}

bool KoalaBot::status() const
{
    if (armsKoala.isFunctionnal() == true && legsKoala.isFunctionnal() == true && headKoala.isFunctionnal() == true)
        return true;
    return false;
}
