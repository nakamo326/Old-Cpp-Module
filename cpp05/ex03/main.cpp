#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Intern bob;

  Form* sf = bob.makeForm("shrubbery creation", "home");
  Form* pf = bob.makeForm("presidential pardon", "home");
  Form* rf = bob.makeForm("robotomy request", "home");
  Form* null = bob.makeForm("no_such_form", "test_target");
  delete null;

  Bureaucrat b0("nop", 1);
  Bureaucrat b1("louis", 30);

  try {
    sf->execute(b0);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  b1.signForm(*dynamic_cast<ShrubberyCreationForm*>(sf));
  b1.signForm(*dynamic_cast<PresidentialPardonForm*>(pf));
  b1.signForm(*dynamic_cast<RobotomyRequestForm*>(rf));

  b1.executeForm(*dynamic_cast<ShrubberyCreationForm*>(sf));
  b1.executeForm(*dynamic_cast<PresidentialPardonForm*>(pf));
  b1.executeForm(*dynamic_cast<RobotomyRequestForm*>(rf));

  b0.executeForm(*dynamic_cast<PresidentialPardonForm*>(pf));
  b0.signForm(*dynamic_cast<PresidentialPardonForm*>(pf));
  b0.executeForm(*dynamic_cast<PresidentialPardonForm*>(pf));

  return 0;
}
