#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
  : name("Bureaucrat"), grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
  : name(name), grade(grade) {
  if (this->grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (this->grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
  : name(copy.getName()), grade(copy.getGrade()) {
  if (this->grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (this->grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
}

Bureaucrat::~Bureaucrat() {
}

const std::string& Bureaucrat::getName() const {
  return this->name;
}

const int& Bureaucrat::getGrade() const {
  return this->grade;
}

void Bureaucrat::incrementGrade() {
  if(this->grade < 2) {
    throw Bureaucrat::GradeTooHighException();
   } else {
    --this->grade;
   }
}

void Bureaucrat::decrementGrade() {
  if(this->grade > 149) {
    throw Bureaucrat::GradeTooLowException();
    } else {
      ++this->grade;
    }
}

void Bureaucrat::signForm(AForm& form) const {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn't sign " << 
      form.getName() << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm& form) const {
  try {
    form.execute(*this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn't execute " <<
      form.getName() << " because " << e.what() << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
}