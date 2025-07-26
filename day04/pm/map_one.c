/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD04pm-albane.merian
** File description:
** map_one
*/

#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "list.h"

unsigned int map_get_size(map_t *map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t *map)
{
    return list_is_empty(map);
}

bool map_add_elem(map_t **map_ptr, void *key, void *value,
    key_comparator_t key_cmp)
{
    list_t *current = *map_ptr;
    pair_t *new_pair = malloc(sizeof(pair_t));
    pair_t *pair = NULL;

    if (!new_pair)
        return false;
    new_pair->key = key;
    new_pair->value = value;
    while (current) {
        pair = (pair_t *)current->value;
        if (key_cmp(pair->key, key) == 0) {
            pair->value = value;
            free(new_pair);
            return true;
        }
        current = current->next;
    }
    return list_add_elem_at_front(map_ptr, new_pair);
}

// int int_comparator ( const void * first , const void * second )
// {
//     int val1 = *( const int *) first ;
//     int val2 = *( const int *) second ;
//     return ( val1 - val2 ) ;
// }

// int main ( void )
// {
//     map_t * map = NULL ;
//     int first_key = 1;
//     int second_key = 2;
//     int third_key = 3;
//     char *first_value = "first" ;
//     char *first_value_rw = "first_rw" ;
//     char *second_value = "second";
//     char *third_value = "third";
//     char **data = NULL ;
//     map_add_elem(&map, &first_key ,&first_value , &int_comparator);
//     map_add_elem(&map, &first_key ,&first_value_rw , &int_comparator);
//     map_add_elem(&map, &second_key,&second_value , &int_comparator);
//     map_add_elem(&map, &third_key ,&third_value , &int_comparator);
//     data = ( char **) map_get_elem ( map , & second_key , &int_comparator);
//     printf ("The key [%d] maps to value [%s]\n", second_key, * data);
//     map_clear (& map ) ;
//     return (0) ;
// }
