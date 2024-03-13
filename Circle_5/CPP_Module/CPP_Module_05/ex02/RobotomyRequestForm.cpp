#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
  : AForm("robotomy", 72, 45), _target("noTarget") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
  : AForm("robotomy", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
  : AForm(copy), _target(copy._target) {
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) {
  if (this != &ref) {
    this->_target = ref._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const {
  this->isExecutable(bureaucrat);
  std::cout << "Drilling~~ wing~~ wing~~" << std::endl;
  std::time_t currentTime = std::time(NULL);
  if (currentTime % 2 == 0) {
    std::cout << this->_target << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << this->_target << " has failed to robotomize." << std::endl;
  }
}