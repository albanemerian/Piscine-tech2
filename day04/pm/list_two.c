/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** list_two
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int int_list_get_elem_at_front(int_list_t *list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    int_list_t *temp = list;

    if (list == NULL)
        return 0;
    while (temp->next != NULL)
        temp = temp->next;
    return temp->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    unsigned int current_position = 0;
    int_list_t *temp = list;

    if (list == NULL)
        return 0;
    if (position == 0)
        return int_list_get_elem_at_front(list);
    while (temp != NULL) {
        if (current_position == position)
            return temp->value;
        current_position++;
        temp = temp->next;
    }
    return 0;
}

// int main(void)
// {
//     int_list_t * list_head = NULL;
//     int_list_add_elem_at_front(&list_head, 1);
//     int_list_add_elem_at_front(&list_head, 2);
//     int_list_add_elem_at_position(&list_head, 3, 1);
//     printf("There are %u elements in the list\n",
//         int_list_get_size(list_head));
//     printf("The first element is %d\n",
//         int_list_get_elem_at_front(list_head));
//     printf("The last element is %d\n",
//         int_list_get_elem_at_back(list_head));
//     int_list_clear(&list_head);
//     return 0;
// }
