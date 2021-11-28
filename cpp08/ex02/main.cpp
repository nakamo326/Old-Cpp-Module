#include <algorithm>
#include <iostream>
#include <stack>

#include "Color.hpp"
#include "MutantStack.hpp"

void test_empty() {
  std::cout << BLU "test empty method." NC << std::endl;
  MutantStack<int> mstack;
  std::cout << GRN "mstack: " NC << mstack << std::endl;
  if (mstack.empty())
    std::cout << GRN "this mstack is empty!" NC << std::endl;
  else
    std::cout << RED "this mstack is not empty!!" NC << std::endl;
  mstack.push(0);
  std::cout << GRN "mstack: " NC << mstack << std::endl;
  if (mstack.empty())
    std::cout << GRN "this mstack is empty!" NC << std::endl;
  else
    std::cout << RED "this mstack is not empty!!" NC << std::endl;
  std::cout << std::endl;
}

void test_size() {
  std::cout << BLU "test size method." NC << std::endl;
  MutantStack<int> mstack;
  std::cout << YLW "mstack;" NC << std::endl;
  std::cout << "mstack size: " << mstack.size() << std::endl;
  std::cout << YLW "mstack.push(0);" NC << std::endl;
  mstack.push(0);
  std::cout << "mstack size: " << mstack.size() << std::endl;
  std::cout << YLW "mstack.push(1);" NC << std::endl;
  mstack.push(1);
  std::cout << "mstack size: " << mstack.size() << std::endl;
  std::cout << std::endl;
}

void test_assignation(MutantStack<int> ms) {
  std::cout << BLU "test assignation constructor" NC << std::endl;
  MutantStack<int> mstack2;
  mstack2.push(333);
  std::cout << GRN "mstack2 (before assignation): " NC << mstack2 << std::endl;
  std::cout << YLW "mstack2 = mstack;" NC << std::endl;
  mstack2 = ms;
  std::cout << GRN "mstack: " NC << ms << std::endl;
  std::cout << GRN "mstack2 (after assignation): " NC << mstack2 << std::endl;
  std::cout << std::endl;
}

void test_copy(MutantStack<int> ms) {
  std::cout << BLU "test copy constructor" NC << std::endl;
  std::cout << GRN "mstack: " NC << ms << std::endl;
  std::cout << YLW "mstack2(mstack);" NC << std::endl;
  MutantStack<int> mstack2(ms);
  std::cout << GRN "mstack2 (copy): " NC << mstack2 << std::endl;
  std::cout << YLW "mstack2.push(888);" NC << std::endl;
  mstack2.push(888);
  std::cout << GRN "mstack: " NC << ms << std::endl;
  std::cout << GRN "mstack2: " NC << mstack2 << std::endl;
  std::cout << std::endl;
}

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  mstack.push(3);
  mstack.push(737);

  test_empty();
  test_size();
  test_assignation(mstack);
  test_copy(mstack);

  // test_pop and top;
  // tset_iterator equal;
  // test_iterator not equal;
  // test_iterator compare;

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  return 0;
}