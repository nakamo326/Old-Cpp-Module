#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const std::string &name, unsigned int grade);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &rhs);
  void incrementGrade();
  void decrementGrade();
  const std::string &getName() const;
  unsigned int getGrade() const;

  class GradeTooHighException : public std::range_error {
  public:
    GradeTooHighException(const std::string &msg = "grade is too high");
  };

  class GradeTooLowException : public std::range_error {
  public:
    GradeTooLowException(const std::string &msg = "grade is too low");
  };

private:
  static const unsigned int _highestGrade = 1;
  static const unsigned int _lowestGrade = 150;
  const std::string _name;
  unsigned int _grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &b);

#endif  // BUREAUCRAT_HPP