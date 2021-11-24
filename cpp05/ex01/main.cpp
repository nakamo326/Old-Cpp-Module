#include <iostream>

#include "Bureaucrat.hpp"
#include "Color.hpp"
#include "Form.hpp"

int main() {
  std::cout << BLU "=== generate Form with invalid grade. ===" NC << std::endl;
  try {
    Form f("test", 0, 10);
  } catch (const Form::GradeTooHighException& e) {
    std::cerr << RED << "High;(\"test\", 0, 10): " << e.what() << "." NC
              << '\n';
  } catch (const Form::GradeTooLowException& e) {
    std::cerr << RED << "Low;(\"test\", 0, 10): " << e.what() << "." NC << '\n';
  }
  try {
    Form f("test", 1, 151);
  } catch (const Form::GradeTooHighException& e) {
    std::cerr << RED << "High;(\"test\", 1, 151): " << e.what() << "." NC
              << '\n';
  } catch (const Form::GradeTooLowException& e) {
    std::cerr << RED << "Low;(\"test\", 1, 151): " << e.what() << "." NC
              << '\n';
  }
  std::cout << std::endl;
  std::cout << BLU
      "=== generate Form (\"test\", 10, 100) and Bureaucrat nop and louis. "
      "===" NC
            << std::endl;
  Form f("test", 10, 100);
  std::cout << f << std::endl;
  Bureaucrat b0("nop", 1);
  Bureaucrat b1("louis", 15);

  std::cout << std::endl;
  std::cout << BLU
      "=== louis tries to sign form(but his grade isn't enough to sign). ===" NC
            << std::endl;
  b1.signForm(f);
  std::cout << f << std::endl << std::endl;
  std::cout << BLU
      "=== nop tries to sign form(his grade is enough to sign). ===" NC
            << std::endl;
  b0.signForm(f);
  std::cout << f << std::endl << std::endl;

  std::cout << BLU "=== nop tries to sign form again. ===" NC << std::endl;
  b0.signForm(f);

  return 0;
}
