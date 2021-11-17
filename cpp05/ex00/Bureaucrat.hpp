#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
  Bureaucrat(const std::string &name, unsigned int grade);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &rhs);
  Bureaucrat operator++(int);
  Bureaucrat operator--(int);
  const std::string &getName() const;
  unsigned int getGrade() const;

  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };

private:
  static const unsigned int _highestGrade = 1;
  static const unsigned int _lowestGrade = 150;
  const std::string _name;
  unsigned int _grade;

  Bureaucrat();
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &b);

#endif  // BUREAUCRAT_HPP