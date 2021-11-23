#include <array>
#include <vector>

#include "easyfind.hpp"

int main() {
  {
    std::array<int, 5> arr{0, 1, 2, 3, 4};
    std::array<int, 5>::const_iterator ret(::easyfind(arr, 4));
    std::cout << *ret << std::endl;
    ret = ::easyfind(arr, 8);
    if (ret == arr.end())
      std::cout << "it's equal with end of iterator" << std::endl;
    else
      std::cout << "something wrong" << std::endl;
  }
  {
    std::vector<int> vec{42, 420, 4242, 9999};
    std::vector<int>::const_iterator ret(::easyfind(vec, 4242));
    std::cout << *ret << std::endl;
    ret++;
    std::cout << *ret << std::endl;
    ret = ::easyfind(vec, 5757);
    if (ret == vec.end())
      std::cout << "it's equal with end of iterator" << std::endl;
    else
      std::cout << "something wrong" << std::endl;
  }
  return 0;
}
