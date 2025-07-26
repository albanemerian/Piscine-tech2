/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH2-alban.roussee
** File description:
** main
*/

#include "new.h"
#include "point.h"
#include "vertex.h"
#include "player.h"
#include "int.h"
#include "char.h"
#include "array.h"
#include "float.h"

#include "new.h"
#include "player.h"


int main (void)
{
    Object *player = new(Player);
    printf("befoe delete\n");
    delete(player);

    printf("after delete\n");
    Object *lol = new(Player);
    printf("befoe delete\n");
    printf("before empty delete\n");
    // delete(NULL);
    delete(lol);

    printf("before point\n");
    Object *point = new(Point, 42, -42);
    printf("before str\n");
    char *temp = str(point);
    printf("point = %s\n", temp); // Memory leak !
    free(temp); // Free the allocated string to avoid memory leak
    

    printf("before point\n");
    point = new(Point, NULL, NULL);
    printf("before str\n");
    char *temps = str(point);
    printf("point = %s\n", temps); // Memory leak !
    free(temps); // Free the allocated string to avoid memory leak
    delete(point);


    // Object *int1 = new(Int, 1681692777);
    // Object *int2 = new(Int, -1804289383);
    // bool intres = lt(int1, int2);
    // printf("Is smaller %s < %s ", str(int1), str(int2));
    // if (intres == 1)
    //     printf("true\n");
    // else
    //     printf("false\n");

    // Object *int1 = new(Int, 42);
    // // Object *int1 = new(Int, 42);
    // Object *int1 = new(Int, 42);
    // printf("for int calss \n");
    Object *int1 = new(Int, 42);
    char *temp1 = str(int1);
    printf("int1 = %s\n", temp1);
    Object *int2 = new(Int, 42);
    bool int4 = eq(int1, int2);
    printf("Is equal %i\n", int4);
    Object *int3 = addition(int1, int2);
    char *temp3 = str(int3);
    printf("int3 = %s\n", temp3);
    bool is_bigger = gt(int1, int3);
    printf("Is bigger %s < %s %i\n", str(int1), str(int3),is_bigger);
    bool is_smaller = lt(int3, int1);
    printf("Is smaller %s > %s %i\n", str(int3), str(int1), is_smaller);
    free(temp1);
    delete(int1);

    Object *mull1 = subtraction(int3, int2);
    printf("Mul %s\n", str(mull1));
    printf("Before char test\n");
    Object *char1 = new(Char, 'c');
    char *temp2 = str(char1);
    printf("char1 = %s\n", temp2);
    Object *char2 = new(Char, 'a');
    Object *char3 = addition(char1, char2);
    char *temp4 = str(char3);
    printf("Free %s\n", temp4);
    free(temp2);
    printf("herere\n");
    delete(char1);
    printf("herere\n");

    Object *tab = new(Array, 10, Int, 42);
    printf("helloa\n");
    if (tab == NULL)
        printf("tab is null\n");
    else
        printf("cacac\n");
    printf(" lelele %s\n", str(tab));
    size_t size = len(tab);
    printf("after %zu\n", size);
    for (size_t i = 0; i < size; i++) {
        Object *elem = getitem(tab, i);
        char *str_elem = str(elem);
        printf("tab[%zu] = %s\n", i, str_elem);
        free(str_elem);
        delete(elem);
    }
}
