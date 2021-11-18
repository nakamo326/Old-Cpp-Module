#ifndef CONVERT_HPP
#define CONVERT_HPP

class convert {
public:
  convert();
  convert(const convert &other);
  ~convert();
  convert &operator=(const convert &rhs);
  void private:
};

convert::convert() {}

convert::convert(const convert &other) { *this = other; }

convert::~convert() {}

convert &convert::operator=(const convert &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // CONVERT_HPP