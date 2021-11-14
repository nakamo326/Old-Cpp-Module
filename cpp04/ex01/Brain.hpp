#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain {
public:
  Brain();
  Brain(const Brain &other);
  ~Brain();
  Brain &operator=(const Brain &rhs);
  void showIdeas() const;

private:
  std::string _ideas[100];
  static int _index;
};

#endif  // BRAIN_HPP