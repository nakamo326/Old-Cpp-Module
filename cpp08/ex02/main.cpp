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

void test_poptoppush() {
  std::cout << BLU "test pop, push, top" NC << std::endl;
  MutantStack<int> mstack;
  std::cout << GRN "mstack: " NC << mstack << std::endl;
  std::cout << YLW "mstack.push(5);" NC << std::endl;
  mstack.push(5);
  std::cout << GRN "mstack: " NC << mstack << std::endl;
  std::cout << YLW "mstack.top(): " NC << mstack.top() << std::endl;
  std::cout << YLW "mstack.pop();" NC << std::endl;
  mstack.pop();
  std::cout << GRN "mstack: " NC << mstack << std::endl;
  std::cout << YLW "mstack.push(9); mstack.push(42);" NC << std::endl;
  mstack.push(9);
  mstack.push(42);
  std::cout << GRN "mstack: " NC << mstack << std::endl;
  std::cout << YLW "mstack.top(): " NC << mstack.top() << std::endl;
  std::cout << std::endl;
}

void tset_iterator(MutantStack<int> mstack) {
  std::cout << BLU "test iterator equal" NC << std::endl;
  std::cout << GRN "mstack: " NC << mstack << std::endl;
  std::cout << YLW "decalared two iterator it and it2" << std::endl;
  MutantStack<int>::iterator it(mstack.begin());
  MutantStack<int>::iterator it2(mstack.begin());
  std::cout << GRN "(it == it2): " NC << (it == it2)
            << "; " GRN "(it != it2): " NC << (it != it2) << std::endl;
  std::cout << GRN "*it: " NC << *it << std::endl;
  std::cout << YLW "it++;" NC << std::endl;
  it++;
  std::cout << GRN "*it: " NC << *it << std::endl;
  std::cout << YLW "it--;" NC << std::endl;
  it--;
  std::cout << GRN "*it: " NC << *it << std::endl;
  std::cout << YLW "it++;" NC << std::endl;
  it++;
  std::cout << GRN "(it == it2): " NC << (it == it2)
            << "; " GRN "(it != it2): " NC << (it != it2) << std::endl;
  std::cout << YLW "it++; ++it;" NC << std::endl;
  it++;
  ++it;
  std::cout << GRN "*it: " NC << *it << std::endl;
  std::cout << YLW "it++;" NC << std::endl;
  it++;
  std::cout << GRN "(it == mstack.end()): " NC << (it == mstack.end())
            << "; " GRN "(it != mstack.end()): " NC << (it != mstack.end())
            << std::endl
            << std::endl;
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

  test_poptoppush();
  tset_iterator(mstack);
  // test_reverse_iterator(mstack);
  // test_stdstackfrommstack;

  // MutantStack<int>::iterator it = mstack.begin();
  // MutantStack<int>::iterator ite = mstack.end();

  // ++it;
  // --it;
  // while (it != ite) {
  //   std::cout << *it << std::endl;
  //   ++it;
  // }
  // std::stack<int> s(mstack);
  // std::cout << "stack s(mstack)" << std::endl;
  // std::cout << s.top() << std::endl;
  // s.pop();
  // std::cout << s.top() << std::endl;
  // s.pop();
  // std::cout << s.top() << std::endl;
  // s.pop();
  // std::cout << s.top() << std::endl;
  return 0;
}