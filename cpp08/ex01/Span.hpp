#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cmath>
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
  unsigned int shortestSpan();
  unsigned int longestSpan();
  unsigned int getCurrentSize() const;
  unsigned int getSize() const;
  std::multiset<int> getContainer() const;

  template <typename Iterator>
  void addIterator(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
      if (_currentSize == _size) {
        throw SpanException("Elements is full.");
      }
      _ms.insert(*it);
      _currentSize++;
    }
  }

  class SpanException : public std::logic_error {
  public:
    SpanException(const std::string &msg = "something wrong");
  };

private:
  unsigned int _currentSize;
  unsigned int _size;
  std::multiset<int> _ms;
};

std::ostream &operator<<(std::ostream &stream, const Span &span);

#endif  // SPAN_HPP
