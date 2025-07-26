/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** test_file_two
*/

#include "../Array.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>



Test(ArrayTests, SizeFunction) {
    Array<int, 5> arr;
    cr_assert_eq(arr.size(), 5, "Expected size to be 5");
}

Test(ArrayTests, AccessOperator) {
    Array<int, 3> arr;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cr_assert_eq(arr[0], 10, "Expected arr[0] to be 10");
    cr_assert_eq(arr[1], 20, "Expected arr[1] to be 20");
    cr_assert_eq(arr[2], 30, "Expected arr[2] to be 30");
    cr_expect_throw(arr[6], std::out_of_range, "Out of range");
}

Test(ArrayTests, OutOfBoundsAccess) {
    Array<int, 3> arr;
    try {
        cr_expect_throw(arr[3], std::out_of_range, "Expected out_of_range exception");
        cr_expect_throw(arr[-1], std::out_of_range, "Expected out_of_range exception for negative index");
        cr_expect_throw(arr[6], std::out_of_range, "Expected out_of_range exception");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

Test(ArrayTests, OutOfBoundsAccs) {
    Array<int, 3> arr;

    cr_expect_throw(arr[3], std::out_of_range, "Expected out_of_range exception for out-of-bounds read");
    cr_expect_throw({ arr[3] = 42; }, std::out_of_range, "Expected out_of_range exception for out-of-bounds write");
    cr_expect_throw(arr[-1], std::out_of_range, "Expected out_of_range exception for negative index");
}

// Add a new test to cover the missing line
Test(ArrayTests, OutOfBoundsWrite) {
    Array<int, 3> arr;
    try {
        arr[0] = 21;
        arr[1] = 42;
        arr[2] = 84;
        arr[3] = 84; // This line should trigger the out-of-range exception
    } catch (const std::exception& e) {
        cr_assert_str_eq(e.what(), "Out of range", "Expected out_of_range exception with message 'Out of range'");
    }
}

Test(ArrayTests, ForEachFunction) {
    Array<int, 3> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    int sum = 0;
    arr.forEach([&sum](const int& value) { sum += value; });
    cr_assert_eq(sum, 6, "Expected sum to be 6");
}

Test(ArrayTests, ConvertFunction) {
    Array<int, 3> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    Array<double, 3> result = arr.convert<double>([](const int& value) { return static_cast<double>(value) * 1.5; });
    cr_assert_float_eq(result[0], 1.5, 0.01, "Expected result[0] to be 1.5");
    cr_assert_float_eq(result[1], 3.0, 0.01, "Expected result[1] to be 3.0");
    cr_assert_float_eq(result[2], 4.5, 0.01, "Expected result[2] to be 4.5");
}
