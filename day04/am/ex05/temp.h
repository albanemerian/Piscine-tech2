/*
** EPITECH PROJECT, 2025
** day4
** File description:
** temp
*/

#include <stdlib.h>

#ifndef TEMP_H_
    #define TEMP_H_

void disp_int_array(const int *array, size_t nmemb);
void sort_array(void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));
void sort_int_array(int *array, size_t nmemb);
size_t uniq_int_array(int *array, size_t nmemb);
size_t uniq_array(void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));
void disp_array(const void *array, size_t nmemb,
    size_t size, void (*print)(const void *));
#endif /* !TEMP_H_ */
