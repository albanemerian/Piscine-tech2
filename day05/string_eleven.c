/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_eleven
*/

#include <string.h>
#include "string.h"
#include <stdlib.h>

char *copy_from_pos(const char *source, int pos, char *dest)
{
    int len = strlen(source) - pos;

    dest = malloc(sizeof(char) * (len + 1));
    strcpy(dest, source + pos);
    return dest;
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    int len = 0;
    char *temp = NULL;

    if (this == NULL || this->str == NULL || str == NULL || pos < 0)
        return;
    len = strlen(this->str);
    this->str = realloc(this->str, (len + strlen(str)) + 1);
    if (len < pos) {
        strcat(this->str, str);
        return;
    }
    temp = copy_from_pos(this->str, pos, temp);
    strncpy(this->str + pos, str, strlen(str));
    this->str[pos + strlen(str)] = '\0';
    strcat(this->str, temp);
    free(temp);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    int len = 0;
    char *temp = NULL;

    if (this == NULL || this->str == NULL || str == NULL
        || str->str == NULL || pos < 0)
        return;
    len = strlen(this->str);
    this->str = realloc(this->str, (len + strlen(str->str)) + 1);
    if (len < pos) {
        strcat(this->str, str->str);
        return;
    }
    temp = copy_from_pos(this->str, pos, temp);
    strncpy(this->str + pos, str->str, strlen(str->str));
    this->str[pos + strlen(str->str)] = '\0';
    strcat(this->str, temp);
    free(temp);
}
