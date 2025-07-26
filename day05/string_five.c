/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_five
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>

int length(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return (-1);
    return (strlen(this->str));
}
