#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

  void execute(Bureaucrat const &executor) const;

private:
  std::string _target;
};

#endif  // ROBOTOMYREQUESTFORM_HPP