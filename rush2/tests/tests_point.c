/*
** EPITECH PROJECT, 2025
** rush02
** File description:
** tests_point
*/

#include "../point.h"
#include "../new.h"
#include <criterion/criterion.h>

Test(new, test_new_point)
{
    Object *object = new(Point, 42, -42);

    cr_assert_not_null(object);
    cr_assert_str_eq(str(object), "<Point (42, -42)>");
}

Test(addition, test_addition_point)
{
    Object *object = new(Point, 42, -42);
    Object *object2 = new(Point, 42, -42);
    Object *result = addition(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Point (84, -84)>");
}

Test(subtraction, test_subtraction_point)
{
    Object *object = new(Point, 42, -42);
    Object *object2 = new(Point, 42, -42);
    Object *result = subtraction(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Point (0, 0)>");
}
