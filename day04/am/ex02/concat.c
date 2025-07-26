/*
** EPITECH PROJECT, 2025
** day4
** File description:
** concat
*/

#include "concat.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(*res, str1);
    strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    str->res = malloc(strlen(str->str1) + strlen(str->str2) + 1);
    strcpy(str->res, str->str1);
    strcat(str->res, str->str2);
}


// static void test_concat_strings(void) {

//     char str1 [] = "I find your lack of faith ...";
//     char str2 [] = " disturbing.";
//     char * res = NULL ;
//     concat_strings(str1, str2, &res);
//     printf("%s \n", res);
//     free(res);
// }

// static void test_concat_struct(void) {

//     char str1 [] = "These aren 't the Droids";
//     char str2 [] = " you ' re looking for .";
//     concat_t str = {
//         .str1 = str1,
//         .str2 = str2,
//         .res = NULL
//     };
//     concat_struct(&str);
//     printf("%s \n", str.res);
//     free(str.res);
// }

// int main (void) {
//     test_concat_strings();
//     test_concat_struct();
//     return (0) ;
// }
