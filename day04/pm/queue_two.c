/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** queue_two
*/

#include <stdio.h>
#include "list.h"
#include "queue.h"

void queue_clear(queue_t **queue_ptr)
{
    list_clear(queue_ptr);
}

void *queue_front(queue_t *queue)
{
    return list_get_elem_at_front(queue);
}
