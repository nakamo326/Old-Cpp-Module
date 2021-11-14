#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("None") {
  std::cout << "[wAnimal] Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  *this = other;
  std::cout << "[wAnimal] Copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "[wAnimal] Destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  std::cout << "[wAnimal] Assignation operator called" << std::endl;
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "[" << _type << "] "
            << "I'M WRONG ANIMAL CLASS" << std::endl;
};

const std::string &WrongAnimal::getType() const {
  return _type;
}