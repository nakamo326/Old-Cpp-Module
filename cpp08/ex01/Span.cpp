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

void Span::print() {}

unsigned int Span::shortestSpan() {
  if (_currentSize < 2)
    throw SpanException("Elements are less to get span.");
  std::vector<int> result(_ms.size());
  std::adjacent_difference(_ms.begin(), _ms.end(), result.begin());
  result.erase(result.begin());
  unsigned int ret = *(std::min_element(result.begin(), result.end()));
  return ret;
}

unsigned int Span::longestSpan() {
  if (_currentSize < 2)
    throw SpanException("Elements are less to get span.");
  unsigned int ret = *(_ms.rbegin()) - *(_ms.begin());
  return ret;
}

// add number iterator

// getter
unsigned int Span::getCurrentSize() const { return _currentSize; }
unsigned int Span::getSize() const { return _size; }
std::multiset<int> Span::getContainer() const { return _ms; }

Span::SpanException::SpanException(const std::string &msg) : logic_error(msg) {}

std::ostream &operator<<(std::ostream &stream, const Span &span) {
  stream << "CurrentSize: " << span.getCurrentSize()
         << ", Size: " << span.getSize() << std::endl
         << "{";
  std::multiset<int> ms = span.getContainer();
  std::multiset<int>::const_iterator it(ms.begin());
  unsigned int size = span.getCurrentSize();
  for (unsigned int i = 0; i < size; i++) {
    stream << *it++;
    if (i < size - 1)
      stream << ", ";
  }
  stream << "}";
  return stream;
}
