#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal* base = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();
  std::cout << base->getType() << std::endl;
  std::cout << dog->getType() << std::endl;
  std::cout << cat->getType() << std::endl;
  base->makeSound();
  dog->makeSound();
  cat->makeSound();
  return 0;
}