/*
** EPITECH PROJECT, 2025
** rush02
** File description:
** tests_vertex
*/

#include "../new.h"
#include "../vertex.h"
#include <criterion/criterion.h>

Test(new, test_new_vertex)
{
    Object *object = new(Vertex, 42, -42, 0);

    cr_assert_not_null(object);
    cr_assert_str_eq(str(object), "<Vertex (42, -42, 0)>");
}

Test(addition, test_addition_vertex)
{
    Object *object = new(Vertex, 42, -42, 0);
    Object *object2 = new(Vertex, 42, -42, 0);
    Object *result = addition(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Vertex (84, -84, 0)>");
}

Test(subtraction, test_subtraction_vertex)
{
    Object *object = new(Vertex, 42, -42, 0);
    Object *object2 = new(Vertex, 42, -42, 0);
    Object *result = subtraction(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Vertex (0, 0, 0)>");
}
