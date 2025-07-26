/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 01
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (this == NULL)
        return;
    if (*args == NULL)
        return;
    this->x = va_arg(*args, int);
    if (*args == NULL)
        return;
    this->y = va_arg(*args, int);
    if (*args == NULL)
        return;
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = NULL;

    if (this == NULL)
        return NULL;
    asprintf(&str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return str;
}

static Object *Vertex_add(VertexClass *this, VertexClass *other)
{
    VertexClass *new_vertex = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_vertex = new(Vertex, this->x + other->x, this->y + other->y, this->z + other->z);
    return new_vertex;
}

static Object *Vertex_sub(VertexClass *this, VertexClass *other)
{
    VertexClass *new_vertex = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_vertex = new(Vertex, this->x - other->x, this->y - other->y, this->z - other->z);
    return new_vertex;
}

static Object *Vertex_mul(VertexClass *this, VertexClass *other)
{
    VertexClass *new_vertex = NULL;

    if (this == NULL || other == NULL)
        return NULL;
    new_vertex = new(Vertex, this->x * other->x, this->y * other->y, this->z * other->z);
    return new_vertex;
}

static Object *Vertex_div(VertexClass *this, VertexClass *other)
{
    VertexClass *new_vertex = NULL;

    if (this == NULL || other == NULL)
        return false;
    if (other->x == 0 || other->y == 0 || other->z == 0)
        return NULL;
    new_vertex = new(Vertex, this->x / other->x, this->y / other->y, this->z / other->z);
    return new_vertex;
}

static bool Vertex_eq(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->x == other->x && this->y == other->y && this->z == other->z)
        return true;
    return false;
}

static bool Vertex_gt(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->x > other->x && this->y > other->y && this->z > other->z)
        return true;
    return false;
}

static bool Vertex_lt(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    if (this->x < other->x && this->y < other->y && this->z < other->z)
        return true;
    return false;
}

static const VertexClass    _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = (binary_operator_t)&Vertex_mul,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = (binary_comparator_t)&Vertex_eq,
        .__gt__ = (binary_comparator_t)&Vertex_gt,
        .__lt__ = (binary_comparator_t)&Vertex_lt,
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
