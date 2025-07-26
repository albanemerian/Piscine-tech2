/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** test_file_one
*/

#include   <criterion/criterion.h>
#include   <criterion/redirect.h>
#include "../Algorithm.hpp"


void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(swap, test_swap)
{
    int a = 42;
    int b = 21;

    swap(a, b);
    cr_assert_eq(a, 21);
    cr_assert_eq(b, 42);
}

Test(min, test_min)
{
    int a = 42;
    int b = 21;

    cr_assert_eq(min(a, b), 21);
}

Test(max, test_max)
{
    int a = 42;
    int b = 21;

    cr_assert_eq(max(a, b), 42);
}

Test(clamp, test_clamp)
{
    int a = 42;
    int b = 21;

    cr_assert_eq(clamp(0, a, b), 42);
}

Test(swap, test_swap_string)
{
    std::string c = "ghi";
    std::string d = "abc";

    swap(c, d);
    cr_assert_str_eq(c.c_str(), "abc");
    cr_assert_str_eq(d.c_str(), "ghi");
}

Test(clamp, test_max_string)
{
    int b = 20;
    int a = 2;

    cr_assert_eq(clamp(40, a, b), 20);
}

Test(calmp, test_min_string)
{
    int a = 3;
    int b = 5;

    cr_assert_eq(clamp(4, a, b), 4);
}


Test(AlgorithmTests, MinFunction) {
    cr_assert_eq(min(3, 5), 3, "Expected min(3,5) to return 3"); 
    cr_assert_eq(min(5, 3), 3, "Expected min(5,3) to return 3");
    cr_assert_eq(min(4, 4), 4, "Expected min(4,4) to return 4"); 
}

Test(AlgorithmTests, MaxFunction) {
    cr_assert_eq(max(3, 5), 5, "Expected max(3,5) to return 5"); 
    cr_assert_eq(max(5, 3), 5, "Expected max(5,3) to return 5"); 
    cr_assert_eq(max(4, 4), 4, "Expected max(4,4) to return 4");
}
