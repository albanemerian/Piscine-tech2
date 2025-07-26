/*
** EPITECH PROJECT, 2025
** day4
** File description:
** main
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "temp.h"

static int test_comp(const void *a, const void *b)
{
    return (strcmp(*(char **)a, *(char **)b));
}

static void test_disp(const void *str)
{
    printf("%s ", *(char **)str);
}

int main(int argc, const char **argv)
{
    printf("argv: ");
    disp_array(argv, argc, sizeof(*argv), &test_disp);
    printf("\n");
    argc = uniq_array(argv, argc, sizeof(*argv), &test_comp);
    printf("uniq: ");
    disp_array(argv, argc, sizeof(*argv), &test_disp);
    printf("\n");
    sort_array(argv, argc, sizeof(*argv), &test_comp);
    printf("sort: ");
    disp_array(argv, argc, sizeof(*argv), &test_disp);
    printf("\n");
    return (0);
}

// size_t uniq_array(void *array, size_t nmemb, size_t size,
//     int (*compar)(const void *, const void *))
// {
//     void *new_array = malloc(nmemb * size);
//     size_t unique_count = 0;
//     int is_unique = 0;

//     for (size_t i = 0; i < nmemb; i++) {
//         is_unique = 1;
//         for (size_t j = 0; j < unique_count; j++) {
//             if (compar((char *)new_array + j * size,
//                 (char *)array + i * size) == 0) {
//                 is_unique = 0;
//                 break;
//             }
//         }
//         if (is_unique) {
//             memcpy((char *)new_array + unique_count * size,
//             (char *)array + i * size, size);
//             unique_count++;
//         }
//     }
//     memcpy(array, new_array, unique_count * size);
//     free(new_array);
//     return unique_count;
// }

// size_t uniq_int_array(int *array, size_t nmemb)
// {
//     int *new_array = malloc(sizeof(int) * nmemb);
//     size_t size = 0;
//     size_t j = 0;

//     for (size_t i = 0; i < nmemb; i++) {
//         j = 0;
//         for (; j < size; j++)
//             if (new_array[j] == array[i])
//                 break;
//         if (j == size) {
//             new_array[size] = array[i];
//             size++;
//         }
//     }
//     return size;
// }
