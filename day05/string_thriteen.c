/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** string_thriteen
*/

// #include <string.h>
#include "string.h"
#include <stdlib.h>
#include <string.h>

static int counter(char *str, char separator)
{
    int count = 0;
    int let_for = 0;

    if (str[0] == '\0') // Handle empty string case
        return 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != separator)
            let_for++;
        if ((str[i] == separator && str[i + 1] != separator) ||
            (str[i] != separator && str[i + 1] == '\0') ||
            (str[i] == separator && str[i + 1] == '\0'))
            count++;
    }
    return count;
}

static char *gouilleseque(char *str, int len)
{
    char *temp = malloc(sizeof(char) * (len + 1));

    if (temp == NULL)
        return NULL;
    for (int j = 0; j < len; j++)
        temp[j] = str[j];
    temp[len] = '\0';
    return temp;
}

static char *gouillerie_two(char *str, char separator, int *gouille,
    int *letter_for_the_odities)
{
    char *temp = NULL;

    if (str[letter_for_the_odities[0]] == separator) {
        temp = gouilleseque(str, letter_for_the_odities[1]);
        *gouille += letter_for_the_odities[1] + 1;
        return temp;
    } else {
        temp = gouilleseque(str, letter_for_the_odities[1]);
        *gouille += letter_for_the_odities[1];
        return temp;
    }
}

static char *fill_arr(char *str, char separator, int *gouille)
{
    int letter_for_the_odities[2] = { 0, 0 };

    if (str[0] == separator) {
        *gouille += 1;
        return strdup("");
    }
    for (letter_for_the_odities[0] = 0; str[letter_for_the_odities[0]] != '\0';
        letter_for_the_odities[0]++) {
        if (str[letter_for_the_odities[0]] != separator)
            letter_for_the_odities[1]++;
        if (str[letter_for_the_odities[0]] == separator ||
            str[letter_for_the_odities[0] + 1] == '\0') {
            return gouillerie_two(str, separator, gouille,
                letter_for_the_odities);
        }
    }
    return NULL;
}

char **split_c(const string_t *this, char separator)
{
    char **array = NULL;
    int count = 0;
    int gouille = 0;

    if (this == NULL || this->str == NULL)
        return NULL;
    count = counter(this->str, separator);
    array = calloc(count + 1, sizeof(char *));
    if (array == NULL)
        return NULL;
    if (this->str[0] == '\0') { // Handle empty string case
        array[0] = strdup("");
        array[1] = NULL;
        return array;
    }
    for (int i = 0; i < count; i++) {
        array[i] = fill_arr(&this->str[gouille], separator, &gouille);
    }
    array[count] = NULL;
    return array;
}

string_t **split_s(const string_t *this, char separator)
{
    string_t **array = NULL;
    int count = 0;
    int b = 0;

    if (this == NULL || this->str == NULL)
        return NULL;
    count = counter(this->str, separator);
    array = calloc(count + 1, sizeof(string_t *));
    for (int i = 0; i < count; i++) {
        array[i] = malloc(sizeof(string_t));
        if (array[i] == NULL)
            return NULL;
        array[i]->str = fill_arr(&this->str[b], separator, &b);
    }
    return array;
}
