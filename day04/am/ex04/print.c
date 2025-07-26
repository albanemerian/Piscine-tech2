/*
** EPITECH PROJECT, 2025
** day4
** File description:
** print
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "print.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_normal(const char *str)
{
    puts(str);
}

static void my_revstr(char *str)
{
    int len = strlen(str);
    char temp = 0;

    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void print_reverse(const char *str)
{
    char *rev_str = malloc(strlen(str) + 1);

    if (rev_str == NULL)
        return;
    strcpy(rev_str, str);
    my_revstr(rev_str);
    puts(rev_str);
    free(rev_str);
}

void print_upper(const char *str)
{
    char *upper_str = malloc(strlen(str) + 1);

    if (upper_str == NULL)
        return;
    strcpy(upper_str, str);
    for (size_t i = 0; i < strlen(upper_str); i++) {
        upper_str[i] = toupper(upper_str[i]);
    }
    puts(upper_str);
    free(upper_str);
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*flag[PRINT_COUNT])(const char *str) = {
        &print_normal, &print_reverse, &print_upper, &print_42};

    for (int i = 0; i < PRINT_COUNT; i++) {
        if ((int)action == i)
            flag[i](str);
    }
}

// int main(void)
// {
//     print_normal("Hello world!");
//     print_reverse("Hello world!");
//     print_upper("Hello world!");
//     print_42("Hello world!");
//     do_action(PRINT_NORMAL, "Hello world!");
//     do_action(PRINT_REVERSE, "Hello world!");
//     do_action(PRINT_UPPER, "Hello world!");
//     do_action(PRINT_42, "Hello world!");
// }
