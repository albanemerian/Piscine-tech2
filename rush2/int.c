/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH2-alban.roussee
** File description:
** int
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "int.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class   base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (this == NULL)
        return;
    if (args == NULL)
        return;
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_str(IntClass *this)
{
    char *str = NULL;

    if (this == NULL)
        return NULL;
    asprintf(&str, "<Int (%d)>", this->x);
    return str;
}

static Object *Int_add(IntClass *this, IntClass *other)
{
    IntClass *new_int = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_int = new(Int, this->x + other->x);
    return new_int;
}

static Object *Int_sub(IntClass *this, IntClass *other)
{
    IntClass *new_int = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_int = new(Int, this->x - other->x);
    return new_int;
}

static Object *Int_mul(IntClass *this, IntClass *other)
{
    IntClass *new_int = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_int = new(Int, this->x * other->x);
    return new_int;
}

static Object *Int_div(IntClass *this, IntClass *other)
{
    IntClass *new_int = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    if (other->x == 0)
        raise("Division by 0");
    new_int = new(Int, this->x / other->x);
    return new_int;
}

static bool Int_eq(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->x == other->x)
        return true;
    return false;
}

static bool Int_gt(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->x > other->x)
        return true;
    return false;
}

static bool Int_lt(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->x < other->x)
        return true;
    return false;
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;
