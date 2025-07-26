/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** list
*/

#include <stdbool.h>
#include "int_list.h"
#include <stdio.h>
#include <stdlib.h>

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool temp_func(int_list_t *new_node, unsigned int position,
    int_list_t **front_ptr, int elem)
{
    unsigned int size = int_list_get_size(*front_ptr);

    if (new_node == NULL)
        return false;
    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    if (position > size) {
        free(new_node);
        return false;
    }
    return true;
}

bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position)
{
    unsigned int temp = 0;
    int_list_t *new_node = malloc(sizeof(int_list_t));
    int_list_t *temp_node = *front_ptr;

    if (temp_func(new_node, position, front_ptr, elem) == false)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    while (temp_node != NULL) {
        if (temp == position - 1) {
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

// int main(void)
// {
//     int_list_t *list_head = NULL;
// }
// {
//     int_list_t *list_head = NULL;
//     int_list_add_elem_at_front(&list_head, 1);
//     int_list_add_elem_at_front(&list_head, 2);
//     int_list_add_elem_at_position(&list_head, 3, 1);
//     printf("There are %u elements in the list \n",
            // int_list_get_size(list_head));
//     int_list_dump(list_head);
//     int_list_clear(&list_head);
//     return 0;
// }
