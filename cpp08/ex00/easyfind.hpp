#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

template <typename T>
typename T::const_iterator easyfind(T &t, int i) {
  return std::find(t.begin(), t.end(), i);
}

#endif  // EASYFIND_HPP