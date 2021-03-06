#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  m_num = 0;
}

Fixed::Fixed(const Fixed &obj) {
  std::cout << "Copy constructor called" << std::endl;
  *this = obj;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  std::cout << "Assignation operator called" << std::endl;
  if (this != &rhs)
    m_num = rhs.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return m_num;
}

void Fixed::setRawBits(int const raw) {
  m_num = raw;
}