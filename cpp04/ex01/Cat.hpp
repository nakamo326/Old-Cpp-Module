#ifndef CAT_CPP
#define CAT_CPP

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
  private:
  public:
  Cat();
  Cat(const Cat &other);
  ~Cat();
  Cat &operator=(const Cat &rhs);
  void makeSound() const;
};

#endif  // CAT_CPP