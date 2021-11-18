#include <iostream>

#include "Bureaucrat.hpp"

void test(size_t grade) {
  try {
    Bureaucrat b("test", grade);
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << grade << ": " << e.what() << '\n';
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << grade << ": " << e.what() << '\n';
  }
}

int main() {
  for (size_t i = 0; i < 155; i++) {
    test(i);
  }

  try {
    Bureaucrat b("test", 1);
    b.incrementGrade();
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "High;inc to 0: " << e.what() << '\n';
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Low;inc to 0: " << e.what() << '\n';
  }

  try {
    Bureaucrat b("test", 150);
    b.decrementGrade();
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "High;dec to 151: " << e.what() << '\n';
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Low;dec to 151: " << e.what() << '\n';
  }

  return 0;
}
