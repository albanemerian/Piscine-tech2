/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_three
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "string.h"

char at(const string_t *this, size_t pos)
{
    int len = 0;

    if (this == NULL || this->str == NULL || pos < 0)
        return -1;
    len = strlen(this->str);
    if (pos >= len)
        return -1;
    return this->str[pos];
}
