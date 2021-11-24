#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <set>

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
  // use abs?

private:
  unsigned int _maxElm;
  std::multiset<int> _ms;
};

Span::Span() {}

Span::Span(const Span &other) { *this = other; }

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // SPAN_HPP