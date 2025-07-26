/*
** EPITECH PROJECT, 2025
** day4
** File description:
** main
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

// Comparateur de clés (pour les chaînes)
int string_comparator(const void *key1, const void *key2) {
    return strcmp((const char *)key1, (const char *)key2);
}

// Fonction principale de test
int main(void) {
    map_t *map = NULL;
    const char *keys[] = {"1804289383", "846930886", "1681692777", "1714636915", "1957747793", "424238335"};
    const char *values1[] = {"719885386", "1649760492", "596516649", "1189641421", "1025202362", "1350490027"};
    const char *values2[] = {"719885386", "35005211", "1365180540", "1189641421", "1025202362", "294702567"};
    const char *values3[] = {"1101513929", "1801979802", "1315634022", "635723058", "1369133069", "1125898167"};

    // Test initial
    printf("map_get_size: %u$\n", map_get_size(map));
    printf("map_is_empty: %d$\n", map_is_empty(map));
    printf("map_get_elem (out bound): \"%s\"$\n", (char *)map_get_elem(map, "out_of_bound", string_comparator));

    // Ajout initial de 6 éléments
    printf("map_add_elem (x6, new)$\n");
    for (int i = 0; i < 6; ++i) {
        map_add_elem(&map, (void *)keys[i], (void *)values1[i], string_comparator);
    }
    printf("map_get_size: %u$\n", map_get_size(map));
    printf("map_is_empty: %d$\n", map_is_empty(map));
    for (int i = 0; i < 6; ++i) {
        printf("map_get_elem (\"%s\"): \"%s\"$\n", keys[i], (char *)map_get_elem(map, keys[i], string_comparator));
    }
    printf("map_get_elem (out bound): \"%s\"$\n", (char *)map_get_elem(map, "out_of_bound", string_comparator));

    // Remplacement des valeurs pour les mêmes clés
    printf("map_add_elem (x6, replace)$\n");
    for (int i = 0; i < 6; ++i) {
        map_add_elem(&map, (void *)keys[i], (void *)values2[i], string_comparator);
    }
    for (int i = 0; i < 6; ++i) {
        printf("map_get_elem (\"%s\"): \"%s\"$\n", keys[i], (char *)map_get_elem(map, keys[i], string_comparator));
    }
    printf("map_get_elem (out bound): \"%s\"$\n", (char *)map_get_elem(map, "out_of_bound", string_comparator));

    // Suppression de tous les éléments
    printf("map_del_elem (x6)$\n");
    for (int i = 0; i < 6; ++i) {
        map_del_elem(&map, (void *)keys[i], string_comparator);
    }
    for (int i = 0; i < 6; ++i) {
        printf("map_get_elem (\"%s\"): \"%s\"$\n", keys[i], (char *)map_get_elem(map, keys[i], string_comparator));
    }
    printf("map_get_size: %u$\n", map_get_size(map));
    printf("map_is_empty: %d$\n", map_is_empty(map));
    printf("map_get_elem (out bound): \"%s\"$\n", (char *)map_get_elem(map, "out_of_bound", string_comparator));

    // Réinsertion avec de nouvelles valeurs
    printf("map_add_elem (x6, replace)$\n");
    for (int i = 0; i < 6; ++i) {
        map_add_elem(&map, (void *)keys[i], (void *)values3[i], string_comparator);
    }
    for (int i = 0; i < 6; ++i) {
        printf("map_get_elem (\"%s\"): \"%s\"$\n", keys[i], (char *)map_get_elem(map, keys[i], string_comparator));
    }
    printf("map_get_elem (out bound): \"%s\"$\n", (char *)map_get_elem(map, "out_of_bound", string_comparator));

    // Nettoyage de la map
    printf("map_clear$\n");
    map_clear(&map);
    printf("map_get_size: %u$\n", map_get_size(map));
    printf("map_is_empty: %d$\n", map_is_empty(map));
    printf("map_get_elem (out bound): \"%s\"$\n", (char *)map_get_elem(map, "out_of_bound", string_comparator));

    return 0;
}
