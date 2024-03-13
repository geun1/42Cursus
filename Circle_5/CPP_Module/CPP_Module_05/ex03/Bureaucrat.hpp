#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
  private:
    const std::string name;
    int grade;
    Bureaucrat&	operator=(const Bureaucrat& copy);

  public:
    Bureaucrat();
    Bureaucrat(const std::string& name, const int& grade);
    Bureaucrat(const Bureaucrat& copy);
    ~Bureaucrat();
    const std::string& getName() const;
    const int& getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(AForm& form) const;
    void executeForm(const AForm& form) const;

    class GradeTooHighException : public std::exception {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif