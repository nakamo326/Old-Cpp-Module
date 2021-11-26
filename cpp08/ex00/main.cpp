#include <set>
#include <vector>

#include "easyfind.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YLW "\e[0;33m"
#define BLU "\e[0;34m"

int main() {
  {
    std::cout << BLU "==test with vec{42, 420, 4242, 9999}===" NC << std::endl;
    std::vector<int> vec;
    vec.push_back(42);
    vec.push_back(420);
    vec.push_back(4242);
    vec.push_back(9999);
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
  std::cout << std::endl;
  {
    std::cout << BLU "==test with arr{0, 1, 2, 3, 4}===" NC << std::endl;
    std::set<int> set;
    set.insert(0);
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    std::cout << YLW "==easyfind(arr, 4)===" NC << std::endl;
    std::set<int>::const_iterator ret(::easyfind(set, 4));
    std::cout << "ret: " << *ret << std::endl;
    std::cout << YLW "==easyfind(arr, 8) (no exist member)===" NC << std::endl;
    ret = ::easyfind(set, 8);
    if (ret == set.end())
      std::cout << "it's equal with end of iterator" << std::endl;
    else
      std::cout << "something wrong" << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
