#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include <iostream>

class Animal {
protected:
  std::string _type;

public:
  Animal();
  virtual ~Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &rhs);
  virtual void makeSound() const = 0;
  const std::string &getType() const;
};

#endif  // ANIMAL_CPP