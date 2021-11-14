#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
public:
  Brain();
  Brain(const Brain &other);
  ~Brain();
  Brain &operator=(const Brain &rhs);

private:
  std::string _ideas[100];
};

#endif  // BRAIN_HPP