#include "Dog.hpp"

Dog::Dog() {
  _type = std::string("Dog");
  _brain = new Brain();
}

Dog::Dog(const Dog &other) {
  *this = other;
}

Dog::~Dog() {
  delete _brain;
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