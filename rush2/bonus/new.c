/*
** EPITECH PROJECT, 2025
** rush02
** File description:
** new
*/

#include "new.h"
#include "player.h"

Object *va_new(const Class *class, va_list *ap)
{
    Object *object = NULL;

    if (class == NULL)
        return NULL;
    object = malloc(class->__size__);
    if (object == NULL)
        raise("Memory error");
    memcpy(object, class, class->__size__);
    if (class->__ctor__ != NULL) {
        class->__ctor__(object, ap);
    }
    return object;
}

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *object = NULL;

    if (class == NULL)
        return NULL;
    object = malloc(class->__size__);
    if (object == NULL)
        raise("Memory error");
    memcpy(object, class, class->__size__);
    if (class->__ctor__ != NULL) {
        va_start(ap, class);
        class->__ctor__(object, &ap);
        va_end(ap);
    }
    return object;
}

void delete(Object *ptr)
{
    Class *class;

    if (ptr == NULL)
        return;
    class = (Class *)ptr;
    if (class->__dtor__ != NULL) {
        class->__dtor__(ptr);
    }
    free(ptr);
}
