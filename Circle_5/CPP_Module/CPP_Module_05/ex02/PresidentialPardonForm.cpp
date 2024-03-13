#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
  : AForm("presidential", 25, 5), _target("noTarget") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
  : AForm("presidential", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
  : AForm(ref), _target(ref._target) {
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) {
  if (this != &ref) {
    this->_target = ref._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
  this->isExecutable(bureaucrat);
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}