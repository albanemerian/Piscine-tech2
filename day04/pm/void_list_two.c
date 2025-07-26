/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** void_list_two
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "list.h"

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *temp = NULL;

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL)
        *front_ptr = new_node;
    else {
        temp = *front_ptr;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
    return true;
}

bool error_cases_void(list_t *new_node, unsigned int pos,
    list_t **front_ptr, void *elem)
{
    unsigned int size = list_get_size(*front_ptr);

    if (pos == 0)
        return list_add_elem_at_front(front_ptr, elem);
    if (pos > size) {
        free(new_node);
        return false;
    }
    return true;
}

bool list_add_elem_at_position(list_t **front_ptr, void *elem,
    unsigned int pos)
{
    unsigned int temp = 0;
    list_t *new_node = malloc(sizeof(list_t));
    list_t *temp_node = *front_ptr;

    if (error_cases_void(new_node, pos, front_ptr, elem) == false)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    while (temp_node != NULL) {
        if (temp == pos - 1) {
            new_node->next = temp_node->next;
            temp_node->next = new_node;
            return true;
        }
        temp++;
        temp_node = temp_node->next;
    }
    free(new_node);
    return false;
}

void *list_get_elem_at_front(list_t *list)
{
    if (list == NULL)
        return NULL;
    return list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    list_t *temp = list;

    if (list == NULL)
        return NULL;
    while (temp->next != NULL)
        temp = temp->next;
    return temp->value;
}
