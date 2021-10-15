#ifndef PONY_HPP
#define PONY_HPP

#include "Pony.hpp"

Pony::Pony(std::string name) {
  m_name = name;
  std::cout << m_name << " is born!" << std::endl;
}

Pony::~Pony() {
  std::cout << m_name << " is dead...;(" << std::endl;
}

void Pony::cry() {
  std::cout << m_name << " is whinnying!" << std::endl;
};
void Pony::run() {
  std::cout << m_name << " is running! clip-clop." << std::endl;
};

#endif