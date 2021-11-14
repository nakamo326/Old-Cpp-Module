#include "Animal.hpp"

Animal::Animal() : _type("None") {
  std::cout << "[Animal] Default constructor called." << std::endl;
}

Animal::Animal(const Animal &other) {
  *this = other;
  std::cout << "[Animal] Copy constructor called." << std::endl;
}

Animal::~Animal() {
  std::cout << "[Animal] Destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  std::cout << "[Animal] Assignation operator called" << std::endl;
  return *this;
}

void Animal::makeSound() const {
  std::cout << "[" << _type << "] "
            << "I'M ANIMAL CLASS" << std::endl;
};

const std::string &Animal::getType() const {
  return _type;
}
