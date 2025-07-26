/*
** EPITECH PROJECT, 2025
** day4
** File description:
** uniq
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int is_unique(int *new_array, size_t size, int value)
{
    for (size_t j = 0; j < size; j++) {
        if (new_array[j] == value)
            return 0;
    }
    return 1;
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    int *new_array = malloc(sizeof(int) * nmemb);
    size_t size = 0;

    for (size_t i = 0; i < nmemb; i++) {
        if (is_unique(new_array, size, array[i])) {
            new_array[size] = array[i];
            size++;
        }
    }
    memcpy(array, new_array, size * sizeof(int));
    free(new_array);
    return size;
}

static int is_unique_element(void *array, size_t count,
    void *element, int (*compar)(const void *, const void *))
{
    for (size_t i = 0; i < count; i++) {
        if (compar((char *)array + i * sizeof(void *), element) == 0)
            return 0;
    }
    return 1;
}

size_t uniq_array(void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
    void *new_array = malloc(nmemb * size);
    size_t unique_count = 0;
    void *current_element = NULL;

    for (size_t i = 0; i < nmemb; i++) {
        current_element = (char *)array + i * size;
        if (is_unique_element(new_array, unique_count,
            current_element, compar)) {
            memcpy((char *)new_array + unique_count * size,
            current_element, size);
            unique_count++;
        }
    }
    memcpy(array, new_array, unique_count * size);
    free(new_array);
    return unique_count;
}
