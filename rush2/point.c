/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (this == NULL)
        return;
    if (*args == NULL)
        return;
    this->x = va_arg(*args, int);
    if (*args == NULL)
        return;
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_str(PointClass *this)
{
    char *str = NULL;

    if (this == NULL)
        return NULL;
    asprintf(&str, "<Point (%d, %d)>", this->x, this->y);
    return str;
}

static Object *Point_add(PointClass *this, PointClass *other)
{
    PointClass *new_point = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_point = new(Point, this->x + other->x, this->y + other->y);
    return new_point;
}

static Object *Point_sub(PointClass *this, PointClass *other)
{
    PointClass *new_point = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_point = new(Point, this->x - other->x, this->y - other->y);
    return new_point;
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
