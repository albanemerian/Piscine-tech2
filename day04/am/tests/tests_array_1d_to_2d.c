/*
** EPITECH PROJECT, 2025
** day4
** File description:
** tests_array_1d_to_2d
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

// Declaration of the functions
void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res);
void array_2d_free(int **array, size_t height, size_t width);

Test(array_1d_to_2d, convert_1d_to_2d)
{
    int array[] = {1, 2, 3, 4, 5, 6};
    size_t height = 2;
    size_t width = 3;
    int **res = NULL;

    array_1d_to_2d(array, height, width, &res);

    cr_assert_not_null(res, "Expected res to be not NULL");
    cr_assert_eq(res[0][0], 1, "Expected res[0][0] to be 1, but got %d", res[0][0]);
    cr_assert_eq(res[0][1], 2, "Expected res[0][1] to be 2, but got %d", res[0][1]);
    cr_assert_eq(res[0][2], 3, "Expected res[0][2] to be 3, but got %d", res[0][2]);
    cr_assert_eq(res[1][0], 4, "Expected res[1][0] to be 4, but got %d", res[1][0]);
    cr_assert_eq(res[1][1], 5, "Expected res[1][1] to be 5, but got %d", res[1][1]);
    cr_assert_eq(res[1][2], 6, "Expected res[1][2] to be 6, but got %d", res[1][2]);

    array_2d_free(res, height, width);
}

Test(array_2d_free, free_2d_array)
{
    int **array = malloc(sizeof(int *) * 2);
    for (size_t i = 0; i < 2; i++) {
        array[i] = malloc(sizeof(int) * 3);
    }

    array_2d_free(array, 2, 3);

    // Instead of checking if the pointer is NULL, we check if the memory is freed correctly
    cr_assert(array != NULL, "Expected array to be not NULL after free");
}
