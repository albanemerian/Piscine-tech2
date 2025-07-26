/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD05-albane.merian
** File description:
** test_main
*/

#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <string.h>

// int main(void) {

    // string_t s1, s2, s3, s4;
    // // Initialize strings
    // string_init(&s1, "Initial");
    // string_init(&s2, "Another");
    // string_init(&s3, "Third");
    // string_init(&s4, "");
    // // printf("Char is equel %i\n",s1.at(&s4, 2));

    // printf("Char is equel %i\n",s1.at(&s1, 7));
    // printf("Char is equel %c\n",s1.at(&s1, 6));
    // printf("Char is equel %c\n",s1.at(&s1, 2));
    // printf("Char is equel %i\n",s1.at(&s1, -7));
    // printf("Char is equel %c\n",s1.at(&s1, 0));
    // printf("before\n");
    // s2.append_c(&s2, " World ");
    // s2.append_s(&s2, &s1);
    // printf("s2 (append): [%s]\n", s2.str);
    // s2.append_c(&s2, NULL);
    // s2.append_s(&s2, &s2);
    // printf("Length %i\n", s1.length(&s2));
    // printf("Length %i\n", s1.length(&s4));

    // string_t ss1, ss2;
    // char str[100];
    // string_init(&ss1, "Hello, world!");
    // string_init(&ss2, "Another string");
    // printf("Len copied %i\n", ss1.copy(&ss2, str, 60, 0));
    // printf("Len copied %i\n", ss1.copy(&ss1, str, 6, 60));
    // // printf("Len copied %i\n", s1.copy(&s3, "", 2, 0));
    // string_destroy(&ss1);
    // string_destroy(&ss2);

    // s4.append_c(&s4, "My string");
    // char stra[100];
    // printf("before\n");
    // printf("My string test %i\n", s1.copy(&s4, stra, 9, 0));

    // s4.clear(&s4);
    // s4.append_c(&s4, "My strin");
    // // char stra[10];
    // printf("My strin test Len copied %i\n", s1.copy(&s4, stra, 9, 0));
    // if (s4.empty(&s4) == 0)
    //     printf("String is not empty\n");
    // else
    //     printf("String is empty\n");
    // s4.clear(&s4);
    // if (s4.empty(&s4) == 0)
    //     printf("String is not empty\n");
    // else
    //     printf("String is empty\n");
    // Test assign_c with normal string
    // s1.assign_c(&s1, "Hello World");
    // s2.assign_c(&s2, "Hello World");
    // // printf("Value where found %i\n", s1.find_c(&s1, "World", 1));
    // // printf("Value error found %i\n", s1.find_c(&s1, "World", -1));
    // // printf("Value error found %i\n", s1.find_c(&s1, "World", 234));

    // // printf("Value where found %i\n", s1.find_s(&s1, &s2, 0));
    // // printf("Value error found %i\n", s1.find_s(&s1, &s2, -6));
    // // printf("Value error found %i\n", s1.find_s(&s1, &s2, 9765));
    // printf("Compare value %i\n", s1.compare_s(&s1, &s2));
    // printf("Compare value %i\n", s2.compare_c(&s2, "Hello World"));
    // printf("Compare value %i\n", s2.compare_s(&s2, &s4));
    // printf("Compare value %i\n", s3.compare_c(&s3, ""));
    // printf("Compare value %i\n", s3.compare_c(&s3, NULL));
    // printf("s1: [%s]\n", s1.str);
    // printf("\tIs empty %i\n", s1.empty(&s1));
    // s1.clear(&s1);
    // printf("\tIs empty %i\n", s1.empty(&s1));

    // printf("Buffer is %s\n", s3.c_str(&s3));
    // printf("Buffer error is %s\n", s3.c_str(&s4));
    // printf("\tIs empty %i\n", s3.empty(&s3));
    // printf("\tIs empty %i\n", s3.empty(&s4));
    // printf("s1 (cleared): [%s]\n", s1.str);
    // // Test assign_c with empty string
    // s1.assign_c(&s1, "");
    // printf("s1 (empty): [%s]\n", s1.str);

    // // Test assign_c with NULL (should handle gracefully)
    // s1.assign_c(&s1, NULL);
    // printf("s1 (NULL): [%s]\n", s1.str);

    // // Test assign_s with another string
    // s2.assign_s(&s2, &s1);
    // printf("s2: [%s]\n", s2.str);

    // // Test assign_s with self-assignment
    // s2.assign_s(&s2, &s2);
    // printf("s2 (self-assignment): [%s]\n", s2.str);

    // // Test assign_s with empty string
    // s3.assign_c(&s3, "");
    // s2.assign_s(&s2, &s3);
    // printf("s2 (assign empty): [%s]\n", s2.str);

    // // Test assign_s with NULL string (should handle gracefully)
    // s2.assign_s(&s2, NULL);
    // printf("s2 (assign NULL): [%s]\n", s2.str);

    // printf("\tIs empty %i\n", s1.empty(&s1));
    // printf("\tIs empty %i\n", s2.empty(&s2));
    // printf("\tIs empty %i\n", s3.empty(&s3));
    // printf("\tIs empty %i\n", s4.empty(&s4));
    // // Clean up
    // string_destroy(&s1);
    // string_destroy(&s2);
    // string_destroy(&s3);
    // string_destroy(&s4);

    // string_t my_string;
    // string_t search_string;
    // const char *search_cstr = "World";

    // // Initialize the strings
    // string_init(&my_string, "Hello, World!");
    // string_init(&search_string, "World");

    // // Test find_s
    // int pos_s = my_string.find_s(&my_string, &search_string, 0);
    // printf("Position of 'World' in 'Hello, World!' using find_s: %d\n", pos_s);

    // // Test find_c
    // int pos_c = my_string.find_c(&my_string, search_cstr, 0);
    // printf("Position of 'World' in 'Hello, World!' using find_c: %d\n", pos_c);

    // // Test find_s with invalid position
    // pos_s = my_string.find_s(&my_string, &search_string, 20);
    // printf("'World' in 'Hello, World!' using find_s with invalid: %d\n", pos_s);

    // // Test find_c with invalid position
    // pos_c = my_string.find_c(&my_string, search_cstr, 20);
    // printf("'World' in 'Hello, World!' using find_c with invalid: %d\n", pos_c);

    // // Destroy the strings
    // string_destroy(&my_string);
    // string_destroy(&search_string);

    // string_t my_test_insert;
    // string_t test_insert_two;
    // string_t s5;
    // string_t s6;

    // string_init(&my_test_insert, "Hello, World!");
    // string_init(&test_insert_two, "bonjour en faite");
    // string_init(&s5, "[s5 lala]");
    // string_init(&s6, "[s6 lala]");

    // my_test_insert.insert_c(&my_test_insert, 7, "[ la la ]");
    // printf("my_test_insert: [%s]\n", my_test_insert.str);
    // my_test_insert.insert_c(&my_test_insert, 70, "[lol end]");
    // printf("my_test_insert: [%s]\n", my_test_insert.str);
    // my_test_insert.insert_c(&my_test_insert, -7, "[lol end]");


    // test_insert_two.insert_s(&test_insert_two, 7, &s5);
    // printf("test_insert_two: [%s]\n", test_insert_two.str);
    // test_insert_two.insert_s(&test_insert_two, 70, &s6);
    // printf("test_insert_two: [%s]\n", test_insert_two.str);
    // test_insert_two.insert_s(&test_insert_two, -7, &my_test_insert);  
 
    // string_t test_atoi;

    // string_init(&test_atoi, "1");
    // printf("Value of string: %i\n", test_atoi.to_int(&test_atoi));
    // test_atoi.assign_c(&test_atoi, "2");
    // printf("Value of string: %i\n", test_atoi.to_int(&test_atoi));
    // test_atoi.assign_c(&test_atoi, "3");
    // printf("Value of string: %i\n", test_atoi.to_int(&test_atoi));
    // test_atoi.assign_c(&test_atoi, "4");
    // printf("Value of string: %i\n", test_atoi.to_int(&test_atoi));



    // string_t my_string_array;
    // string_init(&my_string_array, " ");
    // // string_init(&my_string_array, "monday  tuesday wednesday thursday friday saturday sunday");
    // char **split_c_result = my_string_array.split_c(&my_string_array, ' ');
    // for (int i = 0; split_c_result[i] != NULL; i++) {
    //     printf("[%s]\n", split_c_result[i]);
    //     free(split_c_result[i]); // Free each string
    // }
    // free(split_c_result); // Free the array

    // string_t my_string_array_two;
    // string_init(&my_string_array_two, "Hello world  this is a test lalal");
    // string_t **split_s_result = my_string_array_two.split_s(&my_string_array_two, ' ');
    // printf("\nsplit_s result:\n");
    // for (int j = 0; split_s_result[j] != NULL; j++) {
    //     printf("%s\n", split_s_result[j]->str);
    //     free(split_s_result[j]->str); // Free each string
    //     free(split_s_result[j]); // Free each string_t
    // }
    // free(split_s_result);

    // string_t my_string_array_three;
    // string_init(&my_string_array_three, "Hello;world;this;is;a;test;lalal;my;name;is;lol;and;;;this;exercises;;;sucks");
    // string_t **split_s_result_three = my_string_array_three.split_s(&my_string_array_three, ';');
    // printf("\nsplit_s result three:\n");
    // for (int j = 0; split_s_result_three[j] != NULL; j++) {
    //     my_string_array_three.print(split_s_result_three[j]);
    //     printf("\n");
    //     free(split_s_result_three[j]->str); // Free each string
    //     free(split_s_result_three[j]); // Free each string_t
    // }
    // free(split_s_result_three); // Free the array

    // string_destroy(&my_test_insert);
    // string_destroy(&test_insert_two);
    // string_destroy(&s5);
    // string_destroy(&s6);
    // string_destroy(&test_atoi);
    // string_destroy(&my_string_array);
    // string_destroy(&my_string_array_two);
    // string_destroy(&my_string_array_three);
    // return 0;
// }
// 
