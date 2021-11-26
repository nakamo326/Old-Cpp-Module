#include <algorithm>
#include <iostream>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  std::cout << mstack.size() << std::endl;

  MutantStack<int> mstack2;
  mstack2.push(333);
  mstack2 = mstack;
  std::cout << mstack.size() << std::endl;
  std::cout << mstack2.size() << std::endl;
  std::cout << mstack2.top() << std::endl;
  std::cout << std::endl;

  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  // ++it;
  // --it;
  // while (it != ite) {
  //   std::cout << *it << std::endl;
  //   ++it;
  // }
  // std::stack<int> s(mstack);
  return 0;
}