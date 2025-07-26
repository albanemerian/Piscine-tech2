/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_fourteen
*/

#include <string.h>
#include "string.h"

void print(const string_t *this)
{
    if (this != NULL && this->str != NULL) {
        printf("%s", this->str);
    }
}
