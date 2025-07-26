/*
** EPITECH PROJECT, 2025
** day4
** File description:
** mul_div
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    if (b != 0) {
        *mul = a * b;
        *div = a / b;
    } else {
        *mul = 0;
        *div = 42;
    }
}

void mul_div_short(int *a, int *b)
{
    int aa = *a;
    int bb = *b;

    *a = aa * bb;
    if (bb != 0)
        *b = aa / bb;
    else
        *b = 42;
}

// static void test_long(void) {

//     int a = 13;
//     int b = 4;
//     int mul;
//     int div;
//     mul_div_long (a, b, &mul, &div);
//     printf ( " %d * %d = %d \n", a, b, mul);
//     printf ( " %d / %d = %d \n", a, b, div);
// }

// static void test_long_two(void) {

//     int a = 12;
//     int b = 0;
//     int mul;
//     int div;
//     mul_div_long (a, b, &mul, &div);
//     printf (" %d * %d = %d \n", a, b, mul);
//     printf (" %d / %d = %d \n", a, b, div);
// }

// static void test_short(void) {
//     int a = -3;
//     int b = 7;
//     int mul_res = a;
//     int div_res = b;

//     mul_div_short (& mul_res , & div_res ) ;
//     printf (" %d * %d = %d \n", a, b, mul_res);
//     printf (" %d / %d = %d \n", a, b, div_res);
// }

// int main ( void )
// {
//     test_long();
//     test_long_two();
//     test_short();
//     return (0);
// }
