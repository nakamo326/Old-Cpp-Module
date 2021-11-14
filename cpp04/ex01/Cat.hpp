#ifndef CAT_CPP
#define CAT_CPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *_brain;

public:
  Cat();
  Cat(const Cat &other);
  ~Cat();
  Cat &operator=(const Cat &rhs);
  void makeSound() const;
};

#endif  // CAT_CPP