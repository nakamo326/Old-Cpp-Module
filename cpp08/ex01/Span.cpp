#include "Span.hpp"

Span::Span() : _currentSize(0), _size(0) {}

Span::Span(unsigned int n) : _currentSize(0), _size(n) {}

Span::Span(const Span &other)
    : _currentSize(other._currentSize), _size(other._size), _ms(other._ms) {}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
  if (this == &rhs)
    return *this;
  _currentSize = rhs._currentSize;
  _size = rhs._size;
  _ms = rhs._ms;
  return *this;
}

void Span::addNumber(int num) {
  if (_currentSize == _size) {
    throw SpanException("Elements is full.");
  }
  _ms.insert(num);
  _currentSize++;
}

void Span::print() {
  for (std::multiset<int>::const_iterator it(_ms.begin()); it != _ms.end();
       it++) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;
}

long Span::shortestSpan() {
  if (_currentSize < 2)
    throw SpanException("Elements are less to get span.");
  std::vector<int> result(_ms.size());
  std::adjacent_difference(_ms.begin(), _ms.end(), result.begin());
  result.erase(result.begin());
  long ret = *(std::min_element(result.begin(), result.end()));

  return ret;
}

long Span::longestSpan() {
  if (_currentSize < 2)
    throw SpanException("Elements are less to get span.");
  long ret = *(--_ms.end()) - *(_ms.begin());
  return ret;
}

Span::SpanException::SpanException(const std::string &msg) : logic_error(msg){};
