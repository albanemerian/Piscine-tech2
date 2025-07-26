/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH2-alban.roussee
** File description:
** char
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "char.h"
#include "new.h"

typedef struct 
{
    Class   base;
    char c;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (this == NULL)
        return;
    if (args == NULL)
        return;
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_str(CharClass *this)
{
    char *str = NULL;

    if (this == NULL)
        return NULL;
    asprintf(&str, "<Char (%c)>", this->c);
    return str;
}

static Object *Char_add(CharClass *this, CharClass *other)
{
    CharClass *new_char = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_char = new(Char, this->c + other->c);
    return new_char;
}

static Object *Char_sub(CharClass *this, CharClass *other)
{
    CharClass *new_char = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_char = new(Char, this->c - other->c);
    return new_char;
}

static Object *Char_mul(CharClass *this, CharClass *other)
{
    CharClass *new_char = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_char = new(Char, this->c * other->c);
    return new_char;
}

static Object *Char_div(CharClass *this, CharClass *other)
{
    CharClass *new_char = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    if (other->c == 0)
        raise("Division by 0");
    new_char = new(Char, this->c / other->c);
    return new_char;
}

static bool Char_eq(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->c == other->c)
        return true;
    return false;
}

static bool Char_lt(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->c < other->c)
        return true;
    return false;
}

static bool Char_gt(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->c > other->c)
        return true;
    return false;
}

static const CharClass _descrpition = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt,
    },
    .c = 0
};

const Class *Char = (const Class *)&_descrpition;
