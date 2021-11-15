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
  delete _brain;
  _brain = new Brain(*rhs._brain);
  _type = rhs._type;
  std::cout << "[Cat] Assignation operator called" << std::endl;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "[" << _type << "]  "
            << "Meow. Meoooooooooow." << std::endl;
}

void Cat::showIdeas() const {
  std::cout << "[Cat] there are my ideas." << std::endl;
  _brain->showIdeas();
  std::cout << "[Cat] it's all ." << std::endl;
}
