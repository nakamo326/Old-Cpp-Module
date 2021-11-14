#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  {
    const Animal* base = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << base->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    base->makeSound();
    dog->makeSound();
    cat->makeSound();
    delete base;
    delete dog;
    delete cat;
  }
  {
    std::cout << "===WrongAnimal===" << std::endl;
    const WrongAnimal* wbase = new WrongAnimal();
    const WrongAnimal* wcat = new WrongCat();
    std::cout << wbase->getType() << std::endl;
    std::cout << wcat->getType() << std::endl;
    wbase->makeSound();
    wcat->makeSound();
    delete wbase;
    delete wcat;
  }
  return 0;
}