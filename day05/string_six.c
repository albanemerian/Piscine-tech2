/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_six
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL)
        return (-1);
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || str == NULL)
        return (-1);
    return (strcmp(this->str, str));
}
