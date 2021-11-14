#include "WrongCat.hpp"

WrongCat::WrongCat() {
  _type = std::string("WrongCat");
  std::cout << "[wCat] Default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
  *this = other;
  std::cout << "[wCat] Copy constructor called." << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "[wCat] Destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  std::cout << "[wCat] Assignation operator called" << std::endl;
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "[" << _type << "]  "
            << "Meow. Meoooooooooow." << std::endl;
}