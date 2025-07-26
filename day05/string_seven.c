/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_seven
*/

#include "string.h"
#include <string.h>
#include <stddef.h>

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t copied = 0;
    size_t len = 0;
    size_t remaining = 0;

    if (this == NULL || this->str == NULL || s == NULL)
        return 0;
    len = strlen(this->str) + 1;
    if (pos >= len)
        return 0;
    remaining = len - pos;
    copied = (n < remaining) ? n : remaining;
    strncpy(s, this->str + pos, copied);
    return copied;
}
