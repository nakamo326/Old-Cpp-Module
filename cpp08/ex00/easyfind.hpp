#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

template <typename T>
typename T::const_iterator easyfind(T &t, int val) {
  return std::find(t.begin(), t.end(), val);
}

#endif  // EASYFIND_HPP