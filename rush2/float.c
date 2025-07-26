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
#include "float.h"

typedef struct
{
    Class   base;
    float   n;
}   FloatClass;

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

static Object *Float_add(FloatClass *this, FloatClass *other)
{
    FloatClass *new_point = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_point = new(Float, this->n + other->n);
    return new_point;
}

static Object *Float_sub(FloatClass *this, FloatClass *other)
{
    FloatClass *new_point = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_point = new(Float, this->n - other->n);
    return new_point;
}

static Object *Float_mul(FloatClass *this, FloatClass *other)
{
    FloatClass *new_point = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_point = new(Float, this->n * other->n);
    return new_point;
}

static Object *Float_div(FloatClass *this, FloatClass *other)
{
    FloatClass *new_point = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    if (other->n == 0)
        raise("Division by zero");
    new_point = new(Float, this->n / other->n);
    return new_point;
}

static bool Float_eq(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->n == other->n)
        return true;
    return false;
}

static bool Float_gt(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->n > other->n)
        return true;
    return false;
}

static bool Float_lt(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->n < other->n)
        return true;
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
