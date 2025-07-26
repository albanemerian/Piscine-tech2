/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_ten
*/

#include <string.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *found = NULL;

    if (this == NULL || str == NULL || this->str == NULL || str->str == NULL ||
        pos >= strlen(this->str) || pos < 0)
        return -1;
    found = strstr(this->str + pos, str->str);
    if (found == NULL)
        return -1;
    return found - this->str;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *found = NULL;

    if (this == NULL || str == NULL || this->str == NULL ||
        pos >= strlen(this->str) || pos < 0)
        return -1;
    found = strstr(this->str + pos, str);
    if (found == NULL)
        return -1;
    return found - this->str;
}
