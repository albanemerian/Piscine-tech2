/*
** EPITECH PROJECT, 2025
** rush02
** File description:
** tests_int
*/

#include "../new.h"
#include "../int.h"
#include <criterion/criterion.h>

Test(str, test_str_int)
{
    Object *object = new(Int, 42);

    cr_assert_not_null(object);
    cr_assert_str_eq(str(object), "<Int (42)>");
}

Test(addition, test_addition_int)
{
    Object *object = new(Int, 42);
    Object *object2 = new(Int, 42);
    Object *result = addition(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Int (84)>");
}

Test(subtraction, test_subtraction_int)
{
    Object *object = new(Int, 42);
    Object *object2 = new(Int, 42);
    Object *result = subtraction(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Int (0)>");
}

Test(multiplication, test_multiplication_int)
{
    Object *object = new(Int, 42);
    Object *object2 = new(Int, 42);
    Object *result = multiplication(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Int (1764)>");
}

Test(division, test_division_int)
{
    Object *object = new(Int, 42);
    Object *object2 = new(Int, 42);
    Object *result = division(object, object2);

    cr_assert_not_null(result);
    cr_assert_str_eq(str(result), "<Int (1)>");
}

Test(eq, test_eq_int)
{
    Object *object = new(Int, 42);
    Object *object2 = new(Int, 42);
    bool result = eq(object, object2);

    cr_assert_eq(result, true);
}

Test(gt, test_gt_int)
{
    Object *object = new(Int, 42);
    Object *object2 = new(Int, 42);
    bool result = gt(object, object2);

    cr_assert_eq(result, false);
}

Test(lt, test_lt_int)
{
    Object *object = new(Int, 42);
    Object *object2 = new(Int, 42);
    bool result = lt(object, object2);

    cr_assert_eq(result, false);
}

Test(addition_null, test_int_addition_null)
{
    Object *a = new(Int, 42);
    Object *c = addition(a, NULL);

    cr_assert_null(c);
}

Test(subtraction_null, test_int_subtraction_null)
{
    Object *a = new(Int, 42);
    Object *c = subtraction(a, NULL);

    cr_assert_null(c);
}

Test(multiplication_null, test_int_multiplication_null)
{
    Object *a = new(Int, 42);
    Object *c = multiplication(a, NULL);

    cr_assert_null(c);
}

Test(division_null, test_int_division_null)
{
    Object *a = new(Int, 42);
    Object *c = division(a, NULL);

    cr_assert_null(c);
}

// Test(division_by_zero, test_int_division_by_zero)
// {
//     Object *a = new(Int, 42);
//     Object *b = new(Int, 0);

//     cr_assert_throw(division(a, b), "Division by 0");
// }

Test(eq_null, test_int_eq_null)
{
    Object *a = new(Int, 42);
    bool c = eq(a, NULL);

    cr_assert_eq(c, false);
}

Test(gt_null, test_int_gt_null)
{
    Object *a = new(Int, 42);
    bool c = gt(a, NULL);

    cr_assert_eq(c, false);
}

Test(lt_null, test_int_lt_null)
{
    Object *a = new(Int, 42);
    bool c = lt(a, NULL);

    cr_assert_eq(c, false);
}
