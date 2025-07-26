/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_two
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>

void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL || this == str)
        return;
    if (this->str != NULL)
        free(this->str);
    if (str->str != NULL)
        this->str = strdup(str->str);
    else
        this->str = NULL;
}

void assign_c(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    if (s != NULL)
        this->str = strdup(s);
    else
        this->str = NULL;
}

void append_s(string_t *this, const string_t *ap)
{
    size_t new_len = 0;

    if (this == NULL || ap == NULL || this == ap)
        return;
    if (ap->str != NULL) {
        new_len = strlen(this->str) + strlen(ap->str) + 1;
        this->str = realloc(this->str, new_len);
        this->str = strcat(this->str, ap->str);
    }
}

void append_c(string_t *this, const char *ap)
{
    size_t new_len = 0;

    if (this == NULL)
        return;
    if (ap != NULL) {
        new_len = strlen(this->str) + strlen(ap) + 1;
        this->str = realloc(this->str, new_len);
        strcat(this->str, ap);
    }
}
