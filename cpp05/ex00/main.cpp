#include <iostream>

#include "Bureaucrat.hpp"
#include "Color.hpp"

void test(size_t grade) {
  try {
    Bureaucrat b("test", grade);
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << RED << grade << ": " << e.what() << "." NC << '\n';
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << RED << grade << ": " << e.what() << "." NC << '\n';
  }
}

int main() {
  std::cout << BLU "=== generate Bureaucrat with grade 0 to 155. ===" NC
            << std::endl;
  for (size_t i = 0; i < 155; i++) {
    test(i);
  }

  std::cout << std::endl;
  try {
    std::cout << BLU "=== generate B~ grade 3 and increment to 0 ===" NC
              << std::endl;
    Bureaucrat b("test", 3);
    std::cout << GRN << b << NC << std::endl;
    b.incrementGrade();
    std::cout << GRN << b << NC << std::endl;
    b.incrementGrade();
    std::cout << GRN << b << NC << std::endl;
    b.incrementGrade();
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << RED << "High;inc to 0: " << e.what() << NC << '\n';
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << RED << "Low;inc to 0: " << e.what() << NC << '\n';
  }
  std::cout << std::endl;
  try {
    std::cout << BLU "=== generate B~ grade 148 and decrement to 151 ===" NC
              << std::endl;
    Bureaucrat b("test", 148);
    std::cout << GRN << b << NC << std::endl;
    b.decrementGrade();
    std::cout << GRN << b << NC << std::endl;
    b.decrementGrade();
    std::cout << GRN << b << NC << std::endl;
    b.decrementGrade();
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << RED << "High;dec to 151: " << e.what() << NC << '\n';
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << RED << "Low;dec to 151: " << e.what() << NC << '\n';
  }
  std::cout << std::endl;
  return 0;
}
