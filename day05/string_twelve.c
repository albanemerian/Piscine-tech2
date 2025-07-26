/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_twelve
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <string.h>

int to_int(const string_t *this)
{
    char *temp = NULL;
    int val = 0;

    if (this == NULL || this->str == NULL)
        return 0;
    temp = strdup(this->str);
    val = atoi(temp);
    free(temp);
    return val;
}
