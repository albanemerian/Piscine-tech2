/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_four
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>


void clear(string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    free(this->str);
    this->str = strdup("");
}
