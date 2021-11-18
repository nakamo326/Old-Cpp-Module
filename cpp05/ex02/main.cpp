#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Form* sf = new ShrubberyCreationForm("home");
  Form* pf = new PresidentialPardonForm("john");
  Form* rf = new RobotomyRequestForm("bob");

  Bureaucrat b0("nop", 1);
  Bureaucrat b1("louis", 30);

  try {
    sf->execute(b0);
  } catch (const Form::GradeTooHighException& e) {
    std::cerr << "High;sf->execute(b0): " << e.what() << '\n';
  } catch (const Form::GradeTooLowException& e) {
    std::cerr << "Low;sf->execute(b0): " << e.what() << '\n';
  } catch (const Form::FormNotSignedException& e) {
    std::cerr << "NotSigned;sf->execute(b0): " << e.what() << '\n';
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
