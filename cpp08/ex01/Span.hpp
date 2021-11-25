#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

class Span {
public:
  Span();
  Span(unsigned int n);
  Span(const Span &other);
  ~Span();
  Span &operator=(const Span &rhs);
  void addNumber(int num);
  long shortestSpan();
  long longestSpan();
  void print();

  class SpanException : public std::logic_error {
  public:
    SpanException(const std::string &msg = "something wrong");
  };

private:
  unsigned int _currentSize;
  unsigned int _size;
  std::multiset<int> _ms;
};

#endif  // SPAN_HPP
