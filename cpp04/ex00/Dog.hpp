#ifndef DOG_CPP
#define DOG_CPP

class Dog {
  private:
  public:
  Dog();
  Dog(const Dog &other);
  ~Dog();
  Dog &operator=(const Dog &rhs);
  void makeSound();
};

#endif  // DOG_CPP