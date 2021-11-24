#include <iostream>

#include "Bureaucrat.hpp"
#include "Color.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Intern bob;

  std::cout << BLU "=== Intern makes each concrete form as a form. ===" NC
            << std::endl;
  Form* sf = bob.makeForm("shrubbery creation", "home");
  Form* pf = bob.makeForm("presidential pardon", "home");
  Form* rf = bob.makeForm("robotomy request", "home");
  Form* nf = bob.makeForm("no_such_form", "home");
  (void)nf;

  std::cout << GRN << *sf << NC << std::endl;
  std::cout << GRN << *pf << NC << std::endl;
  std::cout << GRN << *rf << NC << std::endl << std::endl;

  std::cout << BLU "=== generate Bureaucrat nop and louis. ===" NC << std::endl;
  Bureaucrat b0("nop", 1);
  Bureaucrat b1("louis", 30);
  std::cout << std::endl;

  std::cout << BLU "=== try to execute not signed form. ===" NC << std::endl;
  try {
    sf->execute(b0);
  } catch (const Form::GradeTooHighException& e) {
    std::cerr << RED "High;sf->execute(b0): " << e.what() << NC << '\n';
  } catch (const Form::GradeTooLowException& e) {
    std::cerr << RED "Low;sf->execute(b0): " << e.what() << NC << '\n';
  } catch (const Form::FormNotSignedException& e) {
    std::cerr << RED "NotSigned;sf->execute(b0): " << e.what() << NC << '\n';
  }
  std::cout << std::endl;

  std::cout << BLU "=== louis tries to sign all form. ===" NC << std::endl;
  b1.signForm(*sf);
  std::cout << GRN << *sf << NC << std::endl;
  b1.signForm(*pf);
  std::cout << GRN << *pf << NC << std::endl;
  b1.signForm(*rf);
  std::cout << GRN << *rf << NC << std::endl << std::endl;

  std::cout << BLU "=== louis tries to execute all form. ===" NC << std::endl;
  b1.executeForm(*sf);
  b1.executeForm(*pf);
  b1.executeForm(*rf);
  std::cout << std::endl;

  std::cout << BLU
      "=== nop tries to sign and execute PresidentialPardonForm. ===" NC
            << std::endl;
  b0.executeForm(*pf);
  std::cout << GRN << *pf << NC << std::endl;
  b0.signForm(*pf);
  std::cout << GRN << *pf << NC << std::endl;
  b0.executeForm(*pf);
  std::cout << std::endl;

  delete sf;
  delete pf;
  delete rf;

  return 0;
}
