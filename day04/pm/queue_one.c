/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** queue_one
*/

#include <stdio.h>
#include "queue.h"
#include "list.h"


unsigned int queue_get_size(queue_t *queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t *queue)
{
    unsigned int size = queue_get_size(queue);

    if (size == 0)
        return true;
    return false;
}

bool queue_push(queue_t **queue_ptr, void *elem)
{
    return list_add_elem_at_back(queue_ptr, elem);
}

bool queue_pop(queue_t **queue_ptr)
{
    return list_del_elem_at_front(queue_ptr);
}

// int main ( void )
// {
//     queue_t *queue = NULL;
//     int i = 5;
//     int j = 4;
//     int *data = NULL;
//     queue_push(&queue, &i);
//     queue_push(&queue, &j);
//     data = (int *)queue_front(queue);
//     printf (" %d \n", *data);
//     queue_clear (&queue);
//     return (0);
// }
