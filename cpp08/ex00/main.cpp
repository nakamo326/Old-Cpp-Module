#include <array>
#include <vector>

#include "easyfind.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YLW "\e[0;33m"
#define BLU "\e[0;34m"

int main() {
  {
    std::cout << BLU "==test with arr{0, 1, 2, 3, 4}===" NC << std::endl;
    std::array<int, 5> arr{0, 1, 2, 3, 4};
    std::cout << YLW "==easyfind(arr, 4)===" NC << std::endl;
    std::array<int, 5>::const_iterator ret(::easyfind(arr, 4));
    std::cout << "ret: " << *ret << std::endl;
    std::cout << YLW "==easyfind(arr, 8) (no exist member)===" NC << std::endl;
    ret = ::easyfind(arr, 8);
    if (ret == arr.end())
      std::cout << "it's equal with end of iterator" << std::endl;
    else
      std::cout << "something wrong" << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << BLU "==test with vec{42, 420, 4242, 9999}===" NC << std::endl;
    std::vector<int> vec{42, 420, 4242, 9999};
    std::vector<int>::const_iterator ret(::easyfind(vec, 4242));
    std::cout << "ret: " << *ret << std::endl;
    ret++;
    std::cout << "ret++: " << *ret << std::endl;
    std::cout << YLW "==easyfind(arr, 5757) (no exist member)===" NC
              << std::endl;
    ret = ::easyfind(vec, 5757);
    if (ret == vec.end())
      std::cout << "it's equal with end of iterator" << std::endl;
    else
      std::cout << "something wrong" << std::endl;
  }
  return 0;
}
