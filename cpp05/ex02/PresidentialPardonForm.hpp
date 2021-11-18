#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "Form.hpp"

class PresidentialPardonForm : Form {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  void execute(Bureaucrat const &executor) const;

private:
  std::string _target;
};

#endif  // PRESIDENTIALPARDONFORM_HPP