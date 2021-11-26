#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <deque>
#include <iterator>
#include <stack>

template <typename M>
class MutantStackIterator {
private:
  M &_ms;
  size_t _i;

public:
  MutantStackIterator(M &ms, size_t i) : _ms(ms), _i(i) {}
  ~MutantStackIterator() {}
  // M &operator*() { return ; }
};

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
private:
  typedef std::stack<T, Container> st;

public:
  typedef MutantStackIterator<MutantStack> iterator;

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
  iterator begin() { return iterator(*this, 0); }
  iterator end() { return iterator(*this, size()); }
};

#endif  // MUTANTSTACK_HPP