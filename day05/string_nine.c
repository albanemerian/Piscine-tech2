/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string.nine
*/

#include <stdio.h>
#include <string.h>
#include "string.h"

int empty(const string_t *this)
{
    if (this == NULL || this->str == NULL || strlen(this->str) == 0)
        return 1;
    return 0;
}
