/*
** EPITECH PROJECT, 2025
** day4
** File description:
** tests_concat
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdlib.h>

// Declaration of the functions
void concat_strings(const char *str1, const char *str2, char **res);

typedef struct {
    const char *str1;
    const char *str2;
    char *res;
} concat_t;

void concat_struct(concat_t *str);

Test(concat_strings, concatenate_two_strings)
{
    const char *str1 = "Hello, ";
    const char *str2 = "World!";
    char *res = NULL;

    concat_strings(str1, str2, &res);
    cr_assert_str_eq(res, "Hello, World!", "Expected 'Hello, World!', but got '%s'", res);
    free(res);
}

Test(concat_struct, concatenate_struct_strings)
{
    concat_t str = { "Hello, ", "World!", NULL };

    concat_struct(&str);
    cr_assert_str_eq(str.res, "Hello, World!", "Expected 'Hello, World!', but got '%s'", str.res);
    free(str.res);
}
