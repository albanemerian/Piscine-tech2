/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** test_file_four
*/

#include <criterion/criterion.h>
#include "../UniquePointer.hpp"

class TestClass {
    public:
        int value;
        TestClass(int val = 0) : value(val) {}
};

Test(UniquePointer, DefaultConstructor) {
    UniquePointer<TestClass> ptr;
    cr_assert_null(ptr.get());
}

Test(UniquePointer, PointerConstructor) {
    TestClass* raw = new TestClass(42);
    UniquePointer<TestClass> ptr(raw);
    cr_assert_not_null(ptr.get());
    cr_assert_eq(ptr->value, 42);
}

Test(UniquePointer, Reset) {
    UniquePointer<TestClass> ptr(new TestClass(42));
    ptr.reset();
    cr_assert_null(ptr.get());
}

Test(UniquePointer, Get) {
    TestClass* raw = new TestClass(42);
    UniquePointer<TestClass> ptr(raw);
    cr_assert_eq(ptr.get(), raw);
}

Test(UniquePointer, ArrowOperator) {
    UniquePointer<TestClass> ptr(new TestClass(42));
    cr_assert_eq(ptr->value, 42);
}

Test(UniquePointer, AssignmentOperator) {
    UniquePointer<TestClass> ptr(new TestClass(42));
    TestClass* raw = new TestClass(84);
    ptr = raw;
    cr_assert_eq(ptr->value, 84);
}

Test(UniquePointer, NullAssignment) {
    UniquePointer<TestClass> ptr(new TestClass(42));
    ptr = nullptr;
    cr_assert_null(ptr.get());
}

Test(UniquePointer, SelfAssignment) {
    TestClass* raw = new TestClass(42);
    UniquePointer<TestClass> ptr(raw);
    ptr = raw;  // Should handle self-assignment gracefully
    cr_assert_eq(ptr->value, 42);
}

