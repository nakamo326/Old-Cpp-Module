#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <deque>
#include <iterator>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
private:
  typedef std::stack<T, Container> ms;

public:
  // need more implement
  MutantStack() {}
  ~MutantStack() {}
  MutantStack(const MutantStack &other) : ms(other) {}
  MutantStack &operator=(const MutantStack &rhs) {
    if (*this == &rhs)
      return *this;
    ms::c = rhs.ms::c;
    return *this;
  }

  T &top() { return ms::top(); }
  const T &top() const { return ms::top(); }
  bool empty() const { return ms::empty(); }
  typename ms::size_type size() const { return ms::size(); }
  void push(const T &value) { return ms::push(value); }
  void push(T &value) { return ms::push(value); }
  void pop() { return ms::pop(); }
};

#endif  // MUTANTSTACK_HPP