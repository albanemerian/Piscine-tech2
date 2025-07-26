/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_one
*/

#include "string.h"
#include <string.h>
#include <stdlib.h>

void init_end(string_t *this)
{
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    this->split_c = &split_c;
    this->split_s = &split_s;
    this->print = &print;
}

void string_init(string_t *this, const char *s)
{
    int len = strlen(s);

    this->str = malloc(sizeof(char) * (len + 1));
    if (this->str == NULL)
        exit(84);
    strcpy(this->str, s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    init_end(this);
}

void string_destroy(string_t *this)
{
    if (this != NULL && this->str != NULL) {
        free(this->str);
    }
}
