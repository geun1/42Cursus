#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {
}

Intern::Intern(const Intern& copy) {
  (*this) = copy;
}

Intern&	Intern::operator=(const Intern& ref) {
  if (this != &ref)
    (*this) = ref;
  return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(std::string name, std::string target) {
  std::string findName("[" + name + "]");
  std::string findForm("[shrubbery creation][robotomy request][presidential pardon]");
  size_t pos = findName.find("][");
  
  if (pos != std::string::npos) {
    std::cout << name << " is not exist. Check your parameter." << std::endl;
    return NULL;
  }
  
  AForm* createFormByIntern = NULL;
  switch (findForm.find(findName)) {
    case 0:
      createFormByIntern = new ShrubberyCreationForm(target);
      break;
    case 20:
      createFormByIntern = new RobotomyRequestForm(target);
      break;
    case 38:
      createFormByIntern = new PresidentialPardonForm(target);
      break;
    default:
      std::cout << name << " is not exist. Check your parameter." << std::endl;
      return createFormByIntern;
  }
  std::cout << "Intern creates " << (*createFormByIntern);
  return createFormByIntern;
}
