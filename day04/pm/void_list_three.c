/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** void_list_three
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    unsigned int current_position = 0;
    list_t *temp = list;

    if (list == NULL)
        return 0;
    if (position == 0)
        return list_get_elem_at_front(list);
    while (temp != NULL) {
        if (current_position == position)
            return temp->value;
        current_position++;
        temp = temp->next;
    }
    return 0;
}

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *temp = *front_ptr;
    list_t *next = NULL;

    if (*front_ptr == NULL)
        return false;
    next = temp->next;
    free(temp);
    *front_ptr = next;
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *temp = *front_ptr;
    list_t *next = NULL;
    unsigned int size = list_get_size(*front_ptr);
    unsigned int i = 0;

    if (*front_ptr == NULL)
        return false;
    while (temp != NULL) {
        if (i == size - 2) {
            next = temp->next;
            temp->next = NULL;
            free(next);
            break;
        }
        temp = temp->next;
        i++;
    }
    return true;
}

bool error_casess(list_t **front_ptr, unsigned int position)
{
    unsigned int size = list_get_size(*front_ptr);

    if (position > size)
        return false;
    return true;
}

bool list_del_elem_at_position(list_t **front_ptr, unsigned int position)
{
    unsigned int i = 0;
    list_t *next = NULL;
    list_t *temp = *front_ptr;

    if (error_casess(front_ptr, position) == false)
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    while (temp != NULL) {
        if (i == position - 1) {
            next = temp->next;
            temp->next = next->next;
            free(next);
            return true;
        }
        temp = temp->next;
        i++;
    }
    return false;
}
