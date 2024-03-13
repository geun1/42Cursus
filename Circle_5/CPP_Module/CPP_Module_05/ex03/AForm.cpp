#include "AForm.hpp"

AForm::AForm()
  : name("default form"), signCheck(false), signGrade(150), executeGrade(150) {
}

AForm::AForm(const std::string& name, const int& signGrade, const int& executeGrade)
  : name(name), signCheck(false), signGrade(signGrade), executeGrade(executeGrade) {
  if (this->signGrade < 1 || this->executeGrade < 1) throw AForm::GradeTooHighException();
  if (this->signGrade > 150 || this->executeGrade > 150) throw AForm::GradeTooLowException(); 
}

AForm::AForm(const AForm& ref)
  : name(ref.getName()), signCheck(ref.getBeSigned()), signGrade(ref.getSignGrade()), executeGrade(ref.getExecuteGrade()) {
}

AForm::~AForm() {
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "grade is too low!";
}

const char* AForm::NoSignException::what() const throw() {
  return "bureaucrat have not signed form. Check your form.";
}

const char* AForm::InvalidExecuteException::what() const throw() {
  return "bureaucrat could not execute form. Grade is too low.";
}

const std::string& AForm::getName() const {
  return this->name;
}

const bool& AForm::getBeSigned() const {
  return this->signCheck;
}

const int& AForm::getSignGrade() const {
  return this->signGrade;
}

const int& AForm::getExecuteGrade() const {
  return this->executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() <= this->getSignGrade()) {
      this->signCheck = true;
  } else {
      throw AForm::GradeTooHighException();
  }
}

void AForm::isExecutable(const Bureaucrat& bureaucrat) const {
	if (this->getBeSigned() == false) throw AForm::NoSignException();
	if (this->getExecuteGrade() < bureaucrat.getGrade()) throw AForm::InvalidExecuteException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
  return os << form.getName() 
		<< std::boolalpha <<", signed : " << form.getBeSigned()
		<< ", signGrade : " << form.getSignGrade()
		<< ", executeGrade : " << form.getExecuteGrade() << std::endl;
}
