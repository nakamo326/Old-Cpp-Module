#include "Cat.hpp"

Cat::Cat() {
  _type = std::string("Cat");
  _brain = new Brain();
  std::cout << "[Cat] Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) {
  *this = other;
  std::cout << "[Cat] Copy constructor called." << std::endl;
}

Cat::~Cat() {
  delete _brain;
  std::cout << "[Cat] Destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  std::cout << "[Cat] Assignation operator called" << std::endl;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "[" << _type << "]  "
            << "Meow. Meoooooooooow." << std::endl;
}