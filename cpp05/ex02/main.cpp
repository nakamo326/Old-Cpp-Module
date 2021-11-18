#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    Form* f = new ShrubberyCreationForm("home");
    PresidentialPardonForm pf("john");
    // Form RobotomyRequestForm rf("bob");
    ShrubberyCreationForm sf("home");

    Bureaucrat b0("nop", 1);
    Bureaucrat b1("louis", 15);

    b1.signForm(*dynamic_cast<ShrubberyCreationForm*>(f));
    f->execute(b0);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
