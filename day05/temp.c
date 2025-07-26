/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** temp
*/

#include "string.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    string_t s;
 
    string_init(&s, "pierre");
    s.insert_c(&s, 4, "Non");
    s.print(&s);
    string_destroy(&s);
    string_init(&s, "");
    s.insert_c(&s, 4, "Non");
    s.print(&s);
    string_destroy(&s);
    string_init(&s, "pier");
    s.insert_c(&s, 3, "Non");
    s.print(&s);
    string_destroy(&s);
    string_init(&s, "pier");
    s.insert_c(&s, 100, "Non");
    s.print(&s);
    string_destroy(&s);
    string_init(&s, "pierre");
    s.insert_c(&s, 0, "Non");
    s.print(&s);
    string_destroy(&s);
    string_init(&s, "pierre");
    s.insert_c(&s, -1, "Non");
    s.print(&s);
    string_destroy(&s);
    string_init(&s, "");
    s.insert_c(&s, 0, "Non");
    s.print(&s);
    string_destroy(&s);
    string_init(&s, "");
    s.insert_c(&s, -1, "Non");
    s.print(&s);
    string_destroy(&s);
}
 
// int main() {
//     string_t str = { "" };
//     char **result = split_c(&str, ',');

//     for (int i = 0; result[i] != NULL; i++) {
//         printf("tab[%i]=%s\n", i,result[i]);
//         free(result[i]);
//     }
//     free(result);

//     return 0;
// }

// int main() {
//     string_t str = { "," };
//     char **result = split_c(&str, ',');

//     for (int i = 0; result[i] != NULL; i++) {
//         printf("tab[%i]=%s\n", i,result[i]);
//         free(result[i]);
//     }
//     free(result);

//     return 0;
// }

// int main() {
//     string_t str = { ",," };
//     char **result = split_c(&str, ',');

//     for (int i = 0; result[i] != NULL; i++) {
//         printf("tab[%i]=%s\n", i,result[i]);
//         free(result[i]);
//     }
//     free(result);

//     return 0;
// }
