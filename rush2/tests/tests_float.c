/*
** EPITECH PROJECT, 2025
** rush02
** File description:
** tests_float
*/

#include "../new.h"
#include "../float.h"
#include <criterion/criterion.h>

Test(str, test_str_float)
{
    Object *object = new(Float, 42.42);

    cr_assert_not_null(object);
    cr_assert_str_eq(str(object), "<Float (42.42)>");
}

Test(addition, test_addition_float)
{
    Object *object = new(Float, 42.42);
    Object *object2 = new(Float, 42.42);
    Object *result = addition(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Float (84.84)>");
}

Test(subtraction, test_subtraction_float)
{
    Object *object = new(Float, 42.42);
    Object *object2 = new(Float, 42.42);
    Object *result = subtraction(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Float (0)>");
}

Test(multiplication, test_multiplication_float)
{
    Object *object = new(Float, 42.42);
    Object *object2 = new(Float, 42.42);
    Object *result = multiplication(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Float (1799.46)>");
}

Test(division, test_division_float)
{
    Object *object = new(Float, 42.42);
    Object *object2 = new(Float, 42.42);
    Object *result = division(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Float (1)>");
}

Test(eq, test_eq_float)
{
    Object *object = new(Float, 42.42);
    Object *object2 = new(Float, 42.42);
    bool result = eq(object, object2);

    cr_assert_eq(result, true);
}

Test(gt, test_gt_float)
{
    Object *object = new(Float, 42.42);
    Object *object2 = new(Float, 42.42);
    bool result = gt(object, object2);

    cr_assert_eq(result, false);
}

Test(lt, test_lt_float)
{
    Object *object = new(Float, 42.42);
    Object *object2 = new(Float, 42.42);
    bool result = lt(object, object2);

    cr_assert_eq(result, false);
}
