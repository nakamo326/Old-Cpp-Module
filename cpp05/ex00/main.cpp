#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat a("nop", 1);
    std::cout << a << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    Bureaucrat b("louis", 0);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    Bureaucrat c("bunjiro", 151);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    Bureaucrat a("nop", 1);
    a++;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
