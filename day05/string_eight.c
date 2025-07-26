/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_eight
*/

#include <stdbool.h>
#include <string.h>
#include "string.h"


const char *c_str(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return NULL;
    return this->str;
}
