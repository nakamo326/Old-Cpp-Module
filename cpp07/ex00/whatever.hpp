#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <typeinfo>

#include "Color.hpp"

template <typename T>
void swap(T &a, T &b) {
  T tmp;
  tmp = b;
  b = a;
  a = tmp;
  return;
}

template <typename T>
T min(T &a, T &b) {
  if (a < b)
    return a;
  return b;
}

template <typename T>
T min(T const &a, T const &b) {
  if (a < b)
    return a;
  return b;
}

template <typename T>
T max(T &a, T &b) {
  if (a > b)
    return a;
  return b;
}

template <typename T>
T max(T const &a, T const &b) {
  if (a > b)
    return a;
  return b;
}

// for test
template <typename T>
void testAll(T a, T b) {
  ::swap(a, b);
  std::cout << CYN "test by " << typeid(a).name() << NC << std::endl;
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

#endif  // WHATEVER_HPP