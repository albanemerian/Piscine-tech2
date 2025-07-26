/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 04
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "new.h"
#include "int.h"
#include "float.h"

typedef struct
{
    Class   base;
    float   n;
}   FloatClass;

typedef struct
{
    Class   base;
    int x;
} IntClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (this == NULL)
        return;
    if (*args == NULL)
        return;
    this->n = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_str(FloatClass *this)
{
    char *str = NULL;

    if (this == NULL)
        return NULL;
    asprintf(&str, "<Float (%g)>", this->n);
    return str;
}

static Object *Float_add(FloatClass *this, Object *other)
{
    FloatClass *new_float = NULL;

    if (this == NULL || other == NULL)
        return NULL;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        new_float = new(Float, this->n + int_other->x);
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        new_float = new(Float, this->n + float_other->n);
    }
    return new_float;
}

static Object *Float_sub(FloatClass *this, Object *other)
{
    FloatClass *new_float = NULL;

    if (this == NULL || other == NULL)
        return NULL;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        new_float = new(Float, this->n - int_other->x);
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        new_float = new(Float, this->n - float_other->n);
    }
    return new_float;
}

static Object *Float_mul(FloatClass *this, Object *other)
{
    FloatClass *new_float = NULL;

    if (this == NULL || other == NULL)
        return NULL;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        new_float = new(Float, this->n * int_other->x);
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        new_float = new(Float, this->n * float_other->n);
    }
    return new_float;
}

static Object *Float_div(FloatClass *this, Object *other)
{
    FloatClass *new_float = NULL;

    if (this == NULL || other == NULL)
        return NULL;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        if (int_other->x == 0)
            return NULL;
        new_float = new(Float, this->n / int_other->x);
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        if (float_other->n == 0)
            return NULL;
        new_float = new(Float, this->n / float_other->n);
    }
    return new_float;
}

static bool Float_eq(FloatClass *this, Object *other)
{
    if (this == NULL || other == NULL)
        return false;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        return this->n == int_other->x;
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        return this->n == float_other->n;
    }
    return false;
}

static bool Float_gt(FloatClass *this, Object *other)
{
    if (this == NULL || other == NULL)
        return false;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        return this->n > int_other->x;
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        return this->n > float_other->n;
    }
    return false;
}

static bool Float_lt(FloatClass *this, Object *other)
{
    if (this == NULL || other == NULL)
        return false;

    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        IntClass *int_other = (IntClass *)other;
        return this->n < int_other->x;
    } else if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        FloatClass *float_other = (FloatClass *)other;
        return this->n < float_other->n;
    }
    return false;
}

static const FloatClass    _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt,
    },
    .n = 0
};

const Class *Float = (const Class *)&_description;
