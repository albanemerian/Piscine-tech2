/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** stack_one
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

unsigned int stack_get_size(stack_t *stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t *stack)
{
    unsigned int size = stack_get_size(stack);

    if (size == 0)
        return true;
    return false;
}

bool stack_push(stack_t **stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}

bool stack_pop(stack_t **stack_ptr)
{
    return list_del_elem_at_front(stack_ptr);
}

// int main (void)
// {
//     stack_t *stack = NULL;
//     int i = 5;
//     int j = 4;
//     int * data = NULL;
//     stack_push(&stack, &i);
//     stack_push(&stack, &j);
//     data = (int *)stack_top(stack);
//     printf (" %d \n",* data);
//     stack_clear(&stack);
//     return (0) ;
// }
