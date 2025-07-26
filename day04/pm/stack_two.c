/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** stack_two
*/

#include <stdio.h>
#include "list.h"
#include "stack.h"

void stack_clear(stack_t **stack_ptr)
{
    list_clear(stack_ptr);
}

void *stack_top(stack_t *stack)
{
    return list_get_elem_at_front(stack);
}
