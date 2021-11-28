#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <deque>
#include <iterator>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
private:
  typedef std::stack<T, Container> st;

public:
  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::reverse_iterator reverse_iterator;

  MutantStack() {}
  ~MutantStack() {}
  MutantStack(const MutantStack &other) : st(other) {}
  MutantStack &operator=(const MutantStack &rhs) {
    if (this == &rhs)
      return *this;
    st::c = rhs.st::c;
    return *this;
  }

  T &top() { return st::top(); }
  const T &top() const { return st::top(); }
  bool empty() const { return st::empty(); }
  typename st::size_type size() const { return st::size(); }
  void push(const T &value) { return st::push(value); }
  void push(T &value) { return st::push(value); }
  void pop() { return st::pop(); }
  iterator begin() { return st::c.begin(); }
  iterator end() { return st::c.end(); }
  reverse_iterator rbegin() { return st::c.rbegin(); }
  reverse_iterator rend() { return st::c.rend(); }
};

template <typename T>
void printMstack(MutantStack<T> &ms) {
  std::cout << "size: " << ms.size() << ": {";
  MutantStack<int>::iterator it(ms.begin());
  MutantStack<int>::iterator ite(ms.end());
  MutantStack<int>::iterator rit = --ms.end();
  for (; it != ms.end(); it++) {
    std::cout << *it;
    if (it != rit)
      std::cout << ", ";
  }
  std::cout << "}" << std::endl;
}

#endif  // MUTANTSTACK_HPP