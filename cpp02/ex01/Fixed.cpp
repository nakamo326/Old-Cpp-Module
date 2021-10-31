#include "Fixed.hpp"

Fixed::Fixed() {
  m_num = 0;
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
  std::cout << "Int constructor called" << std::endl;
  m_num = num << m_bp;
}

Fixed::Fixed(const float num) {
  std::cout << "Float constructor called" << std::endl;
  m_num = (int)roundf(num * (1 << m_bp));
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  m_num = other.getRawBits();
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Assignation operator called" << std::endl;
  if (this == &other)
    return *this;
  m_num = other.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return m_num;
}

void Fixed::setRawBits(int const raw) {
  m_num = raw;
}

float Fixed::toFloat(void) const {
  return (float)m_num / (1 << m_bp);
}

int Fixed::toInt(void) const {
  return m_num >> m_bp;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &f) {
  stream << f.toFloat();
  return stream;
}
