#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
  Form();
  Form(const std::string &name, unsigned int gradeToSign,
       unsigned int gradeToExecute);
  Form(const Form &other);
  virtual ~Form();
  Form &operator=(const Form &rhs);
  void beSigned(const Bureaucrat &b);
  bool getIsSigned() const;
  const std::string &getName() const;
  unsigned int getGradeToSign() const;
  unsigned int getGradeToExecute() const;

  // add for ex02
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::range_error {
  public:
    GradeTooHighException(const std::string &msg = "grade is too high");
  };

  class GradeTooLowException : public std::range_error {
  public:
    GradeTooLowException(const std::string &msg = "grade is too low");
  };

  class FormNotSignedException : public std::logic_error {
  public:
    FormNotSignedException(const std::string &msg = "This form is not signed!");
  };

protected:
  void checkExecutable(Bureaucrat const &executor) const;

private:
  bool _isSigned;
  const std::string _name;
  const unsigned int _gradeToSign;
  const unsigned int _gradeToExecute;
  static const unsigned int _highestGrade = 1;
  static const unsigned int _lowestGrade = 150;
};

std::ostream &operator<<(std::ostream &stream, const Form &f);

#endif  // FORM_HPP