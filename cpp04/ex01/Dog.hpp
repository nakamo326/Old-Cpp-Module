#ifndef DOG_CPP
#define DOG_CPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *_brain;

public:
  Dog();
  Dog(const Dog &other);
  ~Dog();
  Dog &operator=(const Dog &rhs);
  void makeSound() const;
};

#endif  // DOG_CPP