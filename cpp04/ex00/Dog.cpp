#include "Dog.hpp"

Dog::Dog() {
  _type = std::string("Dog");
  std::cout << "[Dog] Default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) {
  *this = other;
  std::cout << "[Dog] Copy constructor called." << std::endl;
}

Dog::~Dog() {
  std::cout << "[Dog] Destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  std::cout << "[Dog] Assignation operator called" << std::endl;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "[" << _type << "] "
            << "BOWWOW!!" << std::endl;
}