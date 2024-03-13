#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "Bureaucrat.hpp"



class Form {
  private:
    const std::string name;
    bool signCheck;
    const int signGrade;
    const int executeGrade;
    Form&	operator=(const Form& ref);
    Form();

  public:
    
    Form(const std::string& name, const int& signGrade, const int& executeGrade);
    Form(const Form& copy);
    ~Form();

    class GradeTooHighException : public std::exception {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char* what() const throw();
    };

    const std::string& getName() const;
    const bool& getSignCheck() const;
    const int& getSignGrade() const;
    const int& getExecuteGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
