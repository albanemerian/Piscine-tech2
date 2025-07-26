/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** test_file_three
*/

#include "../Array.hpp"
#include "../Stack.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Stack, push_and_top) {
    Stack stack;
    stack.push(5.0);
    cr_assert_eq(stack.top(), 5.0);
}

Test(Stack, pop) {
    Stack stack;
    stack.push(5.0);
    cr_assert_eq(stack.pop(), 5.0);
}

Test(Stack, pop_empty_stack) {
    Stack stack;
    cr_assert_throw(stack.pop(), Stack::Error);
}

Test(Stack, top_empty_stack) {
    Stack stack;
    cr_assert_throw(stack.top(), Stack::Error);
}

Test(Stack, add) {
    Stack stack;
    stack.push(2.0);
    stack.push(3.0);
    stack.add();
    cr_assert_eq(stack.top(), 5.0);
}

Test(Stack, add_not_enough_operands) {
    Stack stack;
    stack.push(2.0);
    cr_assert_throw(stack.add(), Stack::Error);
}

Test(Stack, sub) {
    Stack stack;
    stack.push(5.0);
    stack.push(3.0);
    stack.sub();
    cr_assert_eq(stack.top(), -2);
}

Test(Stack, sub_not_enough_operands) {
    Stack stack;
    stack.push(2.0);
    cr_assert_throw(stack.sub(), Stack::Error);
}

Test(Stack, mul) {
    Stack stack;
    stack.push(2.0);
    stack.push(3.0);
    stack.mul();
    cr_assert_eq(stack.top(), 6.0);
}

Test(Stack, mul_not_enough_operands) {
    Stack stack;
    stack.push(2.0);
    cr_assert_throw(stack.mul(), Stack::Error);
}

Test(Stack, div) {
    Stack stack;
    stack.push(6.0);
    stack.push(3.0);
    stack.div();
    cr_assert_eq(stack.top(), 0.5);
}

Test(Stack, div_not_enough_operands) {
    Stack stack;
    stack.push(2.0);
    cr_assert_throw(stack.div(), Stack::Error);
}

// Test(Stack, div_by_zero) {
//     Stack stack;
//     stack.push(2.0);
//     stack.push(0.0);
//     cr_assert_throw(stack.div(), Stack::Error);
// }

Test(Stack, multiple_operations) {
    Stack stack;
    stack.push(10.0);
    stack.push(5.0);
    stack.add();
    cr_assert_eq(stack.top(), 15.0);
    stack.push(3.0);
    stack.mul();
    cr_assert_eq(stack.top(), 45.0);
    stack.push(5.0);
    stack.div();
    // cr_assert_eq(stack.top(), 0.111111);
    // stack.push(4.0);
    // stack.sub();
    // cr_assert_eq(stack.top(), 5.0);
}

Test(Stack, error_message_not_enough_operands) {
    Stack stack;
    try {
        stack.add();
    } catch (const Stack::Error& e) {
        cr_assert_str_eq(e.what(), "Not enough operands");
    }
}

Test(Stack, error_message_empty_stack) {
    Stack stack;
    try {
        stack.pop();
    } catch (const Stack::Error& e) {
        cr_assert_str_eq(e.what(), "Empty stack");
    }
}

Test(StackTests, PushAndTop) {
    Stack s;
    s.push(10.5);
    cr_assert_eq(s.top(), 10.5, "Expected top to be 10.5");
}

Test(StackTests, Pop) {
    Stack s;
    s.push(20.0);
    double value = s.pop();
    cr_assert_eq(value, 20.0, "Expected popped value to be 20.0");
}

Test(StackTests, PopEmptyStack) {
    Stack s;
    cr_expect_throw(s.pop(), Stack::Error, "Expected Stack::Error when popping empty stack");
}

Test(StackTests, AddOperation) {
    Stack s;
    s.push(5.0);
    s.push(10.0);
    s.add();
    cr_assert_eq(s.top(), 15.0, "Expected top after addition to be 15.0");
}

Test(StackTests, AddNotEnoughOperands) {
    Stack s;
    s.push(5.0);
    cr_expect_throw(s.add(), Stack::Error, "Expected Stack::Error when adding with insufficient operands");
}

Test(StackTests, MulOperation) {
    Stack s;
    s.push(3.0);
    s.push(4.0);
    s.mul();
    cr_assert_eq(s.top(), 12.0, "Expected top after multiplication to be 12.0");
}

// Test(StackTests, DivByZero) {
//     Stack s;
//     s.push(10.0);
//     s.push(0.0);
//     cr_expect_throw(s.div(), Stack::Error, "Expected Stack::Error when dividing by zero");
// }

Test(StackTests, TopEmptyStack) {
    Stack s;
    cr_expect_throw(s.top(), Stack::Error, "Expected Stack::Error when calling top on empty stack");
}
