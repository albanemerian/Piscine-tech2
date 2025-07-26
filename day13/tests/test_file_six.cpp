/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** test_file_six
*/

#include <criterion/criterion.h>
#include "../SharedPointer.hpp"

Test(SharedPointer, default_constructor) {
    SharedPointer<int> sp;
    cr_assert_null(sp.get());
}

Test(SharedPointer, parameterized_constructor) {
    int *p = new int(5);
    SharedPointer<int> sp(p);
    cr_assert_eq(*sp, 5);
    cr_assert_eq(sp.get(), p);
}

Test(SharedPointer, copy_constructor) {
    int *p = new int(5);
    SharedPointer<int> sp1(p);
    SharedPointer<int> sp2(sp1);
    cr_assert_eq(sp1.get(), sp2.get());
    cr_assert_eq(*sp1, *sp2);
}

Test(SharedPointer, assignment_operator) {
    int *p1 = new int(5);
    int *p2 = new int(10);
    SharedPointer<int> sp1(p1);
    SharedPointer<int> sp2(p2);
    sp2 = sp1;
    cr_assert_eq(sp1.get(), sp2.get());
    cr_assert_eq(*sp1, *sp2);
}

Test(SharedPointer, reset) {
    int *p1 = new int(5);
    int *p2 = new int(10);
    SharedPointer<int> sp(p1);
    sp.reset(p2);
    cr_assert_eq(*sp, 10);
    cr_assert_eq(sp.get(), p2);
    sp.reset();
    cr_assert_null(sp.get());
}

Test(SharedPointer, release) {
    int *p = new int(5);
    SharedPointer<int> sp(p);
    sp.release();
    cr_assert_not_null(sp.get());
}

