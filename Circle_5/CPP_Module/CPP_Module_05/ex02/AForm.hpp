#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  private:
    const std::string name;
    bool signCheck;
    const int signGrade;
    const int executeGrade;
    AForm&	operator=(const AForm& ref);
    AForm();

  public:
    AForm(const std::string& name, const int& signGrade, const int& executeGrade);
    AForm(const AForm& ref);
    virtual ~AForm();

    class GradeTooHighException : public std::exception {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char* what() const throw();
    };
    class NoSignException : public std::exception {
      public:
        const char* what() const throw();
    };
    class InvalidExecuteException : public std::exception {
      public:
        const char* what() const throw();
    };

    const std::string& getName() const;
    const bool& getBeSigned() const;
    const int& getSignGrade() const;
    const int& getExecuteGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void isExecutable(const Bureaucrat& Bureaucrat) const;
    virtual void execute(const Bureaucrat& bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
