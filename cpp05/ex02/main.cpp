#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    Form* sf = new ShrubberyCreationForm("home");
    Form* pf = new PresidentialPardonForm("john");
    Form* rf = new RobotomyRequestForm("bob");
    ShrubberyCreationForm sf("home");

    Bureaucrat b0("nop", 1);
    Bureaucrat b1("louis", 15);

    b1.signForm(*dynamic_cast<ShrubberyCreationForm*>(sf));

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
