/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <functional>

template <typename T, std::size_t N>
class Array {
public:
    Array() {
        for (std::size_t i = 0; i < N; i++)
            data[i] = T();
    }
    ~Array() = default;

    std::size_t size() const {
        return N;
    }

    void forEach(const std::function<void(const T&)>& task) const {
        for (std::size_t i = 0; i < size(); i++)
            task(data[i]);
    }

    T& operator[](std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("Out of range"); //missiing unit test
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Out of range");
        }
        return data[index];
    }

    template <typename U>
    Array<U, N> convert(const std::function<U(const T&)>& converter) const {
        Array<U, N> result;
        for (std::size_t i = 0; i < size(); i++)
            result[i] = converter(data[i]);
        return result;
    }

private:
    T data[N];
};

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const Array<T, N>& arr) {

    os << "[";
    for (std::size_t i = 0; i < N; ++i) {
        os << arr[i];
        if (i < N - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif /* !ARRAY_HPP_ */
