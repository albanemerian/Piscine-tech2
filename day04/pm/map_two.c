/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** map_two
*/

#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "list.h"

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp)
{
    list_t *current = map;
    pair_t *pair = NULL;

    while (current) {
        pair = (pair_t *)current->value;
        if (key_cmp(pair->key, key) == 0)
            return pair->value;
        current = current->next;
    }
    return NULL;
}

void check_prev(list_t *prev, list_t *current, map_t **map_ptr)
{
    if (prev)
        prev->next = current->next;
    else
        *map_ptr = current->next;
}

bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp)
{
    list_t *current = *map_ptr;
    list_t *prev = NULL;
    pair_t *pair = NULL;

    while (current) {
        pair = (pair_t *)current->value;
        if (key_cmp(pair->key, key) == 0) {
            check_prev(prev, current, map_ptr);
            free(pair);
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void map_clear(map_t **map)
{
    map_t *temp = *map;
    map_t *next = NULL;

    while (temp != NULL) {
        next = temp->next;
        free(temp->value);
        free(temp);
        temp = next;
    }
    *map = NULL;
}
