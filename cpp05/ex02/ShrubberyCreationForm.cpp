#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("ShrubberyCreationForm", 145, 137), _target("blank") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target)
    : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &other) {
  *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  checkExecutable(executor);
  std::string filepath(_target + "_shrubbery");
  std::ofstream ofs(filepath.c_str());
  if (!ofs) {
    std::cout << "its should be exception but temporary msg" << std::endl;
    return;
  }

  ofs << "       _-_\n";
  ofs << "    /~~   ~~\\\n";
  ofs << " /~~         ~~\\\n";
  ofs << "{               }\n";
  ofs << " \\  _-     -_  /\n";
  ofs << "   ~  \\\\ //  ~\n";
  ofs << "_- -   | | _- _\n";
  ofs << "  _ -  | |   -_\n";
  ofs << "      // \\\\\n";

  std::cout << "Shruberry was created!" << std::endl;
}