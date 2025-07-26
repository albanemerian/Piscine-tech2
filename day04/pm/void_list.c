/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** void_list
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

unsigned int list_get_size(list_t *list)
{
    unsigned int i = 0;
    list_t *temp = list;

    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return i;
}

bool list_is_empty(list_t *list)
{
    unsigned int size = list_get_size(list);

    if (size == 0)
        return true;
    return false;
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    list_t *temp = list;

    while (temp != NULL) {
        val_disp(temp->value);
        temp = temp->next;
    }
}

void list_clear(list_t **front)
{
    list_t *temp = *front;
    list_t *next = NULL;

    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *front = NULL;
}

// static void int_displayer(const void *data)
// {
//     int value = *((const int *)data);
//     printf ("%d \n", value);
// }

// static void test_size(list_t *list_head)
// {
//     printf ("There are %u elements in the list \n",
        // list_get_size(list_head));
//     list_dump(list_head, &int_displayer);
// }

// int main(void)
// {
//     list_t *list = NULL;
//     int i = 42;
//     int j = 43;
//     int a = 44;
//     int b = 45;
//     int c = 46;
//     int d = 47;
//     int e = 48;
//     int f = 49;
//     int g = 50;
//     // int h = 51;
//     // int k = 52;
//     // int l = 53;

//     printf("List size %d\n", list_get_size(list));
//     printf("List is empty %d\n", list_is_empty(list));
//     list_add_elem_at_front(&list, &a);
//     list_add_elem_at_front(&list, &b);
//     list_add_elem_at_front(&list, &i);
//     test_size(list);

//     printf("List size %d\n", list_get_size(list));
//     printf("List is empty %d\n", list_is_empty(list));

//     list_add_elem_at_back(&list, &c);
//     list_add_elem_at_back(&list, &d);
//     list_add_elem_at_back(&list, &j);
//     printf("List size %d\n", list_get_size(list));

//     list_add_elem_at_position(&list, &e, 2);
//     list_add_elem_at_position(&list, &f, 3);
//     list_add_elem_at_position(&list, &j, 5);
//     list_add_elem_at_position(&list, &g, 0);
//     printf("List size %d\n", list_get_size(list));


//     printf("Head value: %i\n", *((int *)list_get_elem_at_front(list)));
//     printf("Tail value: %i\n", *((int *)list_get_elem_at_back(list)));
//     test_size(list);
//     printf("Lsit elem at position 2: %i\n",
            // *((int *)list_get_elem_at_position(list, 5)));
//     list_del_elem_at_front(&list);
//     test_size(list);
//     list_del_elem_at_back(&list);
//     test_size(list);
//     list_del_elem_at_position(&list, 2);
//     printf("after del at pose 2\n\n");
//     test_size(list);
//     list_del_elem_at_position(&list, 0);
//     printf("after del at pose0\n\n");
//     test_size(list);
//     list_clear(&list);
//     printf("Size after clear: %d\n", list_get_size(list));
//     return 0;
// }
