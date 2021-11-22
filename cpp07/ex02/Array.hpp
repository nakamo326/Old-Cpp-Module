#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <class Elm>
class Array {
private:
  Elm *_data;
  size_t _size;

public:
  Array();
  Array(size_t n) {
    _data = new Elm[n]();
    _size = n;
  }

  Array(const Array &other) {
    _data = new Elm[other._size]();
    _size = other._size;
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
    if (index >= _size || index < 0) {
      throw ArrayIndexOutOfRange();
    }
    return _data[index];
  }

  Elm &operator[](size_t index) {
    if (index >= _size || index < 0) {
      throw ArrayIndexOutOfRange();
    }
    return _data[index];
  }

  size_t size() const { return _size; }

  class ArrayIndexOutOfRange : public std::out_of_range {
  public:
    ArrayIndexOutOfRange(const std::string &msg = "Access to out of range!")
        : out_of_range(msg){};
  };
};

#endif  // ARRAY_HPP
