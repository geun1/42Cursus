#include "Form.hpp"

Form::Form()
  : name("default form"), signCheck(false), signGrade(150), executeGrade(150) {
}

Form::Form(const std::string& name, const int& signGrade, const int& executeGrade)
  : name(name), signCheck(false), signGrade(signGrade), executeGrade(executeGrade) {
  if (this->signGrade < 1 || this->executeGrade < 1) throw Form::GradeTooHighException();
  if (this->signGrade > 150 || this->executeGrade > 150) throw Form::GradeTooLowException(); 
}

Form::Form(const Form& copy)
  : name(copy.getName()), signCheck(copy.getSignCheck()), signGrade(copy.getSignGrade()), executeGrade(copy.getExecuteGrade()) {
}

Form::~Form() {
}

const char* Form::GradeTooHighException::what() const throw() {
  return "grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "grade is too low!";
}

const std::string& Form::getName() const {
  return this->name;
}

const bool& Form::getSignCheck() const {
  return this->signCheck;
}

const int& Form::getSignGrade() const {
  return this->signGrade;
}

const int& Form::getExecuteGrade() const {
  return this->executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() <= this->getSignGrade()) {
    this->signCheck = true;
  } else {
    throw Form::GradeTooHighException();
  }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  return os << form.getName() 
		<< ", signed : "<< std::boolalpha  << form.getSignCheck()
		<< ", signGrade : " << form.getSignGrade()
		<< ", executeGrade : " << form.getExecuteGrade();
}
