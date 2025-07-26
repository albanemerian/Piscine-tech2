/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** test_main_void
*/

#include "void.h"
#include <stdio.h>


int main(void)
{
    Void v1, v2, result;

    int a = 5, b = 10;
    init_void(&v1, &a, INT);
    init_void(&v2, &b, INT);
    add_void(&result, &v1, &v2);
    printf("INT: %d + %d = %d\n", *(int *)v1.value, *(int *)v2.value, *(int *)result.value);
    free_void(&v1);
    free_void(&v2);
    free_void(&result);

    float x = 5.5, y = 10.5;
    init_void(&v1, &x, FLOAT);
    init_void(&v2, &y, FLOAT);
    add_void(&result, &v1, &v2);
    printf("FLOAT: %.2f + %.2f = %.2f\n", *(float *)v1.value, *(float *)v2.value, *(float *)result.value);
    free_void(&v1);
    free_void(&v2);
    free_void(&result);

    short s1 = 3, s2 = 7;
    init_void(&v1, &s1, SHORT);
    init_void(&v2, &s2, SHORT);
    add_void(&result, &v1, &v2);
    printf("SHORT: %d + %d = %d\n", *(short *)v1.value, *(short *)v2.value, *(short *)result.value);
    free_void(&v1);
    free_void(&v2);
    free_void(&result);

    return 0;
}

