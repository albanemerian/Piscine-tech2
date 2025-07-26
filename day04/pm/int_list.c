/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** list_0
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));
    int_list_t *temp = NULL;

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

void int_list_dump(int_list_t *list)
{
    int_list_t *temp = list;

    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    unsigned int size = 0;
    int_list_t *temp = list;

    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

bool int_list_is_empty(int_list_t *list)
{
    unsigned int temp = int_list_get_size(list);

    if (temp == 0)
        return true;
    return false;
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *temp = *front_ptr;
    int_list_t *next = NULL;

    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *front_ptr = NULL;
}


//     printf("before dump\n");
//     int_list_dump(list);
//     int_list_add_elem_at_front(&list, 1714636915);
//     int_list_add_elem_at_front(&list, 1957747793);
//     int_list_add_elem_at_front(&list, 424238335);
//     printf("before dump\n");
//     int_list_dump(list);
//     int_list_add_elem_at_position(&list, 1350490027, 5);
//     int_list_add_elem_at_position(&list, 1649760492, 4);
//     int_list_add_elem_at_position(&list, 1189641421, 1);
//     printf("before dump\n\n");
//     int_list_dump(list);
//     int_list_add_elem_at_position(&list, 783368690, 0);

//     printf("before dumpvff\n\n");
//     int_list_dump(list);
//     int_list_del_elem_at_position(&list, 2);
//     printf("before dump\n\n");
//     int_list_dump(list);
//     printf("\nList size %d\n", int_list_get_size(list));
//     printf("List is empty %d\n", int_list_is_empty(list));
//     int_list_del_elem_at_front(&list);
//     int_list_del_elem_at_position(&list, 0);
//     printf("before dump\n\n");
//     int_list_dump(list);
//     int_list_clear(&list);

//     int_list_t *list_head = NULL;
//     int_list_add_elem_at_front(&list_head, 1);
//     int_list_add_elem_at_front(&list_head, 2);
//     int_list_add_elem_at_position(&list_head, 3, 1);
//     printf("There are %u elements in the list \n",
//             int_list_get_size(list_head));
//     int_list_dump(list_head);
//     int_list_clear(&list_head);
//     int_list_add_elem_at_back(&list, 10);
//     int_list_add_elem_at_back(&list, 15);
//     int_list_dump(list);
//     size = int_list_get_size(list);
//     printf("The size of the list is %d\n", size);
//     int_list_clear(&list);
//     temp = int_list_is_empty(list);
//     int_list_clear(&list);
//     printf("The list is %d\n", temp);
//     return 0;
// }
