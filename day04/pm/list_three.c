/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** list_three
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "int_list.h"


bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *temp = *front_ptr;
    int_list_t *next = NULL;

    if (*front_ptr == NULL)
        return false;
    next = temp->next;
    *front_ptr = next;
    free(temp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *temp = *front_ptr;
    int_list_t *next = NULL;
    unsigned int size = int_list_get_size(*front_ptr);
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

bool error_cases(int_list_t **front_ptr, unsigned int position)
{
    unsigned int size = int_list_get_size(*front_ptr);

    if (position >= size)
        return false;
    return true;
}

bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position)
{
    unsigned int i = 0;
    int_list_t *next = NULL;
    int_list_t *temp = *front_ptr;

    if (error_cases(front_ptr, position) == false)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
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
// int main(void)
// {
//     int_list_t * list_head = NULL ;
//     int_list_add_elem_at_back(&list_head, 1);
//     int_list_add_elem_at_back(&list_head, 2);
//     int_list_add_elem_at_back(&list_head, 3);
//     printf("There are %u elements in the list \n",
//             int_list_get_size(list_head));
//     int_list_del_elem_at_front(&list_head);
//     int_list_dump(list_head);
//     int_list_clear(&list_head);
//     return 0;
// }
// int main(void)
// {
//     int_list_t *list = NULL;

//     int_list_add_elem_at_back(&list, 5);
//     int_list_add_elem_at_back(&list, 10);
//     int_list_add_elem_at_back(&list, 15);
//     int_list_add_elem_at_front(&list, 1);
//     int_list_add_elem_at_front(&list, 111);
//     int_list_dump(list);
//     printf("before deliting\n");
//     int_list_del_elem_at_front(&list);
//     printf("after del\n");
//     int_list_del_elem_at_back(&list);
//     int_list_dump(list);
// }
