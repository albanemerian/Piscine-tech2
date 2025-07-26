/*
** EPITECH PROJECT, 2025
** rush02
** File description:
** tests_char
*/

#include "../new.h"
#include "../char.h"
#include <criterion/criterion.h>

Test(str, test_char)
{
    Object *a = new(Char, 'a');

    cr_assert_str_eq(str(a), "<Char (a)>");
}

Test(addition, test_char_addition)
{
    Object *a = new(Char, 'a');
    Object *b = new(Char, 1);
    Object *c = addition(a, b);

    cr_assert_str_eq(str(c), "<Char (b)>");
}

Test(addition_null, test_char_addition_null)
{
    Object *a = new(Char, 'a');
    Object *c = addition(a, NULL);

    cr_assert_null(c);
}

Test(subtraction, test_char_substraction)
{
    Object *a = new(Char, 'B');
    Object *b = new(Char, 1);
    Object *c = subtraction(a, b);

    cr_assert_str_eq(str(c), "<Char (A)>");
}

Test(subtraction_null, test_char_subtraction_null)
{
    Object *a = new(Char, 'B');
    Object *c = subtraction(a, NULL);

    cr_assert_null(c);
}

Test(multiplication, test_char_multiplication)
{
    Object *a = new(Char, 'a');
    Object *b = new(Char, 1);
    Object *c = multiplication(a, b);

    cr_assert_str_eq(str(c), "<Char (a)>");
}

Test(multiplication_null, test_char_multiplication_null)
{
    Object *a = new(Char, 'a');
    Object *c = multiplication(a, NULL);

    cr_assert_null(c);
}

Test(division, test_char_division)
{
    Object *a = new(Char, 'z');
    Object *b = new(Char, 2);
    Object *c = division(a, b);

    cr_assert_str_eq(str(c), "<Char (=)>");
}

Test(division_null, test_char_division_null)
{
    Object *a = new(Char, 'z');
    Object *c = division(a, NULL);

    cr_assert_null(c);
}

// Test(division_by_zero, test_char_division_by_zero)
// {
//     Object *a = new(Char, 'z');
//     Object *b = new(Char, 0);

//     cr_assert_throw(division(a, b), "Division by 0");
// }

Test(eq, test_char_eq)
{
    Object *a = new(Char, 'a');
    Object *b = new(Char, 'b');
    bool c = eq(a, b);

    cr_assert_eq(c, false);
}

Test(eq_null, test_char_eq_null)
{
    Object *a = new(Char, 'a');
    bool c = eq(a, NULL);

    cr_assert_eq(c, false);
}

Test(gt, test_char_gt)
{
    Object *a = new(Char, 'a');
    Object *b = new(Char, 'b');
    bool c = gt(a, b);

    cr_assert_eq(c, false);
}

Test(gt_null, test_char_gt_null)
{
    Object *a = new(Char, 'a');
    bool c = gt(a, NULL);

    cr_assert_eq(c, false);
}

Test(lt, test_char_lt)
{
    Object *a = new(Char, 'a');
    Object *b = new(Char, 'b');
    bool c = lt(a, b);

    cr_assert_eq(c, true);
}

Test(lt_null, test_char_lt_null)
{
    Object *a = new(Char, 'a');
    bool c = lt(a, NULL);

    cr_assert_eq(c, false);
}

Test(new, test_char_new)
{
    Object *a = new(Char, 'a');

    cr_assert_str_eq(str(a), "<Char (a)>");
}


Test(char, test_char)
{
    Object *a = new(Char, 'a');

    cr_assert_str_eq(str(a), "<Char (a)>");
}
