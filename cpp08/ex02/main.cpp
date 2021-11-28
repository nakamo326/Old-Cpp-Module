#include <algorithm>
#include <iostream>
#include <stack>

#include "Color.hpp"
#include "MutantStack.hpp"

void test_copy(MutantStack<int> ms) {
  std::cout << BLU "test copy constructor" NC << std::endl;
  MutantStack<int> mstack2;
  mstack2.push(333);
  std::cout << GRN "mstack2 (before copy): " NC;
  printMstack(mstack2);
  mstack2 = ms;
  std::cout << GRN "mstack: " NC;
  printMstack(ms);
  std::cout << GRN "mstack2 (after copy): " NC;
  printMstack(mstack2);
  std::cout << mstack2.top() << std::endl;
  std::cout << std::endl;
}

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

  test_copy(mstack);

  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  std::stack<int> st;
  st.push(4);
  st.push(42);
  st.push(99);

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  return 0;
}