#include "Dog.hpp"

Dog::Dog() {
  _type = std::string("Dog");
  _brain = new Brain();
  std::cout << "[Dog] Default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) {
  *this = other;
  std::cout << "[Dog] Copy constructor called." << std::endl;
}

Dog::~Dog() {
  delete _brain;
  std::cout << "[Dog] Destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  // if (_brain)
  //  delete _brain;
  _brain = new Brain(*(rhs._brain));
  std::cout << "[Dog] Assignation operator called." << std::endl;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "[" << _type << "] "
            << "BOWWOW!!" << std::endl;
}

void Dog::showIdeas() const {
  std::cout << "[Dog] there are my ideas." << std::endl;
  _brain->showIdeas();
  std::cout << "[Dog] it's all." << std::endl;
}
