#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <class Elm>
class Array {
private:
  Elm *_data;
  size_t _size;

public:
  Array() : _data(NULL), _size(0) {}
  Array(size_t n) : _data(new Elm[n]()), _size(n) {}

  Array(const Array &other)
      : _data(new Elm[other._size]()), _size(other._size) {
    for (size_t i = 0; i < _size; i++) {
      _data[i] = other._data[i];
    }
  }

  ~Array() { delete[] _data; }

  Array &operator=(const Array &rhs) {
    if (this == &rhs)
      return *this;
    delete[] _data;
    _data = new Elm[rhs._size]();
    _size = rhs._size;
    for (size_t i = 0; i < _size; i++) {
      _data[i] = rhs._data[i];
    }
    return *this;
  }

  const Elm &operator[](size_t index) const {
    if (index >= _size || index < 0 || _size == 0)
      throw std::out_of_range("Access to out of range!");
    return _data[index];
  }

  Elm &operator[](size_t index) {
    if (index >= _size || index < 0 || _size == 0)
      throw std::out_of_range("Access to out of range!");
    return _data[index];
  }

  size_t size() const { return _size; }
};

template <typename T>
std::ostream &operator<<(std::ostream &s, Array<T> arr) {
  s << "{ ";
  for (size_t i = 0; i < arr.size(); i++) {
    s << arr[i];
    if (i != arr.size() - 1)
      s << ", ";
  }
  s << " }";
  return s;
};

#endif  // ARRAY_HPP
