#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T *arr, size_t length, void (*fp)(T const &elm)) {
  for (size_t i = 0; i < length; i++) {
    fp(arr[i]);
  }
}

// for test
template <typename T>
void print(const T &a) {
  std::cout << a << ", ";
}

template <typename T>
void times(const T &a) {
  a = a * 2;
}

#endif  // ITER_HPP