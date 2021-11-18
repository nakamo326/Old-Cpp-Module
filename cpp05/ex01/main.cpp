#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Form f("test", 0, 10);
  } catch (const Form::GradeTooHighException& e) {
    std::cerr << "High;(\"test\", 0, 10): " << e.what() << '\n';
  } catch (const Form::GradeTooLowException& e) {
    std::cerr << "Low;(\"test\", 0, 10): " << e.what() << '\n';
  }
  try {
    Form f("test", 1, 151);
  } catch (const Form::GradeTooHighException& e) {
    std::cerr << "High;(\"test\", 1, 151): " << e.what() << '\n';
  } catch (const Form::GradeTooLowException& e) {
    std::cerr << "Low;(\"test\", 1, 151): " << e.what() << '\n';
  }
  Form f("test", 10, 100);
  Bureaucrat b0("nop", 1);
  Bureaucrat b1("louis", 15);

  b1.signForm(f);
  b0.signForm(f);
  b0.signForm(f);

  return 0;
}
