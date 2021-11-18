#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

  void execute(Bureaucrat const &executor) const;

private:
  std::string _target;
};

#endif  // SHRUBBERYCREATIONFORM_HPP

/*

"       _-_"
"    /~~   ~~\"
" /~~         ~~\"
"{               }"
" \  _-     -_  /"
"   ~  \\ //  ~"
"_- -   | | _- _"
"  _ -  | |   -_"
"      // \\"

*/