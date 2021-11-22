#include "iter.hpp"

int main(void) {
  int arr0[5] = {0, 1, 2, 3, 4};
  ::iter(arr0, (size_t)(sizeof(arr0) / sizeof(arr0[0])), ::print);
  std::cout << std::endl;
  ::iter(arr0, (size_t)(sizeof(arr0) / sizeof(arr0[0])), ::times);
  ::iter(arr0, (size_t)(sizeof(arr0) / sizeof(arr0[0])), ::print);
  std::cout << std::endl;
  std::cout << std::endl;
  double arr1[5] = {1.5, 2.8, 7.6, 9.9, 13.2};
  ::iter(arr1, (size_t)(sizeof(arr1) / sizeof(arr1[0])), ::print);
  std::cout << std::endl;
  ::iter(arr1, (size_t)(sizeof(arr1) / sizeof(arr1[0])), ::times);
  ::iter(arr1, (size_t)(sizeof(arr1) / sizeof(arr1[0])), ::print);
  std::cout << std::endl;

  return 0;
}