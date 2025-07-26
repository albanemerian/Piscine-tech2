/*
** EPITECH PROJECT, 2025
** day4
** File description:
** tests_mul_div
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

// Declaration of the functions
void mul_div_long(int a, int b, int *mul, int *div);
void mul_div_short(int *a, int *b);

Test(mul_div_long, valid_division)
{
    int a = 6;
    int b = 3;
    int mul, div;

    mul_div_long(a, b, &mul, &div);
    cr_assert_eq(mul, 18, "Expected 6 * 3 to be 18, but got %d", mul);
    cr_assert_eq(div, 2, "Expected 6 / 3 to be 2, but got %d", div);
}

Test(mul_div_long, division_by_zero)
{
    int a = 6;
    int b = 0;
    int mul, div;

    mul_div_long(a, b, &mul, &div);
    cr_assert_eq(mul, 0, "Expected 6 * 0 to be 0, but got %d", mul);
    cr_assert_eq(div, 42, "Expected division by zero to return 42, but got %d", div);
}

Test(mul_div_short, valid_division)
{
    int a = 6;
    int b = 3;
    int mul = a;
    int div = b;

    mul_div_short(&mul, &div);
    cr_assert_eq(mul, 18, "Expected 6 * 3 to be 18, but got %d", mul);
    cr_assert_eq(div, 2, "Expected 6 / 3 to be 2, but got %d", div);
}

Test(mul_div_short, division_by_zero)
{
    int a = 6;
    int b = 0;
    int mul = a;
    int div = b;

    mul_div_short(&mul, &div);
    cr_assert_eq(mul, 0, "Expected 6 * 0 to be 0, but got %d", mul);
    cr_assert_eq(div, 42, "Expected division by zero to return 42, but got %d", div);
}
