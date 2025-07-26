/*
** EPITECH PROJECT, 2025
** day4
** File description:
** sort
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort_int_array(int *array, size_t nmemb)
{
    int n = nmemb;

    qsort(array, n, sizeof(array[0]), comp);
}

void sort_array(void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
    qsort(array, nmemb, size, compar);
}
