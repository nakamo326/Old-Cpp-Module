#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : Form("RobotomyRequestForm", 72, 45), _target("blank") {
  std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target)
    : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) {
  *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  checkExecutable(executor);
  std::cout << "chuin. chuin. chuiiiiiiiin!" << std::endl;
  int result = std::rand() % 2;
  if (result == 0)
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  else
    std::cout << "its a failure..." << std::endl;
}