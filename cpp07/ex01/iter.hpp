#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T const *arr, size_t length, void (*fp)(T const &elm)) {
  for (size_t i = 0; i < length; i++) {
    fp(arr[i]);
  }
}

template <typename T>
void iter(T *arr, size_t length, void (*fp)(T &elm)) {
  for (size_t i = 0; i < length; i++) {
    fp(arr[i]);
  }
}

// for test
template <typename T>
void show(T const &a) {
  std::cout << a << ", ";
}

// doesn't work
template <typename T>
void times(T &a) {
  a = a * 2;
}

#endif  // ITER_HPP