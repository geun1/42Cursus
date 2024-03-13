#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_treeOfAscii = "   *\n  ***\n *****\n*******\n   |\n";

ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm("shrubbery", 145, 137), _target("noTarget") {
  
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
  : AForm("shrubbery", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
  : AForm(copy), _target(copy._target) {
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
  if (this != &ref) {
    this->_target = ref._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {
  this->isExecutable(bureaucrat);
  std::ofstream writeFile((_target + "_shrubbery").c_str(), std::ios::out | std::ios::app);
  if (writeFile.is_open())
  {
    writeFile << this->_treeOfAscii;
    writeFile.close();
  }
}