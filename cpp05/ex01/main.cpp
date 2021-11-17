#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Form f("test", 0, 10);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Form f("test", 1, 151);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Form f("test", 10, 100);
    Bureaucrat b0("nop", 1);
    Bureaucrat b1("louis", 15);

    b1.signForm(f);
    b0.signForm(f);
    b0.signForm(f);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
