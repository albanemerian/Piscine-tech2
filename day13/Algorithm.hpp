/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(const T &a, const T &b) {
    return (b < a) ? a : b;
}

template <typename T>
T clamp(const T &value, const T &min, const T &max) {
    if (value < min)
        return min;
    else if (max < value)
        return max;
    return value;
}

#endif /* !ALGORITHM_HPP_ */

// Write the following function templates :
// ✓ swap : swaps the value of its two parameters.
// ✓ min : returns the smallest of its two parameters.
// ✓ max : returns the biggest of its two parameters.
// ✓ clamp : takes three parameters (value, min and max), returns the value clamped between
// min and max.
// These templates should generate functions that can be called with any type of parameter, as
// long as they have the same type and provide a < comparison operator
