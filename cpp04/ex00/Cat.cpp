#include "Cat.hpp"

Cat::Cat() {
  _type = std::string("Cat");
  std::cout << "[Cat] Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) {
  *this = other;
  std::cout << "[Cat] Copy constructor called." << std::endl;
}

Cat::~Cat() {
  std::cout << "[Cat] Destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
  std::cout << "[Cat] Assignation operator called" << std::endl;
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "[" << _type << "]  "
            << "Meow. Meoooooooooow." << std::endl;
}