#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

class Convert {
public:
  Convert();
  Convert(std::string literal);
  Convert(const Convert &other);
  ~Convert();
  Convert &operator=(const Convert &rhs);

private:
  std::string _literal;
  bool _surfix;
  bool _dot;
};

Convert::Convert() {}

Convert::Convert(std::string literal)
    : _literal(literal), _surfix(false), _dot(false) {}

Convert::Convert(const Convert &other) { *this = other; }

Convert::~Convert() {}

Convert &Convert::operator=(const Convert &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // CONVERT_HPP