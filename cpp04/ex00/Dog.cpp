#include "Dog.hpp"

Dog::Dog() {
  _type = std::string("Dog");
}

Dog::Dog(const Dog &other) {
  *this = other;
}

Dog::~Dog() {
}

Dog &Dog::operator=(const Dog &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "[" << _type << "] "
            << "BOWWOW!!" << std::endl;
}