#include "Fixed.hpp"

Fixed::Fixed() {
  m_num = 0;
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num) {
  m_num = num << m_bp;
}

Fixed::Fixed(float num) {
  m_num = (int)roundf(num * (1 << m_bp));
}

Fixed::Fixed(const Fixed &other) {
  m_num = other.m_num;
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  m_num = other.m_num;
  std::cout << "Assignation operator called" << std::endl;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
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
