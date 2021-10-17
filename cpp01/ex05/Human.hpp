#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>

#include "Brain.hpp"

class Human {
  private:
  Brain m_brain;

  public:
  Human(/* args */);
  ~Human();
  Brain& getBrain();
  std::string identify();
};

#endif