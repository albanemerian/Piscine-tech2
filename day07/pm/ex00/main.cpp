/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** main
*/

#include "Skat.hpp"
#include <iostream>

int main()
{
    Skat s("John", 10);
    Skat t("Doe", 5);

    s.status();
    t.status();

    int sStock = s.stimPaks();
    int tStock = t.stimPaks();

    t.shareStimPaks(5, sStock);
    t.shareStimPaks(20, sStock);
    s.shareStimPaks(5, tStock);
    t.shareStimPaks(20, s.stimPaks());

    s.status();
    t.status();

    return 0;
}
