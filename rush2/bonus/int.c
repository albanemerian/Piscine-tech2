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
#include "float.h"

typedef struct
{
    Class   base;
    int x;
} IntClass;

typedef struct
{
    Class   base;
    float   n;
}   FloatClass;


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

static Object *Int_add(IntClass *this, Object *other)
{
    FloatClass *new_float = NULL;

    if (this == NULL || other == NULL)
        return NULL;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        new_float = new(Int, this->x + int_other->x);
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        new_float = new(Float, this->x + float_other->n);
    }
    return new_float;
}

static Object *Int_sub(IntClass *this, Object *other)
{
    FloatClass *new_float = NULL;

    if (this == NULL || other == NULL)
        return NULL;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        new_float = new(Int, this->x - int_other->x);
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        new_float = new(Float, this->x - float_other->n);
    }
    return new_float;
}

static Object *Int_mul(IntClass *this, Object *other)
{
    FloatClass *new_float = NULL;

    if (this == NULL || other == NULL)
        return NULL;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        new_float = new(Int, this->x * int_other->x);
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        new_float = new(Float, this->x * float_other->n);
    }
    return new_float;
}

static Object *Int_div(IntClass *this, Object *other)
{
    FloatClass *new_float = NULL;

    if (this == NULL || other == NULL)
        return NULL;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        if (int_other->x == 0)
            return NULL;
        new_float = new(Int, this->x / int_other->x);
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        if (float_other->n == 0)
            return NULL;
        new_float = new(Float, this->x / float_other->n);
    }
    return new_float;
}

static bool Int_eq(IntClass *this, Object *other)
{
    if (this == NULL || other == NULL)
        return false;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        return this->x == int_other->x;
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        return this->x == float_other->n;
    }
    return false;
}

static bool Int_gt(IntClass *this, Object *other)
{
    if (this == NULL || other == NULL)
        return false;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        return this->x > int_other->x;
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        return this->x > float_other->n;
    }
    return false;
}

static bool Int_lt(IntClass *this, Object *other)
{
    if (this == NULL || other == NULL)
        return false;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        return this->x < int_other->x;
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        return this->x < float_other->n;
    }
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
