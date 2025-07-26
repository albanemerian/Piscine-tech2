/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH2-alban.roussee
** File description:
** main
*/

#include "new.h"
#include "player.h"
#include "point.h"
#include "vertex.h"
#include "int.h"
#include "char.h"
#include "float.h"

void int_and_float_test(void)
{
    Object *int1 = new(Int, 42);
    Object *float1 = new(Float, 42.5);

    //float and a int 
    Object *res = addition(float1, int1);
    printf("Add  %s + %s = [%s]\n", str(float1), str(int1), str(res));
    Object *res2 = subtraction(float1, int1);
    printf("Sub %s, and int %s = [%s]\n", str(float1), str(int1), str(res2));
    Object *res3 = multiplication(float1, int1);
    printf("Mul %s, and int %s = [%s]\n", str(float1), str(int1), str(res3));
    Object *res4 = division(float1, int1);
    printf("Div %s, and int %s = [%s]\n", str(float1), str(int1), str(res4));
    
    //int and a float
    Object *res5 = addition(int1, float1);
    printf("Add %s, and float %s = [%s]\n", str(int1), str(float1), str(res5));
    Object *res6 = subtraction(int1, float1);
    printf("Sub %s, and float %s = [%s]\n", str(int1), str(float1), str(res6));
    Object *res7 = multiplication(int1, float1);
    printf("Mul %s, and float %s = [%s]\n", str(int1), str(float1), str(res7));
    Object *res8 = division(int1, float1);
    printf("Div %s, and float %s = [%s]\n", str(int1), str(float1), str(res8));
    delete(int1);
    delete(float1);
    delete(res);
    delete(res2);
    delete(res3);
    delete(res4);
    delete(res5);
    delete(res6);
    delete(res7);
    delete(res8);
}

void int_and_chars(void)
{
    Object *int1 = new(Int, 2);
    Object *int2 = new(Int, 3);
    Object *char1 = new(Char, 'a');

    printf("Add %s + %s = %s\n", str(int1), str(char1), str(addition(int1, char1)));
    printf("Mul %s * %s = %s\n", str(int2), str(char1), str(multiplication(int2, char1)));
}

// int main(void)
// {
//     printf("\tTests between int and floats\n\n");
//     int_and_float_test();
//     printf("\n\n\tTest between int and char's\n\n");
//     int_and_chars();
//     return 0;
// }
